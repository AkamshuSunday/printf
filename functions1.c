#include "main.h"

/* TO PRINT UNSIGNED NUMBER */
int print_unsigned(va_list types, char buffer[],
	/* flags, width, precision, size: Formatting specifications */
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	/* Convert size if necessary */
	num = convert_size_unsgnd(num, size);

	/* Handle the case when the number is 0 */
	if (num == 0)
		buffer[i--] = '0';

	/* Null-terminate the buffer */
	buffer[BUFF_SIZE - 1] = '\0';

	/* Extract digits from the number and store in the buffer */
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	/* Write the unsigned number to the buffer and handle formatting */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* TO PRINT UNSIGNED NUMBER IN OCTAL  */
int print_octal(va_list types, char buffer[],
	/* flags, width, precision, size: Formatting specifications */
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	/* UNUSED macro to avoid compilation warnings */
	UNUSED(width);

	/* Convert size if necessary */
	num = convert_size_unsgnd(num, size);

	/* Handle the case when the number is 0 */
	if (num == 0)
		buffer[i--] = '0';

	/* Null-terminate the buffer */
	buffer[BUFF_SIZE - 1] = '\0';

	/* Extract digits from the number and store in the buffer */
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	/* Add '0' prefix for non-zero values if the '#' flag is present */
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	/* Write the unsigned number in octal to the buffer and handle formatting */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* TO PRINT UNSIGNED NUMBER IN HEXADECIMAL */
int print_hexadecimal(va_list types, char buffer[],
	/* flags, width, precision, size: Formatting specifications */
	int flags, int width, int precision, int size)
{
	/* Call the generic print_hexa function for lowercase hexadecimal */
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
int print_hexa_upper(va_list types, char buffer[],
	/* flags, width, precision, size: Formatting specifications */
	int flags, int width, int precision, int size)
{
	/* Call the generic print_hexa function for uppercase hexadecimal */
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*TO PRINT HEXX NUM IN LOWER OR UPPER */
int print_hexa(va_list types, char map_to[], char buffer[],
	/* flags, width, precision, size: Formatting specifications */
	int flags, char flag_ch, int width, int precision, int size)
{
	/* Initialize variables */
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	/* UNUSED macro to avoid compilation warnings */
	UNUSED(width);

	/* Convert size if necessary */
	num = convert_size_unsgnd(num, size);

	/* Handle the case when the number is 0 */
	if (num == 0)
		buffer[i--] = '0';

	/* Null-terminate the buffer */
	buffer[BUFF_SIZE - 1] = '\0';

	/* Extract digits from the number and map to the specified characters */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	/* Add '0x' or '0X' prefix for non-zero values if the '#' flag is present */
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	/* Write the hexadecimal number to the buffer and handle formatting */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

