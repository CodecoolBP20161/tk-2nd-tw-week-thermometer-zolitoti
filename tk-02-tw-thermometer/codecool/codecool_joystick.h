/*
 * codecool_joystick.h
 *
 *  Created on: Feb 14, 2017
 *      Author: tamasborbas
 */

#ifndef CODECOOL_JOYSTICK_H
#define CODECOOL_JOYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "DigitalIn.h"

mbed::DigitalIn up(A2);
mbed::DigitalIn down(A3);
mbed::DigitalIn left(A4);
mbed::DigitalIn right(A5);
mbed::DigitalIn fire(D4);

/**
 * Read joystick is up or not, returns 0 or 1
 */
#define JOYSTICK_UP (up.read())

/**
 * Read joystick is down or not, returns 0 or 1
 */
#define JOYSTICK_DOWN (down.read())

/**
 * Read joystick is left or not, returns 0 or 1
 */
#define JOYSTICK_LEFT (left.read())

/**
 * Read joystick is right or not, returns 0 or 1
 */
#define JOYSTICK_RIGHT (right.read())

/**
 * Read joystick is pushed or not, returns 0 or 1
 */
#define JOYSTICK_PUSHED (fire.read())

#ifdef __cplusplus
}
#endif

#endif /* CODECOOL_JOYSTICK_H */
