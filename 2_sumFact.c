// Perform summation of a factorial function with a single loop

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
        printf("                                       a\n");
        printf("Summation of factorial function -- ");
        printf("y = Σ (n! + b)\n");
        printf("                                      n=1\n");

        // Capture and verify input
        uint64_t a, b;
        while (1) {
                printf("Enter a and b such that (0 < a,b < 20).\n\n");
                printf("a = ");
                scanf("%" PRIu64, &a);
                printf("b = ");
                scanf("%" PRIu64, &b);

                // Prompt again if input is invalid
                if (a == 0 || b == 0 || a >= 20 || b >= 20) {
                        fprintf(stderr, "\nInput invalid. ");
                        continue;
                }

                break;
        }

        // Prform the calculation in a single loop
        uint64_t y = 0, n_fact = 1;             // The sum and n!
        for (uint64_t n = 1; n <= a; n++) {
                // Perform calculations for this term of the series
                n_fact *= n;
                uint64_t term = n_fact + b;

                // Add term to the sum
                y += term;
        }

        // Read back the input and show answer
        printf("        %" PRIu64 "\n", a);
        printf("    y = Σ (n! + %" PRIu64 ") = %" PRIu64 "\n", b, y);
        printf("       n=1\n\n");

        return 0;
}