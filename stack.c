#include "stack.h"

static int stack[64] = {0}; 
static int count = 0;		//anzahl der Elemente des Stacks

/**
  * @brief  setzt den stack zurück
  * @param  None
  * @retval None
  */
int resetStack(void)
{
	count = 0; 
	return 0; 
}

/**
  * @brief  push ein element auf den stac
  * @param  int i - die zu pushende zahl
  * @retval 1 - bei stackoverflow
  */
int push(int i)
{
	if(count == 64)
	{
		return 1; 
	}
	stack[count] = i; 
	++count; 
	return 0; 
}

/**
  * @brief  entfernt das oberste element vom stack
  * @param  int* res = die adresse der zu überschreibenden variable
  * @retval 2 - bei stackunderflow
  */
int pop(int* res)
{
	if(count == 0)
	{
		return 2; 
	}
	
	*res = stack[count-1]; 
	stack[count-1] = 0; 
	--count; 
	return 0; 
}

/**
  * @brief  liefert die anzahl der elemente
  * @param  int* res = die adresse der zu überschreibenden variable
  * @retval None
  */
int numElemente(int* res)
{
	*res = count; 
	return 0; 
}

/**
  * @brief  liefert die zahl im stack an der gewünschten stelle
  * @param  int* res = die adresse der zu überschreibenden variable, int stelle - die stelle muss >= 0 und <64 sein
  * @retval None
  */
int peek(int stelle, int* res)
{
	*res = stack[stelle]; 
	return 0; 
}

/**
  * @brief  liefert die oberste zahl
  * @param  int* res = die adresse der zu überschreibenden variable
  * @retval 2 - wenn kein element im stack enthalten ist
  */
int top(int* res)
{ 
	if(!count)
	{
		return 2;
	}
	*res = stack[count-1]; 
	return 0;
}	
