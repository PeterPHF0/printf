#include "main.h"

/**
 * print_unsigned - Printsjkkjnjk  an unsigned number
 * @types: List a of ahbjhrgumentnlk s
 * @buffer: Buffer handle printf
 * @flags:  Calculates active flagbjkj mll ll s
 * @width: get widthn lk
 * @precision: Precision knl specification
 * @size: Size specifier klkm
 * Return:  chars prinjklvbdf ted.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints  number in octal notation
 * @types: Lista of argumentsfbdf sdgsd
 * @buffer: Bufffvbdf er array to handle print
 * @flags:  Calculatesdfsg jj  active flags
 * @width: get widthfb sdvg sdv sdv
 * @precision: Precision specificatfdb ion
 * @size: Size specifier ngbdfdf sfdvbdf
 * Return: Number of chars printeddfb bdf
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[c--] = '0';

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - an unsignefwed number in hexadecimal notation
 * @types: Lista gumentseefwv weve
 * @buffer: Bufr array to handle printvwev
 * @flags:  Cculates active flfwev ewweags
 * @width: get widthdvsdv dvefwe
 * @precision: Pcision ssdvsdpecification
 * @size: Size spe cifidvsder
 * Return: Numbv  chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned in r hexadecimal notation
 * @types: Lista ofbdf arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculatesbdfb active flags
 * @width: get width fg r grr fg fddf
 * @precision: Precision sgvb fd pecif  rgregication
 * @size: Size specifier  fdfogrm.f
 * Return: Number of chars printed dlbml  reg rgeger rg
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexade in lower or upper
 * @types: Lista of argumenbe m reger gts
 * @map_to: Array of values the number to
 * @buffer: Bubdfb erg ger g re ergffer array to handle print
 * @flags:  Calculates active f kjngb kl oj pllags
 * @flag_ch: Calculates active
 * @width: get width few ff
 * @precision: Precision ification mvldfmv
 * @size: Size specifier mklgrvmwrl
 * @size: Size specification fvl lmvrwvmwepf
 * Return: Number of chars printed md;vlmwefl
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[c--] = flag_ch;
		buffer[c--] = '0';
	}

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}

