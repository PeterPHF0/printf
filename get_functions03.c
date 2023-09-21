#include "main.h"

/**
 * print_pointer - Prints f a pointer variable
 * @types: List a of arguments mvlmelr f'erm lkvwl
 * @buffer: array to handle print
 * @flags:  vdfvsd Calculates active flags
 * @width: get widt jknjk knmlkh
 * @precision: Precision
 * @size: Size sp jmldkv fier
 * Return: Number of charjoibn rmglore s printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}


/**
 * print_non_printable - Prin odes in hexa of non printable chars
 * @types: argument
 * @buffer: Bufn k klm mv m  verv fer array to handle print
 * @flags:  Calculates active flags kmkl ol lkbef
 * @width: get
 * @precision: Precision specific m lrmgl ovb epm ation
 * @size: Size specifier olmbelr
 * Return: Number ohjvb kgmn mbeb lmm mf chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int d = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[d] != '\0')
	{
		if (is_printable(str[d]))
			buffer[d + offset] = str[d];
		else
			offset += append_hexa_code(str[d], buffer, d + offset);

		d++;
	}

	buffer[d + offset] = '\0';

	return (write(1, buffer, d + offset));
}


/**
 * print_reverse - Prints reverse string mm mdvmwerlvw.
 * @types: Lista of arguments nowemwemf emfwefm
 * @buffer: Buffer array to handle print movwemvw
 * @flags:  Calculates active wovmweokf flags
 * @width: get width omvemrwfg
 * @precision: Preci jln klm sion specification
 * @size: Sizev mewldm
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int c, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (c = 0; str[c]; c++)
		;

	for (c = c - 1; c >= 0; c--)
	{
		char z = str[c];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Prin in rot13.
 * @types: Lista of a fwerrguments
 * @buffer: Buffer array t dvmlm o handle print
 * @flags:  Calculates acti
 * ve flags
 * @width: get width m wefm
 * @precision: Precision specification
 * @size: Size specifvsdier
 * Return: Numbers of ch ve evlars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char z;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				z = out[j];
				write(1, &z, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			z = str[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

