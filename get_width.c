#include "main.h"

/**
 * get_width - Calculates the width for printing.
 *
 * @param format: Formatted string in which to print the arguments.
 * @param i: Current index in the format string.
 * @param list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
    /* Initialize variables */
    int curr_i;
    int width = 0;

    /* Loop through the format string to find width information */
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            /* Accumulate digits to calculate width */
            width *= 10;
            width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            /* Handle '*' as a width specifier, get value from arguments */
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            /* Stop if non-digit and non-'*' character is encountered */
            break;
        }
    }

    /* Update the index */
    *i = curr_i - 1;

    return width;
}

