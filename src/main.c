#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void decimal_to_binary(int n) {
    if (n > 1) {
        decimal_to_binary(n >> 1);
    }
    putchar((n & 1) ? '1' : '0'); // take the least significant bit
}

int main(int argc, char **argv) {
    if (argc !=2) {
        printf("Usage %s <number> <option>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    char *endptr; // ptr for error handling
    long number = strtol(argv[1], &endptr, 10); // convert string to long int

    // verify if valid input is passed
    if (endptr == argv[1]) {
        printf("ERROR: Please input a valid number\n");
        exit(EXIT_SUCCESS);
    }

    // number limit error handling, make sure usr inputs valid length
    if (strlen(argv[1]) > 11) {
        printf("ERROR: Number exceeds the maximum length allowed (must be between 0 and %d)\n", INT_MAX);
        exit(EXIT_SUCCESS);
    }

    if (*endptr != '\0') {
        printf("ERROR: invalid input, non-numeric characters detected\n");
        exit(EXIT_FAILURE);
    }
    
    // call to the function to print the binary result
    decimal_to_binary((int)number);
    putchar('\n'); // newline so it doesn't get fucked
    
    exit(EXIT_FAILURE);
}