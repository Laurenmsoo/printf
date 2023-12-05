#include "main.h"
/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;  /* To keep track of the number of characters printed */
	va_list args;
	int buffer_index = 0;
	char buffer[1024];
	int len;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;  /* Move to the next character after '%'*/

            /* Handle conversion specifiers*/
			switch (*format)
			{
				case 'c':
					{
						char ch = (char)va_arg(args, int);
						buffer[buffer_index++] = ch;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							buffer[buffer_index++] = *str;
							str++;
						}
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int len = _itoa(num, buffer + buffer_index);
						buffer_index += len;
						break;
					}
				case 'u':
					{
						unsigned int num;
						num = va_arg(args, unsigned int);
						len = _itoa_unsigned(num, buffer + buffer_index);
						buffer_index += len;
						break;
					}
				case 'o':
					{
						unsigned int num = va_arg(args, unsigned int);
						int len = _itoa_octal(num, buffer + buffer_index);
						buffer_index += len;
						break;
					}
				case 'x':
				case 'X':
					{
						unsigned int num = va_arg(args, unsigned int);
						int len = _itoa_hex(num, buffer + buffer_index, (*format == 'X'));
						buffer_index += len;
						break;
					}
					case 'b': {
            unsigned int num = va_arg(args, unsigned int);
                    char buffer[32];  /*Assuming a 32-bit unsigned integer */
                    int len = _itoa_binary(num, buffer);
                    count += write(1, buffer, len);
                    break;
                }
				case '%':
					buffer[buffer_index++] = '%';
					break;
				default:
                    /* Handle unsupported conversion specifiers or other characters after '%' */
					buffer[buffer_index++] = '%';
					buffer[buffer_index++] = *format;
			}
		}
		else
		{
            /* Regular character, add it to the buffer */
			buffer[buffer_index++] = *format;
		}

        /* Check if the buffer is full, and if so, write its contents*/
		if (buffer_index >= (int)(sizeof(buffer) - 1))
		{
			count += write(1, buffer, buffer_index);
			buffer_index = 0;
		}
		format++;  /* Move to the next character in the format string */
	}

    /* Write any remaining characters in the buffer*/
	if (buffer_index > 0)
	{
		count += write(1, buffer, buffer_index);
	}
	va_end(args);
	return (count);
}
