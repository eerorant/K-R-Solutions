#include <stdio.h>

/*K&R Exercise 1-12. Write a program that prints its input one word per line*/

#define IN 1
#define OUT 0

main()
{
	int c, state;
	
	state = OUT;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		} else {
			putchar(c);
			state = IN;
		}
	}
}