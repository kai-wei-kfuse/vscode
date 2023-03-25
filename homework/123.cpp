#include <stdlib.h>

#include <stdio.h>

int main()

{

	int number = 123456;

	char string[25];

	itoa(number, string, 10);

	printf("integer=%dstring=%s\n", number, string);

	return 0;
}