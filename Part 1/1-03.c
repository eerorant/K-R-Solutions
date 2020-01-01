#include <stdio.h>

//Exercise 1-3. Modify the temperature conversion program to print a heading above the table.

main()
{
	float fahr, celcius;
	int lower, upper, step;

	lower = -40;	/*lower limit*/
	upper = 300;	/*upper limit*/
	step = 20;	/*step size*/

	fahr = lower;
	printf("Fahrenheit\tCelcius\n");
	while (fahr <= upper) {
		celcius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%10.0f\t%7.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
}