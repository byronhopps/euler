#include <stdio.h>

int main (int argc, char* argv[])
{

    char garbage[32];
    int size;

    if (argc < 2) {
        printf("Too few arguments\n");
        return -1;

    } else if (argc > 2) {
        printf("Too many arguments\n");
        return -1;

    } else if (sscanf(argc[1], "%i%s", &size, garbage) != 1) {
        printf("Argument improperly formatted\n");
        return -1;

    } else if (size % 2 != 1) {
        printf("Argument must be odd\n");
        return -1;
    }

    int i, sum;
    for(i = 3; i <= size; i += 2) {
        sum += 4*(size-1);
    }

    printf("Sum of all the diagonal numbers is %i\n", sum);
    return 0;
}
