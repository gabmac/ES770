#include "../PERIPHERAL/es670_peripheral_board.h"
#include "adc.h"




/* ************************************************** */
/* Method name: 	 heater_hal_StateMachine          */
/* Method description:  maquina de estados do sensor  */
/*			 de temp		                          */
/* Input params:	   n/a 			                  */
/* Outpu params:	   n/a 			                  */
/* ************************************************** */
int heater_hal_StateMachine(int isensor)
{
	adc_initConvertion(isensor);
	while(!adc_isAdcDone()){}
	int value = adc_getConvertionValue();
	while(adc_isAdcDone()){}
	return value;


}


