/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   i2c.h
 * Author: zsoltmazlo
 *
 * Created on January 9, 2017, 9:59 PM
 */

#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "I2C.h"

//         sda,  scl
//I2C sensor(PTB3, PTB2);
mbed::I2C sensor(PTE0, PTE1);

/**
 * Set frequency for I2C communication.
 * 
 * There are multiple versions of I2C standard which are offers
 * different speeds for communications. But usually not supported all
 * of them on every I2C enabled devices, therefore we need to check
 * what frequencies are supported for each device.
 * 
 * @param frequency: I2C communication frequency in Hz.
 * 
 * <b>Example:</b><br>
 * I2C_FREQ(100000); // makes the speed to 100kHz
 */
#define I2C_FREQ(freq) sensor.frequency(freq)

/**
 * Send number of <b>len</b> bytes of data over I2C to the device listening on 
 * <b>address</b>, and reading them from <b>buffer</b> from index 0.
 * 
 * <b>NOTE</b>: the <b>buffer</b> needs to have at least the size of <b>len</b>, 
 * otherwise it will cause a Segmentation fault.
 * 
 * @param buffer: the byte buffer which we want to transmit
 * @param len: how many bytes we want to transmit
 * 
 * <b>Example</b>:<br>
 * uint8_t buffer[4] = {0x00, 0x01, 0x02, 0x03};<br> 
 * I2C_WRITE(0x90, buffer, 4);
 */
#define I2C_WRITE(address, buffer, len) sensor.write(address, (const char*)buffer, len)

/**
 * Waits for receiving number of <b>len</b> bytes of data over I2C to the device
 * listening on <b>address</b>, and loads them into <b>buffer</b> from index 0.
 * 
 * <b>NOTE</b>: the <b>buffer</b> needs to have at least the size of <b>len</b>, 
 * otherwise it will cause a Segmentation fault.
 * 
 * @param buffer: the byte buffer which could be used to store data
 * @param len: how many bytes we want to receive
 * 
 * <b>Example</b>:<br>
 * uint8_t buffer[12];<br> 
 * I2C_READ(0x90, buffer, 12);
 */
#define I2C_READ(address, buffer, len) sensor.read(address, (char*)buffer, len)


#ifdef __cplusplus
}
#endif

#endif /* I2C_H */
