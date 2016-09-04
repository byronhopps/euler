#include <stdio.h>
#include "p31.h"

int main (int argc, char* argv[])
{

    char garbage[32];
    int total;

    if (argc < 2) {
        printf("Too few arguments\n");
        return -1;

    } else if (argc > 2) {
        printf("Too many arguments\n");
        return -1;

    } else if (sscanf(argv[1], "%i%s", &total, garbage) != 1) {
        printf("Argument improperly formatted\n");
        return -1;
    }

    printf("There are %i ways to make %ip\n", countCoins(0, total), total);

    return 0;
}
