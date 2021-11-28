/*
 * gui.h
 *
 *  Created on: 17.02.2019
 *      Author: user
 */

#ifndef GUI_H_
#define GUI_H_
#include <stdint.h>

extern uint8_t gui_speed;
extern double gui_power;
extern double gui_battery;
extern uint8_t gui_brightness;
extern uint8_t gui_charging;
extern uint8_t gui_gear;
extern int gui_trip;
extern uint8_t gui_cruise_speed_set;
extern uint8_t gui_cruise_speed_limit;
extern uint8_t gui_cruise_mode;
extern uint8_t gui_leds_byte1;
extern uint8_t gui_leds_byte2;

extern uint8_t gui_picture_iteration;
extern uint8_t gui_statement;

extern uint8_t gui_h;
extern uint8_t gui_m;


void gui_init();
extern void gui_set_brightness(uint8_t x);
extern void gui_get_data_from_can();
extern void gui_display_statement(uint8_t number);

extern void gui_screen_main();
extern void gui_screen_intro();

extern uint8_t dbg_blink;
extern uint16_t TEST_counter;
extern uint16_t TEST_counter2;
extern uint16_t TEST_counter3;
extern uint16_t TEST_counter4;
extern uint8_t TEST_flag;
extern uint8_t TEST_poprz_stan;




#endif /* GUI_H_ */
