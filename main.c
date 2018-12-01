

/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "PERIPHERAL/es670_peripheral_board.h"
#include "SERIAL/mcg_hal.h"
#include "SERIAL/debugUart.h"
#include "UTIL/util.h"
#include "UTIL/tc_hal.h"
#include "fsl_debug_console.h"
#include "COOLER/motor_hal.h"
#include "COOLER/timer_counter.h"
#include "PID/pid.h"
#include <stdio.h>
#include <stdlib.h>
#include "HEATER/adc.h"
#include "HEATER/heater_hal.h"
#include "PID/controle.h"


/* system includes */
#include "fsl_debug_console.h"

/* globals */
volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
volatile unsigned int uiTempCelsius = 0;
volatile unsigned int uiFlagIntCom = 0,vuiPonteiro;
volatile char vcBuffer[50],cComand;


/* ************************************************ */
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: cyclic executive interrupt   */
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */
    uiFlagNextPeriod = 1;
}


/****************************************************/
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: interpretCmd interrupt 		*/
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/****************************************************/

void UART0_IRQHandler(void){
	uiFlagIntCom = 1;
	cComand = GETCHAR();
	if(vuiPonteiro >50 ){
		vuiPonteiro = 0;
	}
	vcBuffer[vuiPonteiro] = cComand;
	vuiPonteiro++;

}


void leitura_sensor(int value){
	PUTCHAR(value+'0');
	PUTCHAR(' ');
}

void qual_sensor(int i){
	PUTCHAR('S');
	PUTCHAR(i+'0');
	PUTCHAR(' ');
}

void imprime(int v){
	int i;
	PUTCHAR('A');
	for(i = 0; i<3; i++){
		int aux = 0;
		if(i == 0){
			aux = v/100;
			PUTCHAR(aux+'0');
			v = v%100;
		}
		else if(i == 1){
			aux = v/10;
			PUTCHAR(aux+'0');
			v = v%10;
		}
		else{
			PUTCHAR(v+'0');
		}
	}
}



int main(void)
{

 	int branco = 0;// 0 linha branca
	mcg_clockInit();
	measure_Init();
    debugUart_init();
    tc_installLptmr0(1000000/100, main_cyclicExecuteIsr);
    NVIC_EnableIRQ(UART0_IRQn); 						/* habilita interrupcoes de UART0 */
    UART0_C2_REG(UART0) |= UART0_C2_RIE(1); 			/* habilita interrupcao para RDRF */
    adc_initADCModule();
    /* configura ADC*/
    timer_initTPM1AsPWM();
    timer_MotorInit();
    timer_changeMotorDirPwm(100);							/*começa desligado o cooler e o heater pwm*/
    timer_changeMotorEsqPwm(100);
    pid_Set(0);
	PID_DATA pid_data;
	pid_init(&pid_data);
    int s1, s2;


    int value[6];
    int i = 4;
    int valor;
    while(1){

    	for(i=0;i<6;i++){
    		qual_sensor(i);
			valor =  heater_hal_StateMachine(i);
			if(branco == 0){
				if(valor > 100)
					value[i] = 1;
				else
					value[i] = 0;
			}
			else{
				if(valor < 100)
					value[i] = 1;
				else
					value[i] = 0;
			}
			leitura_sensor(value[i]);
    	}


    	controle(value);

    	while(!uiFlagNextPeriod);
    		uiFlagNextPeriod = 0;


    }
    /* cooperative cyclic executive main loop */

    /* Never leave main */
    return 0;
}
