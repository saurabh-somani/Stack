#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_node
{
	void *pData;
	struct stack_node *next;
}STACK_NODE;

typedef struct
{
	int count;
	STACK_NODE *top;
}STACK;

//STACK FUNCTIONS
STACK* 	createStack();						  	//CREATE STACK
bool   	pushStack(STACK *stack, void *pDataIn); //PUSH STACK
void*  	popStack(STACK *stack);					//POP STACK
void*  	stackTop(STACK *stack);					//WHAT'S THE STACK TOP?
bool   	emptyStack(STACK *stack);				//IS STACK EMPTY?
bool   	fullStack(STACK *stack);				//IS STACK FULL?
int    	stackCount(STACK *stack);				//WHAT'S THE STACK COUNT?
STACK* 	destroyStack(STACK *stack);				//DESTROY STACK



STACK *createStack()
{
	STACK *stack = (STACK*)malloc(sizeof(STACK));

	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	}

	return stack;
}

bool pushStack(STACK *stack, void *pDataIn)
{
	STACK_NODE *newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));

	if (!newPtr)
	{
		return false;
	}

	newPtr->pData = pDataIn;
	newPtr->next = stack->top;
	stack->top = newPtr;

	(stack->count)++;

	return true;
}

void *popStack(STACK *stack)
{
	void *pDataOut;

	if (stack->count == 0)
	{
		pDataOut = NULL;
	}
	else
	{
		STACK_NODE *temp = stack->top;
		pDataOut = stack->top->pData;
		stack->top = stack->top->next;

		free(temp);
		(stack->count)--;
	}

	return pDataOut;
}

void *stackTop(STACK *stack)
{
	if (stack->count == 0)
	{
		return NULL;
	}

	return stack->top->pData;
}

bool emptyStack(STACK *stack)
{
	return (stack->count == 0);
}

bool fullStack(STACK *stack)
{
	STACK_NODE *temp;

	if (temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))
	{
		free(temp);
		return false;
	}

	return true;
}

int stackCount(STACK *stack)
{
	return stack->count;
}

STACK *destroyStack(STACK *stack)
{
	STACK_NODE *temp;

	if (stack)
	{
		while(stack->top != NULL)
		{
			free(stack->top->pData);

			temp = stack->top;
			stack->top = stack->top->next;
			free(temp);
		}

		free(stack);
	}

	return NULL;
}