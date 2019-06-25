#include "stacks.h"
#include <string.h>
#include <ctype.h>

bool isOperator(char c)
{
	if (c == '*' || c == '/' || c == '-' || c == '+')
	{
		return true;
	}

	return false;
}

int evaluate(int n1, int n2, char op)
{
	int result;
	
	switch(op)
	{
		case '+': result = n1 + n2;
				  break;
		case '-': result = n1 - n2;
				  break;
		case '*': result = n1 * n2;
				  break;
		case '/': result = n1 / n2;
				  break;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	STACK *stack = createStack();

	printf("Enter a postfix expression: ");

	char token;
	while((token = getchar()) != '\n')
	{
		if (isdigit(token) != 0)
		{
			int *num = (int*)malloc(sizeof(int));
			*num = atoi(&token);

			pushStack(stack, num);
		}
		else if (isOperator(token))
		{
			int *n1 = (int*)popStack(stack);
			int *n2 = (int*)popStack(stack);

			*n1 = evaluate(*n2, *n1, token);
			pushStack(stack, n1);
		}
	}

	int *result = (int*)popStack(stack);

	printf("\n\nResult = %d\n", *result);

	destroyStack(stack);
	return 0;
}