#include "stacks.h"

int main(int argc, char const *argv[])
{
	STACK *stack = createStack();

	printf("Enter a number: ");
	int num;
	scanf("%d", &num);

	while(num != 0)
	{
		int *rem = (int*)malloc(sizeof(int));

		*rem = num % 2;
		pushStack(stack, rem);

		num /= 2;
	}

	while(!emptyStack(stack))
	{
		printf("%d", *((int*)popStack(stack)));
	}
	printf("\n");
	return 0;
}