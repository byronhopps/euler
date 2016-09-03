#include <stdlib.h>
#include <stdio.h>
#include "p19.h"

#define NUM_ARGS 1

int main(int argc, char* argv[]) {

    if (argc > NUM_ARGS) {
        fprintf(stderr, "Too many arguments");
        exit(-1);
    } else if (argc < NUM_ARGS) {
        fprintf(stderr, "Too few arguments");
        exit(-1);
    }

    // Call program
    printf("%i Sundays fell on the first of the month in the "
            "20th century\n", sundayCount());

    return 0;
}
