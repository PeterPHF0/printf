#include "main.h"

/**
 * binary - a function to convert decimal number to binary.
 * @str: format string.
 * @i: index.
 * @ls: argument list.
 *
 * Return: lenth of string.
 */

void binary(const char *str, int i, va_list ls)
{
	int num = va_arg(ls, int);
	int *arr = generate_array(num);
	int len = get_arr_len(arr);
	char c;
	int i = 0;

	while (len)
	{
		if (num >= arr[i])
		{
			c = '1';
			write(1, &c, 1);
			num = num - arr[i];
		}
		else
		{
			c = '0';
			write(1, &c, 1);
		}
		i++;
		len--;
	}
	_put(&str[j], ls);
}

/**
 * *generate_array - a function to convert decimal number to binary.
 * @num: a number.
 *
 * Return: lenth of string.
 */

int *generate_array(int num)
{
	int *arr_num;
	int i = 2;
	int n = 4;

	arr_num = malloc(sizeof(int));
	if (num <= 1)
	{
		arr_num[0] = 1;
		return (arr_num);
	}
	while (n <= num)
	{
		n *= 2;
		i++;
	}

	arr_num = realloc(arr_num, i * sizeof(int));
	for (int j = 1; j <= i; j++)
	{
		n /= 2;
		arr_num[j - 1] = n;
	}
	return (arr_num);
}

/**
 * get_arr_len - a function to get array lenght.
 * @arr: a ponter to the array.
 *
 * Return: lenth.
 */

int get_arr_len(int *arr)
{
	int i = arr[0];
	int len = 0;

	while (i)
	{
		i /= 2;
		len++;
	}
	return (len);
}
