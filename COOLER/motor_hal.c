/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: cooler metodos                                  */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26mar2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */
#include "motor_hal.h"
#include "../PERIPHERAL/es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        cooler_init                  */
/* Method description: Initialize the cooler		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_Init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as gpio */

    PORTA_PCR13 = PORT_PCR_MUX(MotorDir_ALT);
    PORTA_PCR12 = PORT_PCR_MUX(MotorEsq_ALT);

    /* set pin as digital output */
    GPIOA_PDDR |= GPIO_PDDR_PDD(MotorDir_DIR);

}

/* ************************************************ */
/* Method name:        cooler_SetPin                */
/* Method description: Set cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void motor_SetPin(void)
{
	GPIOA_PSOR = GPIO_PSOR_PTSO(0x01u << MotorEsq_PIN);
}

/* ************************************************ */
/* Method name:        cooler_ClearPin              */
/* Method description: Clear cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_ClearPin(void)
{
	GPIOA_PCOR = GPIO_PCOR_PTCO(0x01u << MotorEsq_PIN);
	GPIOA_PCOR = GPIO_PCOR_PTCO(0x01u << MotorDir_PIN);
}
