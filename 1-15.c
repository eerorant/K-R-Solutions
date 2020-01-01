#include <stdio.h>

int fahrToCelcius(int f);

//Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
main() {
	printf("%d", fahrToCelcius(100));
}

int fahrToCelcius(int f) {
	return (5.0/9.0)*(f-32);
}