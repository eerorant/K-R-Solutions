#include <stdio.h>
#define MAXARRAY 1000

int my_getline(char line[], int lim);
void reverse(char original[], char reversed[], int len);

//Exercise 1-19. Write a function reverse (s) that reverses the character string s. Use it to write a program that reverses its input a line at a time
int main() {
	char original[MAXARRAY];
	char reversed[MAXARRAY];
	int len;
	while ((len = my_getline(original, MAXARRAY)) > 0) {
		reverse(original, reversed, len);
		printf("%s\n", reversed);
	}
	return 0;
}

//my_getline: read a line into s, return length (index of '\o')
int my_getline(char s[], int lim) {
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

//reverse the elements in an array
void reverse(char original[], char reversed[], int len) {
	int i;
	//we iterate through the original array from right to left, we don't want to include '\n' so we subtract two in the beginning
	for (i = len - 2; i >= 0; --i) {
		reversed[len - i - 2] = original[i];
	}
	reversed[len - 1] = '\0';
}
