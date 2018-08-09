#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
 * @brief Outputs useful error message for a standard error with a given error number.
 * @param file The name of the file in which the error occured.
 * @param line The line at which the error occured.
 * @param error_number The error number (usually given by errno).
 */ 
void standard_error(char *file, int line, int error_number);

/**
 * @brief Special error handler for realloc. Also cleans up previously used memory.
 * When realloc fails, the original memory remains as it was before the call. Use this function
 * to deallocate that memory. It then calls standard_error to close the program with a useful
 * error message. 
 * @param array An array of pointers that could not be reallocated. Must be cast to void.
 * @param length The number of elements in the array.
 * @param file The name of the file where the error occured.
 * @param line The line of at which the error occured.
 * @param error_number The error number (usually given by errno).
 */
void realloc_pointer_array_error(void **array, size_t length, char *file, int line, int error_number);

#endif // ERROR_HANDLER_H_

