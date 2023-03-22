#include "abfrage.h"
#include "keypad.h"
#include <ctype.h>
#include "stack.h"
#include "ausgabe.h"
#include "operation.h"

static int zahl = 0; 
static int anzahlZeichen = 0; 

int wartenAufEingabe(Terminal* t)
{
	char c = getKeyPadInput(); 
	
	if(c != 'e' && c != 'P' && c != 'p' && c != 'C' && c != 'd' && c != 'r' )
	{
	zeichenDarstellen(c,t);
	}
	
	if(isdigit(c))
	{
		zahlAktualisieren(c);  
	}
	else
	{
		switch(c)
		{
			case '+':
				speichern();
				plus(t);
				break; 
			case '-':
				speichern();
				minus(t);
				break;
			case '*':
				speichern();
				mal(t);
				break;
			case '/':
				speichern();
				geteilt(t);
				break;
			case 'P': 
				speichern();
				gesamtenStackDrucken(t); 
				break;
			case 'p': 
				speichern();
				obersterWert(t);
				break;
			case 'C': 
				speichern();
				allesLoeschen(); 
				break;
			case 'd': 
				speichern();
				dublizieren(); 
				break;
			case 'r':
				speichern();	
				vertausche();
				break; 
			case 'e':
				speichern();
				zeichenDarstellen(' ',t);
				break;
		}
	}
	return 0; 
}


int zahlAktualisieren(char c)
{
	zahl *= 10; 
	zahl += c - '0'; 
	++anzahlZeichen; 
	return 0; 
}

int speichern(void)
{
	if(anzahlZeichen != 0)
	{
	push(zahl);
	zahl = 0;
	anzahlZeichen = 0; 
	}
	return 0; 
}
	