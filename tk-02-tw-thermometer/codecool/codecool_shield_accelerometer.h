/*
 * codecool_shield_accelerometer.h
 *
 *  Created on: Feb 14, 2017
 *      Author: tamasborbas
 */

#ifndef CODECOOL_SHIELD_ACCELEROMETER_H
#define CODECOOL_SHIELD_ACCELEROMETER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "MMA7660/MMA7660.h"

MMA7660 MMA(D14,D15);

/**
 * Read the acceleration in the x axis
 */
#define SHIELD_ACC_X_READ (MMA.x())

/**
 * Read the acceleration in the y axis
 */
#define SHIELD_ACC_Y_READ (MMA.y())

/**
 * Read the acceleration in the z axis
 */
#define SHIELD_ACC_Z_READ (MMA.z())

#ifdef __cplusplus
}
#endif

#endif /* CODECOOL_SHIELD_ACCELEROMETER_H */
