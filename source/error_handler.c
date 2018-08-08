#include "../includes/error_handler.h"

void standard_error(char *file, int line, int error_number)
{
    if (errno) {
            fprintf(stderr, "Error in %s at line %d: %s.\n", file, line, strerror(error_number));
    } else {
        fprintf(stderr, "Unknown error in %s at line %d.\n", file, line);
    }

    exit(EXIT_FAILURE);
}

void realloc_pointer_array_error(void **array, size_t length, char *file, int line, int error_number)
{
    // Cleanup memory from previously allocated block
    for (size_t i = 0; i < length; i++) {
        free(array[i]);
    }

    free(array);

    // Throw standard error
    standard_error(file, line, error_number);
}