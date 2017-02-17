/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   codecool_debug.h
 * Author: zsoltmazlo
 *
 * Created on January 9, 2017, 10:01 PM
 */

#ifndef CODECOOL_DEBUG_H
#define CODECOOL_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "Serial.h"

mbed::Serial pc(USBTX, USBRX);

#define D(fmt, ...) pc.printf(fmt, ##__VA_ARGS__); pc.printf("\n")



#ifdef __cplusplus
}
#endif

#endif /* CODECOOL_DEBUG_H */
