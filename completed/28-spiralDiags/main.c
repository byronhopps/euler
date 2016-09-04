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

    } else if (sscanf(argv[1], "%i%s", &size, garbage) != 1) {
        printf("Argument improperly formatted\n");
        return -1;

    } else if (size % 2 != 1) {
        printf("Argument must be odd\n");
        return -1;
    }

    int i, j, sum = 1, diag = 1;
    for(i = 3; i <= size; i += 2) {
        for(j = 0; j < 4; j++) {

            diag += i - 1;
            sum += diag;
        }
    }

    printf("Sum of all the diagonal numbers is %i\n", sum);
    return 0;
}
