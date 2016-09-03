#include <stdio.h>
#include <gmp.h>

int main() {

    FILE* numbers = fopen("numbers.txt", "r");

    mpz_t sum;
    mpz_init(sum);

    mpz_t new;
    mpz_init(new);

    while (mpz_inp_str(new, numbers, 10) != 0) {
        mpz_add(sum, sum, new);
    }

    mpz_out_str(NULL, 10, sum);

    fclose(numbers);
    return 0;
}
