/* ***************************************************************** */
/* File name:        timer_counter.h                                 */
/* File description: cooler metodos para pwm                         */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    05jun2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */



#ifndef SOURCES_TIMER_COUNTER_H_
#define SOURCES_TIMER_COUNTER_H_


void timer_initTPM1AsPWM(void);
void timer_MotorInit(void);
void timer_changeMotorEsqPwm(int iPwm);
void timer_changeMotorDirPwm(int i);

#endif /* SOURCES_TIMER_COUNTER_H_ */
