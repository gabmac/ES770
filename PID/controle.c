/*
 * controle.c
 *
 *  Created on: 03/11/2018
 *      Author: Mari Suzuki
 */

#include "../COOLER/motor_hal.h"
#include "../COOLER/timer_counter.h"


void controle(int pos[4]){

	if(pos[1] == 1 & pos[2] == 1 & pos[2] == 1 & pos[3] == 1){
	    timer_changeMotorDirPwm(0);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(0);
	}

	else if(pos[3] == 1){
	    timer_changeMotorDirPwm(30);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(0);
	}
	else if(pos[0] == 1){
	    timer_changeMotorDirPwm(0);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(30);
	}
	else if(pos[1] == 1){
	    timer_changeMotorDirPwm(30);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(10);
	}


	else if(pos[2] == 1){
	    timer_changeMotorDirPwm(10);							/*começa desligado o cooler e o heater pwm*/
	    timer_changeMotorEsqPwm(30);
	}

}

