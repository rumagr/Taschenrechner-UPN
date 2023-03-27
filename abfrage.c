#include "abfrage.h"
#include "keypad.h"
#include <ctype.h>
#include "stack.h"
#include "ausgabe.h"
#include "operation.h"

static int zahl = 0;						//zwischengespeicherte Zahl
static int anzahlZeichen = 0; 	//die länge der Zahl

/**
  * @brief  wartet auf eine Eingabe und führt dementsprechende Aktion aus.
  * @param  Terminal* t - der Terminal
  * @retval fehler - der Fehlercode
  */
int wartenAufEingabe(Terminal* t)
{
	int fehler = 0; 							//speichert den Fehlercode
	char c = getKeyPadInput(); 		//wartet auf den input
	
	if(isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*')	//druckt alle Zahlen und Rechenoperatoren
	{
	zeichenDarstellen(c,t);
	}
	
	if(isdigit(c))	//wenn ein ziffer eingegeben wird -> aktualisiere die Zahl
	{
		fehler = zahlAktualisieren(c); 
	}
	else //sonst führe Operationen aus
	{
		if(speichern()) //speichert die zwischengespeicherte Zahl ab.
		{
			return 1; //stackoverflow
		}
		
		if(!(c == 'e' || c == 'C' || c == 'd' || c == 'r'))
		{
		printTerm("\n",t); 
		}
		
		switch(c)	//ruft operation auf
		{
			case '+':
				fehler = plus(t);
				break; 
			case '-':
				fehler = minus(t);
				break;
			case '*':
				fehler = mal(t);
				break;
			case '/':
				fehler = geteilt(t);
				break;
			case 'P': 
				gesamtenStackDrucken(t); 
				break;
			case 'p': 
				fehler = obersterWert(t);
				break;
			case 'C': 
				allesLoeschen(); 
				break;
			case 'd': 
				fehler = dublizieren(); 
				break;
			case 'r':
				fehler = vertausche();
				break; 
			case 'e': 
				zeichenDarstellen(' ',t); 
				break;
		}
	}
	return fehler; //gibt fehlercode zurück
}

/**
  * @brief  Aktualisiert die zwischengespeicherte Zahl.
  * @param  char c - die anzuhängende Ziffer
  * @retval 3 - wenn die Zahl zu lang wird
  */
int zahlAktualisieren(char c)
{
	long long temp = zahl;  
	temp *= 10; 
	temp += c - '0';  //neue zahl wird als 64 bit variable gespeichert
	
	zahl *= 10; 
	zahl += c - '0'; //neue zahl wird in der int variable gespeichert
	
	++anzahlZeichen; 
	if(temp > zahl) //wenn temp > zahl ist, ist ein überlauf entstanden
	{								//zahl und anzahlZeichen wird reseted und der fehlercode wird zurückgegeben. 
			zahl = 0; 
			anzahlZeichen = 0; 
			return 3; 
	}
	return 0; 
}
/**
  * @brief  Pushed die aktuelle Zahl auf den Stack
  * @param  None
  * @retval 1 - bei stackoverflow
  */
int speichern(void)
{
	if(anzahlZeichen != 0) //falls bisher Zeichen eingegeben wurde 
	{											// -> push die zahl und reset zahl und anzahl Zeichen
	if(push(zahl))
	{
		return 1; 					 //return 1 - bei stackoverflow 
	}
	zahl = 0;
	anzahlZeichen = 0; 
	}
	return 0; 
}
	