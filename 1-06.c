#include <stdio.h>

//Exercise 1-6. Verify that the expression qetchar () I= EOFis 0 or 1
main() {
	//print 0 if input is EOF, else 1
	printf("%d", getchar() != EOF);
}