// Print the number of words, vowels, letters, and digits in a c-string.
// Determination of character types is done using bit manipulation 
// and characters' integer ASCII values.

#include <stdio.h>              // For capturing input and displaying output
#include <stdint.h>             // For explicit unsigned 32-bit int (uint32_t)
#include <stdbool.h>

// Define baseline values for mapping to ASCII values
#define BASE_DGT        '0'     // ASCII 48
#define BASE_UC         'A'     // ASCII 65
#define BASE_LC         'a'     // ASCII 97

// Define limits for character types         
#define MAX_DGT   10            // Number of possible digits
#define MAX_ALPHA 26            // Number of letters in the alphabet

// Macros to set bits in the vowel mask
#define VOWEL_A (1u << 0)       // 'A' or 'a'
#define VOWEL_E (1u << 4)       // 'E' or 'e'
#define VOWEL_I (1u << 8)       // 'I' or 'i'
#define VOWEL_O (1u << 14)      // 'O' or 'o'
#define VOWEL_U (1u << 20)      // 'U' or 'u'

// Checks--since values are unsigned, underflow will result in a value over max

// c is a digit
#define IS_DIGIT(c)             ((unsigned)((c) - BASE_DGT) < MAX_DGT)
// c is an uppercase letter
#define IS_UPPER(c)             ((unsigned)((c) - BASE_UC) < MAX_ALPHA)
// c is a lowercase letter
#define IS_LOWER(c)             ((unsigned)((c) - BASE_LC) < MAX_ALPHA)
// c is a letter
#define IS_ALPHA(c)             (IS_UPPER((c)) || IS_LOWER((c)))
// c is a vowel--(vowel bit mask) AND (c normalized to the 32-bit mask) != 0
#define IS_VOWEL(c) ( \
        (IS_UPPER((c)) && (vowelMask & (1u << (unsigned)((c) - BASE_UC)))) || \
        (IS_LOWER((c)) && (vowelMask & (1u << (unsigned)((c) - BASE_LC)))) \
)

#define LEN_MAX 255             // Max length of input string

int main() {
        printf("Enter a sentence with max 255 characters\n> ");
        fflush(stdout);

        char str[LEN_MAX + 1] = {'\0'};         // Container for the sentence
        int pos = 0;                            // Length of the sentence
        int words = 0, vowels = 0, alphas = 0, digits = 0;
        
        // Define the vowel bit mask as an unsigned 32-bit integer
        uint32_t vowelMask = VOWEL_A | VOWEL_E | VOWEL_I | VOWEL_O | VOWEL_U;

        // Capture input and categorize its characters
        char curr = ' ';
        char next = '\0';
        bool inNum = false;
        while ((next = getchar()) != EOF) {
                // Exit loop immediately at newline, without adding the newline
                if (next == '\n') {
                        inNum = false;
                        break;
                }

                // Words can contain digits, but must have at least one letter
                if (IS_DIGIT(curr) && inNum) {
                        if (IS_ALPHA(next)) {
                                inNum = false;
                                words++;
                        }
                }

                // Check for potential new word
                if (curr == ' ' && next != ' ') {
                        if (IS_DIGIT(next)) {
                                inNum = true;
                        } else {
                                words++;
                        }
                }

                str[pos++] = next;
                curr = next;

                vowels += IS_VOWEL(curr);
                alphas += IS_ALPHA(curr);
                digits += IS_DIGIT(curr);
        }

        inNum = false;
        str[pos] = '\0';

        // Read back input and report totals
        printf("\n    You entered: \"%s\"\n", str);
        printf(
                "    words = %d ; vowels = %d ; alphas = %d ; digits = %d\n\n",
                words, vowels, alphas, digits
        );

        return 0;
}