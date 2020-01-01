#include <stdio.h>

#define LINELENGTH 10
#define MAXINPUT 2000

int myGetLine(char array[]);
int fold(char string1[], char string2[], int len);

/*Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
    Eero: THIS IS UNFINISHED
*/
int main() {
	char input[MAXINPUT];
	char newString[MAXINPUT];
	int len;
	
	len = myGetLine(input);
	
	if (len > LINELENGTH) {
		fold(input, newString, len);
		printf("%s\n", newString);
	} else {
		printf("%s\n", input);
	}
	return 0;
}

//Read a line from stdin, return length
int myGetLine(char input[]) {
	int c, i;
	
	for (i = 0; i < MAXINPUT - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		input[i] = c;
	}
	if (c == '\n') {
		input[i] = c;
		++i;
	}
	input[i] = '\0';
	return i;
}

int fold(char string1[], char string2[], int len) {
	int i, j, column;
	i = j = 0;
	column = 0;
	while (i < len) {
		if (column < LINELENGTH) {
			string2[j] = string1[i];
			++i;
			++j;
			++column;
		} else {
			string2[j] = '\n';
			++j;
			column = 0;
		}
	}
	string2[j] = '\0';
	return 0;
}
