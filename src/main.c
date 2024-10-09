#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// decimal to hex logic
void decimal_to_hex(int n) {
        if (n < 0) {
            printf("ERROR: Cannot convert negative numbers to hexadecimal\n");
            return;
        }
        printf("0x%x", n); // print number into hex format
}


// decimal to binary logic
void decimal_to_binary(int n) {
    if (n > 1) {
        decimal_to_binary(n >> 1);
    }
    putchar((n & 1) ? '1' : '0'); // take the least significant bit
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        printf("Usage %s <number> <option>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *endptr; // ptr for error handling
    long number = strtol(argv[1], &endptr, 10); // convert string to long int


    // verify if valid input is passed
    if (endptr == argv[1]) {
        printf("ERROR: Please input a valid number\n");
        exit(EXIT_FAILURE);
    }

    // number limit error handling, make sure usr inputs valid length
    if (strlen(argv[1]) > 11) {
        printf("ERROR: Number exceeds the maximum length allowed (must be between 0 and %d)\n", INT_MAX);
        exit(EXIT_FAILURE);
    }

    // deny non-numeric characters input to usr
    if (*endptr != '\0') {
        printf("ERROR: Invalid input, non-numeric characters detected\n");
        exit(EXIT_FAILURE);
    }
    
      int option = 0; // Valor por defecto si no se proporciona opción
    if (argc == 3) {
        option = atoi(argv[2]); // Convertir solo si argv[2] existe
    }
    
    // call to the function to print the binary result
    decimal_to_binary((int)number);
    putchar('\n'); // newline so it doesn't get fucked


    exit(EXIT_SUCCESS);
}