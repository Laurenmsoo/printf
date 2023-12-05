#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _puts - Write a string to the standard output.
 * @str: The input string.
 * Return: The number of characters written.
 */
int _puts(const char *str)
{
	return (write(1, str, _strlen(str)));
}

/**
 * _putchar - Write a character to the standard output
 * @c: The character to be written
 * Return: On success, return the number of characters written. On error, return -1.
 */

int _putchar(char c) {
    return write(1, &c, 1);
}
