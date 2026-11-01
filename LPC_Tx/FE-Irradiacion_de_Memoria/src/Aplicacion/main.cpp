/*********************************************
 *
 * ### Irradiación de Memoria en CONEA ###
 * ## Física Electrónica - R2521 - CL2026 ##
 *
 * @brief           Código de escritura en memoria FLASH
 * 					y lectura constante en la misma.
 *
 * @author			Enrique Stutz
 * 					Iván Yopolo
 *
 *********************************************/

#include "Aplicacion/inicializar.h"


int main( void ) {

	Inicializar();

    while ( 1 ) {
    	// Aplicar timers...
    	Check_Timer_Events();
    }


    return 0;
}
