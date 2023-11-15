#include "main.h"

/**
 * get_size - Determines the size specifier for casting the argument.
 * @format: The format string that guides the argument printing.
 * @i: Current index in the format string.
 *
 * Returns: The size specifier (S_LONG or S_SHORT).
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    /* Check if 'l' denotes a long size specifier.*/
    if (format[curr_i] == 'l')
        size = S_LONG;
    /* Check if 'h' denotes a short size specifier.*/
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    /* If no size specifier is found, update the index accordingly.*/
    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return size;
}

