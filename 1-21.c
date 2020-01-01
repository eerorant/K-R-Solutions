#include <stdio.h>
#define TABSTOP 8
#define MAXINPUT 2000

int getInput(char input[]);
int entab(char array[], char newArray[], int len);

/* K&R 1-21:  Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */
int main() {
	char input[MAXINPUT];
	char newArray[MAXINPUT];
	int len;

	len = getInput(input);
	entab(input, newArray, len);
	
	printf("%s\n", newArray);
}

int getInput(char input[]) {
	int c, i;
	
	for (i = 0; i < MAXINPUT - 1 && (c = getchar()) != EOF; ++i) {
		input[i] = c;
	}
	input[i] = '\0';
	return i;
}

int entab(char array[], char newArray[], int len) {
	int column, i, j, count;
	i = j = count = 0;
	column = 0;
	
	// We go through the given string (array) and keep track of the column we're in (reset at every '\n'). We copy the characters to
	// newArray. If we encounter a blank (' '), we see if they continue to a full tabstop. If so, we add a '\t' to newArray, otherwise
	// we add the blanks.
	while (i < len) {
		if (array[i] == '\n') {
			newArray[j] = array[i];
			column = 0;
			++i;
			++j;
		}
		else if (array[i] != ' ') {
			newArray[j] = array[i];
			++i;
			++j;
			++column;
		}
		else {
			// We encounter a blank, so let's see how many blanks there are in a row, count is the number of blanks
			while (array[i] == ' ') {
				// If true, we can add a tab to newArray
				if (column % TABSTOP == 0 && count != 0) {
					newArray[j] = '\t';
					++j;
					count = 0;
				}
				++i;
				++column;
				++count;
			}
			// There are no more blanks, let's add all that we counted to newArray.
			while (count > 0) {
				newArray[j] = ' ';
				++j;
				--count;
			}
		}
	}
	newArray[j] = '\0';
	return 0;
}