#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);
void removeTrailing(char line[], int len);

//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
int main() {
	int len;
	char line[MAXLINE];
	
	while ((len = my_getline(line, MAXLINE)) > 0) {
		printf("%s", line);
		removeTrailing(line, len);
	}
	return 0;
}

//my_getline: read a line into s, return length
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

//remove spaces and tabs at the end of an array
void removeTrailing(char line[], int len) {
	int c;
	
	--len; //we move the index to the last character excluding \n and \0
	--len;
	while (line[len] == ' ' || line[len] == '\t') {
		--len;
	}
	line[len + 1] = '\n';
	line[len + 2] = '\0';		
}



