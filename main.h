#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
int _puts(const char *str);
int _itoa(int num, char *buffer);
int _itoa_binary(unsigned int num, char *buffer);
int _itoa_unsigned(unsigned int num, char *buffer);
int _itoa_octal(unsigned int num, char *buffer);
int _itoa_hex(unsigned int num, char *buffer, int uppercase);

#endif /* MAIN_H */
