/* putchar_puts.c */

#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _puts(char *str)
{
    int count = 0;

    while (*str)
    {
        count += _putchar(*str);
        str++;
    }

    return count;
}

