/*********************************************
 *
 * ### inicializar.cpp ###
 * 
 * @brief           Inicializa el SysTick a 1 ms e inicia las secuencias.
 * 					Configura el modo de funcionamiento de la interrupción externa.
 * @date            Jun 10, 2026
 * @author          iyopolo
 *
 *********************************************/


/* ###########################################
 * ### INCLUDES ###
 * ########################################### */
#include "Aplicacion/inicializar.h"


/* ###########################################
 * ### MACROS & TIPOS DE DATOS PRIVADOS ###
 * ########################################### */
#define	__CTIMER_PRESCALER_FREQ		((uint32_t) 1e6)

/***************************
 *** PINOUT ***
 ***************************/

// >> UART: comunicación asíncrona
#define __UART_TX_PORT				0
#define __UART_TX_PIN				25
#define __UART_RX_PORT				0
#define __UART_RX_PIN				24
#define __UART_USART_x				0
#define __UART_BAUDRATE				9600
#define __UART_MAX_RX				1024
#define __UART_MAX_TX				1024


/* ###########################################
 * ### PROTOTIPOS DE FUNCIONES PRIVADAS ###
 * ########################################### */
//


/* ###########################################
 * ### VARIABLES GLOBALES PRIVADAS ###
 * ########################################### */
CTimer ctimerObject( __CTIMER_PRESCALER_FREQ );
Uart serialCOMS_LPC( __UART_TX_PORT, __UART_TX_PIN, __UART_RX_PORT, __UART_RX_PIN, __UART_USART_x,
					 __UART_BAUDRATE, Uart::bits_de_datos::ocho_bits, Uart::paridad_t::NoParidad,
					 __UART_MAX_RX, __UART_MAX_TX );


/* ###########################################
 * ### FUNCIONES PRIVADAS ###
 * ########################################### */
//


/* ###########################################
 * ### VARIABLES GLOBALES PÚBLICAS ###
 * ########################################### */
//


/* ###########################################
 * ### FUNCIONES PÚBLICAS ###
 * ########################################### */

/*********************************************
 * Inicializar
 *********************************************
 * Inicializa el SysTick a 1 ms e inicia las secuencias.
 * Configura el modo de funcionamiento de la interrupción externa.
 */
void Inicializar() {
//	 ### Systick ###
	SysTick_Config( 1 );

	// ### FLASH ###
	Init_Flash_Write();
}


