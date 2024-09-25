#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc !=2) {
        printf("Usage %s <number> <option>\n", argv[0]);
        return 1;
    }
    
    return 0;
}


