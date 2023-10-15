#include "main.h"
/**
 * *intToString - it is a function
 * to convert integer to string to be used in write function
 * @num: an integer.
 * Return: string (converted integer)
 */
char *intToString(int num)
{
int i, temp = num, numDigits;
char *str;
if (num == 0)
{
str = (char *)malloc(2 * sizeof(char));
if (str == NULL)
return (NULL);
str[0] = '0';
str[1] = '\0';
return (str);
}
numDigits = 0;
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
str = (char *)malloc((numDigits + 1) * sizeof(char));
if (str == NULL)
return (NULL);
if (num < 0)
{
str[0] = '-';
temp = -num;
}
else
temp = num;
str[numDigits] = '\0';
for (i = numDigits - 1; i >= (num < 0 ? 1 : 0); i--)
{
str[i] = '0' + (temp % 10);
temp /= 10;
}
return (str);
}
