/*
 * lcd_conf.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_


/**********MODE************/


#define LCD_8_BIT_MODE    0
#define LCD_4_BIT_MODE    1
#define LCD_MODE  LCD_4_BIT_MODE

/*********LCD_PIN_4_mode********/



/******data pin*******/
#define LCD_PORT    PORTA

/******control pin*********/

#define RS      9
#define E       11

#endif /* HAL_LCD_LCD_CONF_H_ */
