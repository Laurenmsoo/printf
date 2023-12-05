#include "main.h"

/**
 * _itoa - Convert integer to string.
 * @num: The integer to convert.
 * @buffer: The buffer to store the result.
 * Return: The length of the string.
 */
int _itoa(int num, char *buffer)
{
	int i = 0;
	int j;
	int is_negative = 0;

    /* Handle the case of negative numbers*/
	if (num < 0)
	{
        is_negative = 1;
        num = -num;
    }

    /* Handle the case of zero separately*/
    if (num == 0)
    {
        buffer[i++] = '0';
    }

    /* Convert the number to string in reverse order*/
    while (num != 0)
    {
        int digit = num % 10;
        buffer[i++] = digit + '0';
        num /= 10;
    }

    /* Add the negative sign if necessary*/
    if (is_negative)
    {
        buffer[i++] = '-';
    }

    /* Reverse the string in-place*/
    for (j = 0; j < i / 2; j++)
    {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (i);
}

/**
 * _itoa_binary - Convert unsigned integer to binary.
 * @num: The unsigned integer to convert.
 * @buffer: The buffer to store the result.
 * Return: The length of the binary string.
 */
int _itoa_binary(unsigned int num, char *buffer)
{
    int i = 0;
    int j, bit;
    char temp;


    /* Handle the case of zero separately*/
    if (num == 0)
    {
        buffer[i++] = '0';
    }

    /* Convert the number to binary in reverse order*/
    while (num != 0)
    {
        bit = num % 2;
        buffer[i++] = bit + '0';
        num /= 2;
    }

    /* Reverse the string in-place*/
    for (j = 0; j < i / 2; j++)
    {
        temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (i);
}

/**
 * _itoa_unsigned - Convert unsigned integer to string.
 * @num: The unsigned integer to convert.
 * @buffer: The buffer to store the result.
 * Return: The length of the string.
 */
int _itoa_unsigned(unsigned int num, char *buffer){
	int i=0, digit, j = 0;
    char temp;

    /* Handle the case of zero separately*/
    if (num == 0) {
      buffer[i++] = '0';
    }

    /* Convert the number to string in reverse order*/
    while (num != 0) {
        digit = num % 10;
        buffer[i++] = digit + '0';
        num /= 10;
    }

    /* Reverse the string in-place*/
    for (j = 0; j < i / 2; j++) {
        temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (i);
}

/**
 * _itoa_octal - Convert unsigned integer to octal string.
 * @num: The unsigned integer to convert.
 * @buffer: The buffer to store the result.
 * Return: The length of the octal string.
 */
int _itoa_octal(unsigned int num, char *buffer) {
    int i = 0,digit, j;
    char temp;

    /* Handle the case of zero separately*/
    if (num == 0) {
        buffer[i++] = '0';
    }

    /* Convert the number to octal in reverse order*/
    while (num != 0) {
        digit = num % 8;
        buffer[i++] = digit + '0';
        num /= 8;
    }

    /* Reverse the string in-place*/
    for (j = 0; j < i / 2; j++) {
        temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return i;
}

/**
 * _itoa_hex - Convert unsigned integer to hexadecimal string.
 * @num: The unsigned integer to convert.
 * @buffer: The buffer to store the result.
 * @uppercase: Whether to use uppercase letters in the hexadecimal representation.
 * Return: The length of the hexadecimal string.
 */
int _itoa_hex(unsigned int num, char *buffer, int uppercase) {
    int i = 0, digit, j;
    char temp;

    /* Handle the case of zero separately*/
    if (num == 0) {
        buffer[i++] = '0';
    }

    /* Convert the number to hexadecimal in reverse order*/
    while (num != 0) {
        digit = num % 16;
        buffer[i++] = (digit < 10) ? digit + '0' : digit - 10 + (uppercase ? 'A' : 'a');
        num /= 16;
    }

    /* Reverse the string in-place*/
    for (j = 0; j < i / 2; j++) {
        temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (i);
}
