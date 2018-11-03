/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */



/*                    Motor definitions                  */
#define Motor_PORT_BASE_PNT        PORTA
#define COOLER_GPIO_BASE_PNT        PTA

#define MotorDir_PIN                 13U
#define MotorDir_DIR                 (GPIO_OUTPUT << MotorDir_PIN)
#define MotorDir_ALT                 0x01u

#define MotorEsq_PIN                 12U
#define MotorEsq_DIR                 (GPIO_OUTPUT << MotorDir_PIN)
#define MotorEsq_ALT                 0x01u




#define LS_PORT_BASE_PNT            PORTE                                   /* peripheral port base pointer */
#define LS_GPIO_BASE_PNT            PTE

#define LS1_PIN                     20U                                      /* led #0 pin */
#define LS1_DIR_OUTPUT              (GPIO_OUTPUT << LS1_PIN)
#define LS1_ALT                     0x01u

#define LS2_PIN                     21U                                      /* led #1 pin */
#define LS2_DIR_OUTPUT              (GPIO_OUTPUT << LS2_PIN)
#define LS2_ALT                     0x01u

#define LS3_PIN                     22U                                      /* led #2 pin */
#define LS3_DIR_OUTPUT              (GPIO_OUTPUT << LS3_PIN)
#define LS3_ALT                     0x01u

#define LS4_PIN                     23U                                      /* led #3 pin */
#define LS4_DIR_OUTPUT              (GPIO_OUTPUT << LS4_PIN)
#define LS4_ALT                     0x01u



/*                  END OF Motor definitions             */

#define TAC_PORT_BASE_PNT        PORTE                                   /* peripheral port base pointer */
#define TAC_GPIO_BASE_PNT        PTE


#define TACESQ_PIN                   29U


#define TACDIR_PIN                   30U


#define TACOMETRO_ALT                  0x04u
#define SOP4_SEL					   0x00u
#define SOP2_SEL                       0x02u








#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
