#include <stdio.h>



main() {
	int i;
	
	for (i = 0; i < 256; ++i) {
		printf("%d: ", i);
		putchar(i);
		putchar('\n');
	}
}