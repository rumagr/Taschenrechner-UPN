#include "fehler.h"
#include "keypad.h"
#include "stack.h"
#include "ausgabe.h"
#include "terminal.h"

/**
  * @brief  liefert für den fehlercode eine fehlermeldung und ermöglicht den reset des Taschenrechners
  * @param  int i - der fehlercode, Terminal* t
  * @retval None
  */
int fehlerbehandlung(int i,Terminal* t)
{
	switch(i)
	{
		case 1 :
			printTerm("\n Error: \n StackOverflow", t); 
			break; 
		case 2 : 
			printTerm("\n Error: \n StackUnderflow", t);
			break;
		case 3 :
			printTerm("\n Error: \n number exceeds range", t); 
			break; 
		case 4 : 
			printTerm("\n Error: \n division by zero",t); 
			break; 
		case 5 : 
			printTerm("\n Error: \n calculated number\n exceeds range", t); 
			break; 
	}
	printTerm("\n press C to reset",t); 
	char c = ' '; 
	while(c != 'C')
	{
		c = getKeyPadInput(); 
	}
	
	resetStack(); 
	clearTerm(t);
	printTerm("Taschenrechner in RPN \n", t);	
	
	return 0; 
	
}