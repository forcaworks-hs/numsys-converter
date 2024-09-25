#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void decimal_to_binary(int n) {
    if (n > 1) {
        decimal_to_binary(n >> 1);
    }
    putchar((n & 1) ? '1' : '0'); // take the least significant bit
}

int main(int argc, char **argv) {
    if (argc !=2) {
        printf("Usage %s <number> <option>\n", argv[0]);
        return 1;
    }

    char *endptr; // pointer for error handling
    long number = strtol(argv[1], &endptr, 10); // convert string to long int

    // check if conversion is successful, if not it errors
    if (*endptr != '\0' || endptr == argv[1] || number < 0 || number > INT_MAX) {
        printf("ERROR: please input a valid number (cannot be negative)\n");
        return 1;
    }

    return 0;
}


