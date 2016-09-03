#include <stdio.h>

int main (int argc, char* argv[])
{

    // TODO: Add fugitive.vim, and learn how to use it

    char garbage[32];
    int size;

    if (argc < 2) {
        printf("Too few arguments\n");
        return -1;

    } else if (argc > 2) {
        printf("Too many arguments\n");
        return -1;

    } else if (sscanf(argv[1], "%i%s", &size, garbage) != 1) {
        printf("Argument improperly formatted\n");
        return -1;

    } else if (size % 2 != 1) {
        printf("Argument must be odd\n");
        return -1;
    }

    return 0;
}
