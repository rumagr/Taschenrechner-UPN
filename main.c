/**
 ******************************************************************************
 * @file    main.c
 * @author  Ruben
 * @version 0.1
 *
 * @date    22.03.2023
 * @brief   Taschenrechner in RPN
 ******************************************************************************
 */

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
#include "ausgabe.h"
#include "stack.h"
#include "abfrage.h"

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	Terminal t; 
	
	initDisplay(&t);
	
	while(1)
	{
		wartenAufEingabe(&t); 
	}
	
}


