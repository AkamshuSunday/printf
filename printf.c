#include <unistd.h>
#include <stdarg.h>

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
