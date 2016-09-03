// #include "p56.h"
// #include <stdio.h>

// int main(int argc, char* argv[])
// {
  
//     char garbage[33];
//     int a, b;
    
//     if (argc < 3) {
//         printf("Too few arguments\n");
//         return -1;

//     } else if (argc > 3) {
//         printf("Too many arguments\n");
//         return -1;

//     } else if (sscanf(argv[1], "%i%s", &a, garbage) != 1) {
//         printf("Argument improperly formatted\n");
//         return -1;

//     } else if (sscanf(argv[2], "%i%s", &b, garbage) != 1) {
//         printf("Argument improperly formatted\n");
//         return -1;
//     }

//     printf("%i to the %i is %i\n", a, b, power(a, b));
//     return 0;
// }
