/*
 * displays.h
 *
 *  Created on: 04.12.2018
 *      Author: user
 */

#ifndef __DISPLAYS_H__
#define __DISPLAYS_H__

void display_battery(double value);
void display_gear(int state);
void display_power(double value,uint8_t charging);
void display_speed(double value,uint8_t cruise);
void display_logo(void);
void displays_init();
void display_power_disable(void);
void display_battery_disable(void);
void display_gear_disable(void);
void displays_set_brightness(uint8_t val);

extern u8g_t u8g_big;
extern u8g_t u8g_small;

#endif /* DISPLAYS_H_ */
