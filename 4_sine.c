// Perform series approximation of sin(x^2) using a single loop

#include <stdio.h>
#include <stdint.h>     
#include <inttypes.h>

// Period of sin(z), a floating-point value
#define TWO_PI 6.2831852f

int main() {
        printf("                                 a\n");
        printf("Sine of x^2 function -- ");
        printf("sin(x^2) = Σ [(-1)^n * x^(4n+2) / (2n+1)!]\n");
        printf("                                n=0\n");

        // Capture and validate input. a is cast to uint32_t after validation
        int a_raw;      // For checking that input a is valid
        uint32_t a;     // For storing a after casting
        float x;        // 32-bit single-precision float
        while (1) {
                printf("Enter a,x such that a is a non-zero positive integer ");
                printf("and x is any integer or decimal number.\n\n");
                printf("a = ");
                scanf("%d", &a_raw);
                printf("x = ");
                scanf("%f", &x);

                // Prompt again if input is invalid
                if (a_raw <= 0) {
                        fprintf(stderr, "\nInput invalid. ");
                        continue;
                }

                a = (uint32_t)a_raw;
                break;
        }

        // Reduce the range of x^2 with identity sin(z) = sin(z mod (2*pi)). 
        // Mod loses the decimal places when used on floats, so we will instead 
        // use the remainder formula r = z - (int)(z/(2*pi)) * (2*pi).
        float z = x*x;   // Grab sin()'s argument
        float z_mod_2pi = z - (int)(z / TWO_PI) * TWO_PI; 

        // Perform the calculation in a single loop
        float term = z_mod_2pi; // term_0 is x^(4(0)+2) / (2(0)+1)! = x^2 / 1
        float sum = term;       // Add term_0 to the sum and start loop at 1
        for (uint32_t n = 1; n <= a; n++) {
                // Calculate the next term to add.
                term *= (-1) * z_mod_2pi * z_mod_2pi /
                        ((2.0f*(n-1) + 2) * (2.0f*(n-1) + 3));

                // Add the new term to the sum
                sum += term;
        }

        // Show the answer
        printf("    sin(%f^2) = %f\n\n", x, sum);

        return 0;
}