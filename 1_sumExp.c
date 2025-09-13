// Morgan Williams - mtw0067
// CSCE 2610.001

// PA1-Program 1: Perform summation of an exponential function, using 32-bit 
// unsigned integers

#include <stdio.h>

#include <stdint.h>     
#include <inttypes.h>   

int main() {
        printf("                                                    a\n");
        printf("Problem 1: Summation of exponential function -- ");
        printf("y = Σ (a^n - b)\n");
        printf("                                                   n=1\n");
        
        // Capture and verify input
        uint32_t a, b;
        while (1) {
                printf("Enter a and b such that (0 < b < a < 10).\n\n");
                printf("a = ");
                scanf("%" PRIu32, &a);
                printf("b = ");
                scanf("%" PRIu32, &b);

                // Prompt again if input is invalid
                if (a == 0 || b == 0 || a >= 10 || a < b) {
                        fprintf(stderr, "\nInput invalid. ");
                        continue;
                }

                break;
        }

        // Perform the calculation in a single loop
        uint32_t y = 0, a_pow_n = 1;            // The sum and a^n
        for (uint32_t n = 1; n <= a; n++) {
                // Perform calculations for this term of the series
                a_pow_n *= a;
                uint32_t term = a_pow_n - b;

                // Add term to the sum
                y += term;
        } 

        // Read back the input and show the answer
        printf("        %" PRIu32 "\n", a);
        printf("    y = Σ (%" PRIu32 "^n - %" PRIu32 ") = ", a, b);
        printf("%" PRIu32 "\n", y);
        printf("       n=1\n\n");        

        return 0;
}