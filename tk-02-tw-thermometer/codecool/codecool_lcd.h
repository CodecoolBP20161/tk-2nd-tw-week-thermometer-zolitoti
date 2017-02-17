/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   codecool_lcd.h
 * Author: zsoltmazlo
 *
 * Created on January 17, 2017, 1:37 PM
 */

#ifndef CODECOOL_LCD_H
#define CODECOOL_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "C12832/C12832.h"

C12832 lcd(D11, D13, D12, D7, D10);

/**
 * Clear whole screen on LCD.
 */
#define LCD_CLS() lcd.cls()

/**
 * Set cursor on LCD display to position <b>x,y</b>, where x,y=0,0 means the 
 * top-left corner of the screen.
 * 
 * @param x: position on the horizontal axes
 * @param y: position on the vertical axes
 * 
 * <b>Example</b>:<br>
 * LCD_LOCATE(0,0);
 */
#define LCD_LOCATE(x, y) lcd.locate(x, y)

/**
 * Print <b>fmt</b> text to LCD in current position. Based on a common printf 
 * solution, the function allows to use formatted string with variable number of
 * arguments and insert them instead of format specifiers.
 * 
 * @param fmt: mandatory parameter, which holds a character array with or without
 * format specifiers
 * @param ...: other parameters to insert into formatter string.
 * 
 * <b>Example</b>:<br>
 * LCD_PRINTF("hello: %d", 12); // will print 'hello: 12' string.
 */
#define LCD_PRINTF(fmt, ...) lcd.printf(fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* CODECOOL_LCD_H */

