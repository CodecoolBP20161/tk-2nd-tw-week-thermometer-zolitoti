/*
 * codecool_pwm.h
 *
 *  Created on: Jan 19, 2017
 *      Author: zsoltmazlo
 */

#ifndef CODECOOL_PWM_H_
#define CODECOOL_PWM_H_

#include "PwmOut.h"

typedef mbed::PwmOut* _pwm_t;

_pwm_t _pwms[10];
uint16_t _pwm_ports[10];
uint8_t _pwm_last_index = 0;

/**
 * Initialize PWM output on given <b>pin</b>.
 * 
 * @param pin: which pin should we use as a PWM output
 * 
 * <b>Example</b>:<br>
 * PWM_INIT(LED1);
 */
#define PWM_INIT(pin) { \
    _pwm_t test = new PwmOut(pin); \
    _pwms[_pwm_last_index] = test; \
    _pwm_ports[_pwm_last_index++] = pin; }

/**
 * Set PWM frequency to <b>frequency</b>.
 * 
 * PWM signals need to alternate at a very high rate, therefore before using them,
 * you should set up the refresh-rate by hand. 
 * 
 * @param pin: which pin should be setup
 * @param frequency: the refresh-rate in Hz
 * 
 * <b>Example</b>:<br>
 * PWM_FREQUENCY(LED1, 2000);
 */
#define PWM_FREQUENCY(pin, frequency) { \
    _pwm_t p = NULL; \
    for (uint8_t i = 0; i < _pwm_last_index; ++i) if (pin == _pwm_ports[i]) p = _pwms[i];\
    if( p != NULL ) { \
    	if(frequency>0) {p->period(1.0f / (float) frequency);}\
    	else {p->period(0);} } }

/**
 * Set pulse width percentage of the PWM signal on <b>pin</b>. The width parameter
 * could be either float or integer.
 * 
 * @param pin: which pin should be setup
 * @param width: the pulse width percentage, in the range of 0 and 100
 * 
 * <b>Example</b>:<br>
 * PWM_SET_PULSE_WIDTH(LED1, 50);
 */
#define PWM_SET_PULSE_WIDTH(pin, width) { \
    _pwm_t p = NULL; \
    for (uint8_t i = 0; i < _pwm_last_index; ++i) if (pin == _pwm_ports[i]) p = _pwms[i];\
    if( p != NULL ) p->write( (float)(100-width)/100.0f ); }



#endif /* CODECOOL_PWM_H_ */
