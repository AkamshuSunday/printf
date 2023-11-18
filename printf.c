#include "main.h"

/* Function to print the contents of the buffer and reset the index */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom implementation of printf function.
 * @format: Format string with optional specifiers.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    /* Check if the format string is not NULL */
    if (format == NULL)
        return (-1);

    /* Initialize the variable argument list */
    va_start(list, format);

    /* Loop through the characters in the format string */
    for (i = 0; format && format[i] != '\0'; i++)
    {
        /* If the character is not '%', add it to the buffer */
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            
            /* Check if the buffer is full, and print its contents if so */
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            printed_chars++;
        }
        else
        {
            /* Print the buffer contents before handling the specifier */
            print_buffer(buffer, &buff_ind);

            /* Get the flags, width, precision, and size for the specifier */
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            
            /* Move to the next character after '%' */
            ++i;

            /* Handle the specifier and get the number of characters printed */
            printed = handle_print(format, &i, list, buffer,
                                   flags, width, precision, size);

            /* Check for error during handling and return -1 if needed */
            if (printed == -1)
                return (-1);

            printed_chars += printed;
        }
    }

    /* Print the remaining contents of the buffer */
    print_buffer(buffer, &buff_ind);

    /* End the variable argument list */
    va_end(list);

    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 * @buffer: Array of characters to be printed.
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    /* Check if the buffer contains any characters */
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    /* Reset the buffer index */
    *buff_ind = 0;
}
