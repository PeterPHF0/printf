#include "main.h"

/**
 * *intToString - it is a function
 * to convert integer to string to be used in write function
 * @num: an integer.
 *
 * Return: string (converted integer)
 */

char *intToString(int num)
{
	/* Handle the case of a zero input separately */
	if (num == 0)
	{
		char *str = (char *)malloc(2 * sizeof(char));

		if (str == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	/* Calculate the number of digits in the integer */
	int temp = num;
	int numDigits = 0;

	/* Account for the negative sign if the number is negative */
	if (num < 0)
	{
		numDigits++;
		temp = -temp;
	}
	while (temp)
	{
		numDigits++;
		temp /= 10;
	}

	/* Allocate memory for the string, including space for null-terminator */
	char *str = (char *)malloc((numDigits + 1) * sizeof(char));

	if (str == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	/* Handle the negative sign if the number is negative */
	if (num < 0)
	{
		str[0] = '-';
		temp = -num;
	}
	else
	{
		temp = num;
	}

	/* Convert the integer to a string */
	str[numDigits] = '\0';
	int i;

	for (i = numDigits - 1; i >= (num < 0 ? 1 : 0); i--)
	{
		str[i] = '0' + (temp % 10);
		temp /= 10;
	}
	return (str);
}
