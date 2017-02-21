#include "mbed.h"
#include "codecool/codecool_lcd.h"
#include "codecool/codecool_i2c.h"
#include "codecool/codecool_serial.h"
#include "codecool/codecool_pwm.h"
#include "codecool/codecool_joystick.h"
#include "codecool/codecool_shield_names.h"
#include "codecool/codecool_pwm.h"

#define freq 2000;
#define LM75_ADDRESS 0x90

int main() {

	PWM_INIT(LED_RED_SHIELD);
	PWM_INIT(LED_GREEN_SHIELD);
	PWM_INIT(LED_BLUE_SHIELD);
	PWM_INIT(SPEAKER);

    I2C_FREQ(100000);
    SERIAL_BAUD(9600);
    SERIAL_SET_NON_BLOCKING();

    LCD_CLS();
    LCD_LOCATE(0, 0);
    LCD_PRINTF("PUSH THE BUTTON FOR SENDING");

    wait(2);

    uint8_t buffer_temp[16];
    float temp;

    while (true) {

        if(JOYSTICK_PUSHED){
        	PWM_FREQUENCY(SPEAKER, 0);
        	PWM_SET_PULSE_WIDTH(SPEAKER, 0);
        	LCD_CLS();
        	buffer_temp[0] = 0x00;
            I2C_WRITE(LM75_ADDRESS, buffer_temp, 1);

            memset(buffer_temp, 0x00, sizeof (buffer_temp));
            I2C_READ(LM75_ADDRESS, buffer_temp, 2);
            int8_t _int_part = (int8_t)buffer_temp[0];
            temp = _int_part + 0.5f * ((buffer_temp[1]&0x80)>>7);
    		LCD_CLS();
            LCD_LOCATE(0,0);
            LCD_PRINTF("sent: %.1f", temp);
            SERIAL_SEND(buffer_temp, 16);
        }

        if(JOYSTICK_LEFT){
			memset(buffer_temp, 0x00, sizeof(buffer_temp));
			SERIAL_RECV(buffer_temp, 16);
			float tempi;
			int8_t _int_part = (int8_t)buffer_temp[0];
			tempi = _int_part + 0.5f * ((buffer_temp[1]&0x80)>>7);
			LCD_LOCATE(0,12);
			LCD_PRINTF("Received: %.1f", tempi);

			if(temp < 10){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 100);
				PWM_FREQUENCY(SPEAKER, 200);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}


			if(tempi >= 10 && temp < 18){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 100);
				PWM_FREQUENCY(SPEAKER, 400);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}

			if(tempi >= 18 && temp < 26){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 600);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}


			if(tempi >= 26 && temp < 34){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 800);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}



			if(tempi >= 34){
				PWM_SET_PULSE_WIDTH(LED_RED_SHIELD, 100);
				PWM_SET_PULSE_WIDTH(LED_GREEN_SHIELD, 0);
				PWM_SET_PULSE_WIDTH(LED_BLUE_SHIELD, 0);
				PWM_FREQUENCY(SPEAKER, 1000);
				PWM_SET_PULSE_WIDTH(SPEAKER, 1);
			}
			wait(2);
}
    }
}
