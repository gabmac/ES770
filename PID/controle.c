/*
 * controle.c
 *
 *  Created on: 03/11/2018
 *      Author: Mari Suzuki
 */

#include "../COOLER/motor_hal.h"
#include "../COOLER/timer_counter.h"

int conta = 0;

void controle(int pos[6]){

	if( pos[1] == 1 & pos[2] == 1 & pos[3] == 1 & pos[4] == 1){
		conta++;
		if(conta >= 12){
		    timer_changeMotorDirPwm(0);							/*começa desligado o cooler e o heater pwm*/
		    timer_changeMotorEsqPwm(0);
		}
		else{
		    timer_changeMotorDirPwm(60);							/*começa desligado o cooler e o heater pwm*/
		    timer_changeMotorEsqPwm(60);
		}
	}
	else if(pos[2] == 1){
	    timer_changeMotorDirPwm(80);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(60);
	}

	else if(pos[3] == 1){
	    timer_changeMotorDirPwm(80);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(60);
	}

	else if(pos[1] == 1){
	    timer_changeMotorDirPwm(30);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(50);
	}
	else if(pos[4] == 1){
	    timer_changeMotorDirPwm(50);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(30);
	}


	else if(pos[0] == 1){
	    timer_changeMotorDirPwm(0);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(30);
	}
	else if(pos[5] == 1){
	    timer_changeMotorDirPwm(30);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(0);
	}



}

