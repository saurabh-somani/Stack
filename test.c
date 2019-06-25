#include "stacks.h"

int main(int argc, char const *argv[])
{
	STACK *stack = createStack();

	bool done = false;

	while(!done)
	{
		printf("Enter a double (EOF to exit): ");
		double *num = (double*)malloc(sizeof(double));

		if (scanf("%lf", num) == EOF || fullStack(stack))
		{
			done = true;
			free(num);
		}
		else
		{
			pushStack(stack, num);
		}
	}
	
	printf("\n\nThe List of numbers:\n");

	while(!emptyStack(stack))
	{
		double *temp = (double*)popStack(stack);
		printf("%4.1lf\n", *temp);

		free(temp);
	}

	destroyStack(stack);
	return 0;
}