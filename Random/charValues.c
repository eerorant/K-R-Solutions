#include <stdio.h>

/*print the numeric value of inputted chars*/
main() {
	int c, i;
	
	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			printf("%d\n", c);
		}
	}
	
}