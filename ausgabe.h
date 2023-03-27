#ifndef __AUSGABE_H__
#define __AUSGABE_H__
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "init.h"
#include "delay.h"
#include "LCD_GUI.h"
#include "LCD_Demos.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "LCD_Touch.h"
#include "error.h"
#include "keypad.h"

int initDisplay(Terminal* t); 
int zeichenDarstellen(char c, Terminal* t); 
int zahlDarstellen(int i, Terminal* t); 
int reset(void); 

#endif