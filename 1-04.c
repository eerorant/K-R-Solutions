#include <stdio.h>

//Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.

main()
{
	float celcius, fahr;
	int lower, upper, step;

	lower = -40;	/*lower limit*/
	upper = 300;	/*upper limit*/
	step = 20;	/*step size*/

	celcius = lower;
	printf("Celcius\tFahrenheit\n");
	while (fahr <= upper) {
		fahr = (9.0 / 5.0) * celcius + 32.0;
		printf("%7.0f\t%10.1f\n", celcius, fahr);
		celcius += step;
	}
}