/*
 * main2.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: mz
 */
#include "mbed.h"
#include "codecool/codecool_lcd.h"
#include "codecool/codecool_i2c.h"
#include "codecool/codecool_serial.h"
#include "codecool/codecool_pwm.h"
#include "codecool/codecool_joystick.h"
#include "codecool/codecool_shield_names.h"
#include "codecool/codecool_pot.h"
#include "temp_modify.h"
#include "limit_modify.h"
#include "set_pulse_width.h"

#define LM75_ADDRESS 0x90

int main(){

	PWM_INIT(LED_RED_SHIELD);
	PWM_INIT(LED_GREEN_SHIELD);
	PWM_INIT(LED_BLUE_SHIELD);
	PWM_INIT(SPEAKER);

    I2C_FREQ(100000);
    SERIAL_BAUD(9600);
    SERIAL_SET_NON_BLOCKING();

    uint8_t buffer_temp[16];
    float temp;
    float modified_temp;
    int limit;

    LCD_CLS();
    LCD_LOCATE(0, 0);
    LCD_PRINTF("GADGET IS READY");
    wait(2);

    while(true){

    	//######## CODE FOR SENDING ########

    	/*if(JOYSTICK_PUSHED){
			LCD_CLS();
			buffer_temp[0] = 0x00;
			I2C_WRITE(LM75_ADDRESS, buffer_temp, 1);

			memset(buffer_temp, 0x00, sizeof (buffer_temp));
			I2C_READ(LM75_ADDRESS, buffer_temp, 2);
			int8_t _int_part = (int8_t)buffer_temp[0];
			temp = _int_part+0.5f * ((buffer_temp[1]&0x80)>>7);
			buffer_temp[0] = _int_part+ temp_send_modify(POT1_READ);
			modified_temp = temp + temp_send_modify(POT1_READ);
			LCD_CLS();
			LCD_LOCATE(0,20);
			LCD_PRINTF("sent: %.1f", modified_temp);
			SERIAL_SEND(buffer_temp, 16);
		}

    	LCD_LOCATE(0,0);
		LCD_PRINTF("Current temperature: %.1f", temp);
		LCD_LOCATE(0,10);
		LCD_PRINTF("Modification: %.1f", temp_send_modify(POT1_READ));*/

		//######## CODE FOR RECEIVING ########

        if(JOYSTICK_PUSHED){
        	LCD_CLS();
        	PWM_FREQUENCY(SPEAKER, 0);
        	PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			memset(buffer_temp, 0x00, sizeof(buffer_temp));
			SERIAL_RECV(buffer_temp, 16);
			int8_t _int_part = (int8_t)buffer_temp[0];
			temp = _int_part + 0.5f * ((buffer_temp[1]&0x80)>>7);
			LCD_LOCATE(0,0);
			LCD_PRINTF("Received: %.1f", temp);
        }

        limit = limit_modification(POT2_READ);

    	LCD_LOCATE(0,10);
    	LCD_PRINTF("Modify by: %d", limit);
    	LCD_LOCATE(0,20);
    	LCD_PRINTF("Pot value: %.1f", POT2_READ);

		if(temp < 10+limit){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD,100);
				PWM_FREQUENCY(SPEAKER, 400);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
		}

		if(temp >= 10+limit && temp < 18+limit){
			if((18+limit)-temp >= 4){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 50);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD,100);
				PWM_FREQUENCY(SPEAKER, 500);
			}else{
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD,100);
				PWM_FREQUENCY(SPEAKER, 600);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}
		}

		if(temp >= 18+limit && temp < 26+limit){
			if((26+limit)-temp >= 4){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 50);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 700);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}else{
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 800);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}
		}

		if(temp >= 26+limit && temp < 34+limit){
			if((34+limit)-temp >= 4){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 50);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD,10);
				PWM_FREQUENCY(SPEAKER, 900);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}else{
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 1000);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}
		}

		if(temp >= 34+limit){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 50);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD,0);
				PWM_FREQUENCY(SPEAKER, 1200);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
		}

		wait(0.2);

    }

}

