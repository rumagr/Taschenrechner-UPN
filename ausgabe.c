#include "ausgabe.h" 
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

int initDisplay(Terminal* t)
{
	initITSboard();                 // Initialisierung des ITS Boards
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch
	if (!checkVersionFlashFonts()) 
	{
	    // Ueberpruefe Version der Fonts im Flash passt nicht zur Software Version
		Error_Handler();
	}
	
	*t = makeKeyPad();
	printTerm("Taschenrechner in RPN \n", t); 
	return 0; 
}

int zeichenDarstellen(char c, Terminal* t)
{
	char str[2]; 
	str[0] = c; 
	str[1] = '\0';  
	printTerm(str,t); 
	
	return 0; 
}

int zahlDarstellen(int i, Terminal* t)
{
	char str[32] = {'\0'}; 
	int current = 0; 
	
	while(i)																		//liefert zahl als invertierten string
	{
		char c = '0' + i % 10; 
		i /= 10; 
		str[current] = c;
		++current; 
	}
	--current; 
	
	for(int a = 0; a < current; ++a, --current) //invertiert den String
	{
		char b = str[current]; 
		str[current] = str[a]; 
		str[a] = b; 
	}
	
	printTerm(str, t); 
	return 0; 
}
	
