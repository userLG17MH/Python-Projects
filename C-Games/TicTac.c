#include <stdio.h>

int main()
{
	char char1, char2;

	printf("Enter two characters: ");
	scanf(" %c %c", &char1, &char2);

	printf(" %c | %c | %c ", char1, char2, char2);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", char1, char2, char2);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", char2, char1, char1);

	return 0;
}
