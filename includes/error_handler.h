#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void standard_error(char *file, int line, int error_number);

void realloc_pointer_array_error(void **array, size_t length, char *file, int line, int error_number);

#endif // ERROR_HANDLER_H_
