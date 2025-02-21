#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>

void joystick_init();
float joystick_x();
float joystick_y();
uint8_t joystick_switch();

#endif