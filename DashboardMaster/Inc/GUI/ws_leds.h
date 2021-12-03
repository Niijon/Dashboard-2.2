/*
 * ws_leds.h
 *
 *  Created on: 16.02.2019
 *      Author: user
 */

#ifndef WS_LEDS_H_
#define WS_LEDS_H_

#include "stm32f1xx_hal.h"

extern uint8_t ws_spd;
extern uint8_t ws_spd_lim ;
extern uint8_t ws_bat;
extern uint8_t ws_powr;
extern uint8_t ws_powr_mod;
extern uint8_t ws_leds1;
extern uint8_t ws_leds2;
extern uint8_t ws_led_bright;
extern uint8_t ws_mod;

void ws_senddata(void);
void ws_set_leds(uint8_t byte1,uint8_t byte2);
void ws_set_speed(uint8_t x);
void ws_set_power(double x, uint8_t charging);
void ws_set_battery(double x);
void ws_set_brightness(uint8_t y);


















#endif /* WS_LEDS_H_ */
