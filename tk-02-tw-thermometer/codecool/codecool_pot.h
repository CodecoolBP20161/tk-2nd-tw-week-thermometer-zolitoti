/*
 * codecool_pot.h
 *
 *  Created on: Feb 14, 2017
 *      Author: tamasborbas
 */

#ifndef CODECOOL_POT_H
#define CODECOOL_POT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "AnalogIn.h"

mbed::AnalogIn pot1 (A0);
mbed::AnalogIn pot2 (A1);

/**
 * Read the value of the first pot
 */
#define POT1_READ ((float)pot1)

/**
 * Read the value of the second pot
 */
#define POT2_READ ((float)pot2)

#ifdef __cplusplus
}
#endif

#endif /* CODECOOL_POT_H */
