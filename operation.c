#include "operation.h"
#include "stack.h"
#include "ausgabe.h"

/**
  * @brief  addiert die obersten zwei Zahlen im Stack
  * @param  Terminal* t
  * @retval 2 - bei stackunderflow, 5 - bei overflow der operation
  */
int plus(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		if(pop(&z1)) 
		{
				return 2; 
		}
		if(pop(&z2))
		{
			return 2; 
		}
		
		long long temp = z1 + z2;  //(z1 + z2) als int -> wird in einem long long gepeichert z.B. INT_MAX_VALUE + 1 = INT_MIN_VALUE temp = INT_MIN_VALUE
		
		if(temp - z1 != z2) 				//wenn (z1 + z2) overflowed -> ist temp - z1 != z2						INT_MIN_VALUE -1 = INT_MIN_VALUE-1 != INT_MAX_VALUE
		{
			return 5; 
		}
		
		z1 += z2; // addiert die Zahlen
		push(z1); //push ergebnis
				
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
		return 0; 
}

/**
  * @brief  subtrahiert die obersten zwei Zahlen im Stack
  * @param  Terminal* t
  * @retval 2 - bei stackunderflow, 5 - bei overflow der operation
  */
int minus(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		if(pop(&z1))
		{
			return 2; 
		}
		if(pop(&z2))
		{
			return 2; 
		}
		
		long long temp = z2 - z1;  
		if(temp + z1 != z2)
		{
			return 5; 
		}
		z2 -= z1;
		push(z2);
		
		zahlDarstellen(z2,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

/**
  * @brief  multipliziert die obersten zwei Zahlen im Stack
  * @param  Terminal* t
  * @retval 2 - bei stackunderflow, 5 - bei overflow der operation
  */
int mal(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		if(pop(&z1))
		{
			return 2; 
		}
		if(pop(&z2))
		{
			return 2; 
		} 
		long long temp = z1 * z2; 
		if(z1 != temp / z2)
		{
			return 5; 
		}
		z1 *= z2; 
		push(z1);
		
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
		return 0; 
}

/**
  * @brief  teilt die obersten zwei Zahlen im Stack
  * @param  Terminal* t
  * @retval 2 - bei stackunderflow, 5 - bei overflow der operation, 4 - wenn durch 0 geteilt wird 
  */
int geteilt(Terminal* t)
{
		int z1 = 0; 
		int z2 = 0; 
		
		if(pop(&z1))
		{
			return 2; 
		}
		if(pop(&z2))
		{
			return 2; 
		}  
		
		if(!z1)
		{
			return 4; 
		}
	
		z2 /= z1; 
		push(z2);
		
		zahlDarstellen(z2,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

/**
  * @brief  liefert den obersten wert im stack
  * @param  Terminal* t
  * @retval 2 - wenn kein wert enthalten ist
  */
int obersterWert(Terminal* t) 
{	
		zeichenDarstellen(' ',t);
		int z1 = 0;  
		if(top(&z1))
		{
			return 0; 
		}
		zahlDarstellen(z1,t); 
		zeichenDarstellen(' ',t);
	
		return 0; 
}

/**
  * @brief  druckt den gesamten stack
  * @param  Terminal* t
  * @retval None
  */
int gesamtenStackDrucken(Terminal* t)
{	
	zeichenDarstellen(' ',t);
	int j = 0; 
	numElemente(&j); //speichere stack größe in j
	for(int i = 0; i < j; ++i)  //peek jedes Element, beginnend beim ersten und druckt es 
	{
		int num = 0;
		peek(i, &num); 					
		zahlDarstellen(num,t); 
		zeichenDarstellen(' ',t);
	}
	return 0; 
}
	
/**
  * @brief  löscht alle Elemente des Stacks
  * @param  None
  * @retval None
  */
int allesLoeschen(void)
{
	resetStack();
	//int j = 0; 
	//numElemente(&j);
	
	//for(int temp = 0; j>0; --j)	//für jedes enthaltene element entferne ein element
	//{
	//	pop(&temp); 
	//}
	return 0; 
}

/**
  * @brief  Dubliziert das letzte element im stack
  * @param  None
  * @retval 2 - wenn kein element enthalten, 1 - wenn der stack voll ist
  */
int dublizieren(void)
{
		int i = 0; 
		if(top(&i))
		{
			return 2; 
		}
		if(push(i))
		{
			return 1; 
		}
		return 0; 
}

/**
  * @brief  vertauscht die obersten elemente auf dem stack
  * @param  None
  * @retval 2 - wenn weniger als zwei elemente enhalten
  */
int vertausche(void)
{
		int z1 = 0; 
		int z2 = 0; 
		
		if(pop(&z1))
		{
			return 2; 
		}
		if(pop(&z2))
		{
			return 2; 
		}  
	
		push(z1); 
		push(z2); 
	
		return 0; 
}