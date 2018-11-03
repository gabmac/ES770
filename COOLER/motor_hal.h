/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: cooler metodos                                  */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26mar2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */
#ifndef SOURCES_MOTOR_HAL_H_
#define SOURCES_MOTOR_HAL_H_

/* ************************************************ */
/* Method name:        cooler_init                  */
/* Method description: Initialize the cooler		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_Init(void);



/* ************************************************ */
/* Method name:        cooler_SetPin                */
/* Method description: Set cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_SetPin(void);

/* ************************************************ */
/* Method name:        cooler_ClearPin              */
/* Method description: Clear cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void motor_ClearPin(void);


#endif

