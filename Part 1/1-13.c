#include <stdio.h>

/* K&R Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.*/

#define IN 1
#define OUT 0

main() {
	int i, j, c, l, state;
	int wordLengthFrequency[20];
	
	for (i = 0; i < 20; ++i) {
		wordLengthFrequency[i] = 0;
	}
	
	l = 0;
	state = OUT;
	
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				++wordLengthFrequency[l - 1];
				state = OUT;
				l = 0;
			}
		} else {
			++l;
			state = IN;
		}
	}
	
	for (i = 0; i < 20; ++i) {
		printf("\n%2d: ", i + 1);
		for (j = 0; j < wordLengthFrequency[i]; j++) {
			putchar('#');
		}
	}
	
}