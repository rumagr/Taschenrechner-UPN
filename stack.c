#include "stack.h"

static int stack[64] = {0}; 
static int count = 0;

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

int pop(int* res)
{
	if(count == 0)
	{
		return 1; 
	}
	
	*res = stack[count-1]; 
	stack[count-1] = 0; 
	--count; 
	return 0; 
}

int numElemente(int* res)
{
	*res = count; 
	return 0; 
}

int peek(int stelle, int* res)
{
	*res = stack[stelle]; 
	return 0; 
}

int top(int* res)
{
	if(count == 0)
	{
		return 1; 
	}
	*res = stack[count-1]; 
	return 0;
}	
