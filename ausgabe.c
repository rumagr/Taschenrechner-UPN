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

/**
  * @brief  initialisiert den Display 
  * @param  Terminal* t
  * @retval none
  */
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
	
	*t = makeKeyPad();		//generiert keypad
	printTerm("Taschenrechner in RPN \n", t); //druckt string auf dem Terminal
	return 0; 
}

/**
  * @brief  stellt ein Zeichen auf dem Terminal da. 
  * @param  char c - das darzustellende Zeichen, Terminal* t 
  * @retval None
  */
int zeichenDarstellen(char c, Terminal* t)
{
	char str[2]; 	//erstellt ein char[]
	str[0] = c; 	//schreibt zeichen an die stelle 0 im char[]
	str[1] = '\0';  //markiert ende des strings 
	printTerm(str,t);  //druckt das zeichen auf dem Terminal
	
	return 0; 
}

/**
  * @brief  stellt eine zahl auf dem Terminal da
  * @param  int i - die darzustellende Zahl, Terminal* t
  * @retval None
  */
int zahlDarstellen(int i, Terminal* t)
{
	if(i < 0)
	{
		i = -1 * i; 
		zeichenDarstellen('-',t);
	}
	
	char str[32] = {'\0'}; 
	int current = 0; 
	
	if(i==0)																		//falls i == 0, drucke '0'
	{
		str[current] = '0';
		printTerm(str,t); 
		return 0; 
	}
	
	while(i)																		//liefert zahl als invertierten string
	{
		char c = '0' + i % 10; 										
		i /= 10; 
		str[current] = c;
		++current; 
	}
	--current; 
	
	for(int a = 0; a < current; ++a, --current) //invertiert den invertierten string
	{
		char b = str[current]; 
		str[current] = str[a]; 
		str[a] = b; 
	}
	
	printTerm(str, t); //druckt die Zahl als String auf dem Terminal.
	return 0; 
}
	
