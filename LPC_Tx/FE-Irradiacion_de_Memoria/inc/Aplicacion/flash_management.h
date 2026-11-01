/*********************************************
 *
 * ### flash_management.h ###
 * 
 * @brief           Manejo de memoria FLASH.
 * @date            31/10/2026
 * @author          iyopolo
 *
 *********************************************/


#ifndef         FLASH_MANAGEMENT_H_
    #define     FLASH_MANAGEMENT_H_

//	#include "Aplicacion/flash_management.h"


    /* ###########################################
     * ### INCLUDES GLOBALES ###
     * ########################################### */
	#include "Drivers/tipos.h"
	#include "Modulos/includeModulos.h"
	#include "Drivers/Systick/systick.h"
	#include "Drivers/LPC845.h"
	#include "Drivers/C-Timer/c_timer.h"


    /* ###########################################
     * ### MACROS & TIPOS DE DATOS GLOBALES ###
     * ########################################### */
    //


    /* ###########################################
     * ### VARIABLES GLOBALES PÚBLICAS ###
     * ########################################### */
	//


    /* ###########################################
     * ### PROTOTIPOS DE FUNCIONES PÚBLICAS ###
     * ########################################### */
	void Check_Timer_Events();
    void Tx_Memory_Data();
    void Init_Flash_Write();
    void Write_Bytes_in_Memory( const void *dataInput, uint16_t nBytes );
    void Read_Bytes_in_Memory( void *dataOutput, uint16_t nBytes, uint16_t beginAddr, uint16_t endAddr );

#endif          /* FLASH_MANAGEMENT_H_ */
