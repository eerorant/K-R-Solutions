#include <stdio.h>

/*K&R Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.*/

main () {
	int c, i, j;
	int frequencies[256];
	
	for (i = 0; i < 256; ++i) {
		frequencies[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		++frequencies[c];
	}
	
	for (i = 0; i < 256; ++i) {
		if (frequencies[i] != 0) {
			putchar('\n');
			if (i == '\t')
				printf("\\t");
			else if (i == '\n')
				printf("\\n");
			else
				putchar(i);
			printf(": ");
			for (j = 0; j < frequencies[i]; j++) 
				putchar('#');
		}
	}
}