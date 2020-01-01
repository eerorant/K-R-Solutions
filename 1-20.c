#include <stdio.h>
#define TABSTOP 8
#define MAXINPUT 2000

int getInput(char input[]);
int detab(char array[], char newArray[], int len);


/* K&R 1-20: Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the
next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?  */

int main() {
	int c, len;
	char input[MAXINPUT];
	char newArray[MAXINPUT];
	len = getInput(input);
	detab(input, newArray, len);
	
	printf("%s\n", newArray);
	
	return 0;
	
}

/* Read input into input[] array, return length*/
int getInput(char input[]) {
	int c, i;
	
	for (i = 0; i < MAXINPUT - 1 && (c = getchar()) != EOF; ++i) {
		input[i] = c;
	}
	input[i] = '\0';
	return i;
}

/* detab gets two arrays as parameters and copies the first array to the second one, replacing all tabs with an adequate amount of spaces. */
int detab(char array[], char newArray[], int len) {
	int column, i, j;
	i = j = 0;
	column = 0;
	while (i < len) {
		if (array[i] == '\t') {
			newArray[j] = ' ';
			++column;
			++j;
			while (column % TABSTOP > 0) {
				newArray[j] = ' ';
				++column;
				++j;
			}
		} else if (array[i] == '\n') {
			newArray[j] = array[i];
			column = 0;
			++j;
		} else {
			newArray[j] = array[i];
			++column;
			++j;
		}
		++i;
	}
	newArray[j] = '\0';
	return 0;
	
}
 
