#include "main.h"
/**
 * *intToString - it is a function
 * to convert integer to string to be used in write function
 * @num: an integer.
 * Return: string (converted integer)
 */
char *intToString(int num)
{
if (num == 0)
{
char *str = (char *)malloc(2 * sizeof(char));
if (str == NULL)
return (NULL);
str[0] = '0';
str[1] = '\0';
return (str);
}
int temp = num;
int numDigits = 0;
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
char *str = (char *)malloc((numDigits + 1) * sizeof(char));
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
int i;
for (i = numDigits - 1; i >= (num < 0 ? 1 : 0); i--)
{
str[i] = '0' + (temp % 10);
temp /= 10;
}
return (str);
}
