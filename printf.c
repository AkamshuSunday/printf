#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - print a string
 * @str: string argument
 *
 * Return: length of string
 */

int print_string(const char *str)
{
	unsigned int string_len = 0;

	while (str[string_len] != '\0')
	{
		string_len++;
	}
	write(1, str, string_len);
	return (string_len);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * @...: arguments
 *
 * Return: the number of characters printed excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int counter = 0;
	char c_args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c_args = va_arg(args, int);
					write(1, &c_args, 1);
					counter++;
					break;
				case 's':
					counter += print_string(va_arg(args, char *));
					break;
				case '%':
					write(1, format, 1);
					counter++;
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}

/**
 * _print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int _print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    if (n / 10)
        _print_number(n / 10);

    return _putchar(n % 10 + '0');
}



/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past '%' */
            switch (*format)
            {
            case 'c':
                count += _putchar(va_arg(args, int));
                break;
            case 's':
                count += _puts(va_arg(args, char *));
                break;
            case 'd':
            case 'i':
                count += _print_number(va_arg(args, int));
                break;
            case 'u':
                count += _print_unsigned(va_arg(args, unsigned int));
                break;
            case 'o':
                count += _print_octal(va_arg(args, unsigned int));
                break;
            case 'x':
                count += _print_hex(va_arg(args, unsigned int), 0);
                break;
            case 'X':
                count += _print_hex(va_arg(args, unsigned int), 1);
                break;
            case '%':
                count += _putchar('%');
                break;
            default:
                count += _putchar('%') + _putchar(*format);
                break;
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

/**
 * _print_unsigned - Prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int _print_unsigned(unsigned int n)
{
    if (n / 10)
        _print_unsigned(n / 10);

    return _putchar(n % 10 + '0');
}

/**
 * _print_octal - Prints an octal number
 * @n: The unsigned integer to print as octal
 *
 * Return: Number of characters printed
 */
int _print_octal(unsigned int n)
{
    if (n / 8)
        _print_octal(n / 8);

    return _putchar(n % 8 + '0');
}

/**
 * _print_hex - Prints a hexadecimal number
 * @n: The unsigned integer to print as hexadecimal
 * @uppercase: Flag to print uppercase letters (1) or lowercase (0)
 *
 * Return: Number of characters printed
 */
int _print_hex(unsigned int n, int uppercase)
{
    char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        _print_hex(n / 16, uppercase);

    return _putchar(hex_digits[n % 16]);
}

