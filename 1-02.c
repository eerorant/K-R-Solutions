#include <stdio.h>

//Exercise 1-2. Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above
main() {
	printf("123\"45\b6");
	return 0;
}