#include "stacks.h"
#include <string.h>
#include <ctype.h>

#define OP1 "*/"
#define OP2 "+-"

char *charToStr(char c)
{
	char *temp = (char*)malloc(sizeof(char) * 2);
	temp[0] = c;
	temp[1] = '\0';

	return temp;
}

int main(int argc, char const *argv[])
{
	STACK *stack = createStack();

	printf("Enter a infix expression: ");
	char infix[100];
	scanf("%[^\n]%*c", infix);

	char postfix[100] = "";

	for (int i = 0; i < strlen(infix); ++i)
	{
		char *temp = charToStr(infix[i]);

		if (isalpha(infix[i]) != 0)
		{
			strcat(postfix, temp);
		}
		else if (infix[i] == '*' || infix[i] == '/')
		{
			char *ch = (char*)malloc(sizeof(char));
			*ch = infix[i];

			char *top = (char*)malloc(sizeof(char));
			top = (char*)stackTop(stack);

			if (emptyStack(stack) || *top == '+' || *top == '-')
			{
				pushStack(stack, ch);
			}
			else
			{
				while(!emptyStack(stack) && (*top == '*' || *top == '/'))
				{
					char *ch2 = (char*)popStack(stack);
					char *temp2 = charToStr(*ch2);
					strcat(postfix, temp2);
				}
			}
		}
		else
		{
			char *ch = (char*)malloc(sizeof(char));
			*ch = infix[i];

			if (emptyStack(stack))
			{
				pushStack(stack, ch);
			}
			else
			{
				while(!emptyStack(stack))
				{
					char *ch2 = (char*)popStack(stack);
					char *temp2 = charToStr(*ch2);
					strcat(postfix, temp2);
				}
				pushStack(stack, ch);
			}
		}
	}

	while(!emptyStack(stack))
	{
		char *t = (char*)popStack(stack);
		//printf("Pop = %c\n", *t);
		char *temp2 = charToStr(*t);
		strcat(postfix, temp2);
	}

	printf("\n\nPostfix: %s\n", postfix);

	destroyStack(stack);
	return 0;
}