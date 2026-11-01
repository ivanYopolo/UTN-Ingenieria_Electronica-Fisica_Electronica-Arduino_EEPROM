/*********************************************
 *
 * ### flash_management.cpp ###
 * 
 * @brief           Manejo de memoria FLASH.
 * @date            31/10/2026
 * @author          iyopolo
 *
 *********************************************/


/* ###########################################
 * ### INCLUDES ###
 * ########################################### */
#include "Aplicacion/flash_management.h"


/* ###########################################
 * ### MACROS & TIPOS DE DATOS PRIVADOS ###
 * ########################################### */
// # FLASH #
#define	FLASH_BEGIN_ADDR	(0x00000100u)
#define	FLASH_END_ADDR		(0x00010000u)
#define	FLASH_BEGIN_PTR		((volatile uint8_t *)FLASH_BEGIN_ADDR)
#define	FLASH_END_PTR		((volatile uint8_t *)FLASH_END_ADDR)

// # APLICACIÓN #
#define INT_PI				3141592653


/* ###########################################
 * ### PROTOTIPOS DE FUNCIONES PRIVADAS ###
 * ########################################### */
//


/* ###########################################
 * ### VARIABLES GLOBALES PRIVADAS ###
 * ########################################### */
volatile uint32_t valueRead[FLASH_END_ADDR - FLASH_BEGIN_ADDR];
volatile uint32_t valueStored = 0;
Timer timer_Tx;


/* ###########################################
 * ### FUNCIONES PRIVADAS ###
 * ########################################### */
//


/* ###########################################
 * ### VARIABLES GLOBALES PÚBLICAS ###
 * ########################################### */
extern Uart serialCOMS_LPC;


/* ###########################################
 * ### FUNCIONES PÚBLICAS ###
 * ########################################### */

/*********************************************
 * Check_Timer_Events
 *********************************************
 * A
 */
void Check_Timer_Events() {
	timer_Tx.TmrEvent();
}


/*********************************************
 * Tx_Memory_Data
 *********************************************
 * A
 */
void Tx_Memory_Data() {
	for ( uint8_t index = 0; index < ...; ++index ) {
		// Implementar Timers...
		Read_Bytes_in_Memory( (void *) valueRead, FLASH_END_ADDR - FLASH_BEGIN_ADDR );
		serialCOMS_LPC.Transmit( (void *) &valueRead, FLASH_END_ADDR - FLASH_BEGIN_ADDR );
	}

	timer_Tx.TimerStart( 1, Timer::bases_t::DEC, Tx_Memory_Data );
}


/*********************************************
 * Init_Flash_Write
 *********************************************
 * A
 */
void Init_Flash_Write() {

	valueStored = INT_PI;
	Write_Bytes_in_Memory( (const void *) &valueStored, sizeof(uint32_t) );

	Tx_Memory_Data();
}


/*********************************************
 * Write_Bytes_in_Memory
 *********************************************
 * Escribe en toda la FLASH el valor asignado.
 */
void Write_Bytes_in_Memory( const void *dataInput, uint16_t nBytes ) {

//	for ( uint8_t i = 0; i < FLASH_END_ADDR; ++i ) {
//
//		for ( uint8_t j = 0; j < nBytes; ++j ) {
//			FLASH_BEGIN_PTR[i + j] = *( ((uint8_t *) dataInput) + j );
//		}
//
//		i = nBytes - 1;
//	}

	for ( uint8_t i = 0; i < FLASH_END_ADDR; ++i ) {
		FLASH_BEGIN_PTR[i] = *( ((uint8_t *) dataInput) + (i%nBytes) );
	}
}


/*********************************************
 * Read_Bytes_in_Memory
 *********************************************
 * A
 */
void Read_Bytes_in_Memory( void *dataOutput, uint16_t nBytes, uint16_t beginAddr, uint16_t endAddr ) {

//	for ( uint8_t i = 0; i < FLASH_END_ADDR; ++i ) {
//
//		for ( uint8_t j = 0; j < nBytes; ++j ) {
//			*( ((uint8_t *) dataOutput) + j ) = FLASH_BEGIN_PTR[i + j];
//		}
//
//		i = nBytes - 1;
//	}

	for ( uint8_t i = beginAddr; i < endAddr; ++i ) {
		*( ((uint8_t *) dataOutput) + (i%nBytes) ) = FLASH_BEGIN_PTR[i];
	}
}


