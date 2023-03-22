#include "operation.h"
#include "stack.h"
#include "ausgabe.h"

int plus(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		pop(&z1); 
		pop(&z2); 
	
		z1 += z2; 
		push(z1); 
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
		return 0; 
}

int minus(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		pop(&z1); 
		pop(&z2); 
	
		z2 -= z1; 
		push(z2); 
		zahlDarstellen(z2,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

int mal(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		pop(&z1); 
		pop(&z2); 
	
		z1 *= z2; 
		push(z1); 
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
		return 0; 
}

int geteilt(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		pop(&z1); 
		pop(&z2); 
	
		z2 /= z1; 
		push(z2); 
		zahlDarstellen(z2,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

int obersterWert(Terminal* t) 
{	
		zeichenDarstellen(' ',t);
		int z1 = 0;  
		top(&z1);
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

int gesamtenStackDrucken(Terminal* t)
{	
	zeichenDarstellen(' ',t);
	int j = 0; 
	numElemente(&j);
	for(int i = 0; i < j; ++i)
	{
		int num = 0;
		peek(i, &num);
		zahlDarstellen(num,t); 
		zeichenDarstellen(' ',t);
	}
	return 0; 
}
		
int allesLoeschen(void)
{
	int j = 0; 
	numElemente(&j);
	
	for(int temp = 0; j>0; --j)
	{
		pop(&temp); 
	}
	return 0; 
}

int dublizieren(void)
{
		int i = 0; 
		top(&i);
		push(i); 
		return 0; 
}

int vertausche(void)
{
		int z1 = 0; 
		int z2 = 0; 
		
		pop(&z1); 
		pop(&z2); 
	
		push(z1); 
		push(z2); 
	
		return 0; 
}