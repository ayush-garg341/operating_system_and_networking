#include <stdio.h>

#include <stdio.h>

int main() {
    int option;
    int result;

    // Initialize the option with some value
    option = -1;

    while (1) {
        printf("Enter an option: ");
        result = scanf("%d", &option);
        if (result != 1) {
            printf("option when input not an integer = %d\n", option);
            // Clear the input buffer if invalid input is encountered
            while (getchar() != '\n'); // Consume invalid input until newline
            printf("Invalid input. Please enter an integer.\n");
        } else {
            printf("option when correct integer input = %d\n", option);
        }
    }

    return 0;
}

// scanf ignores whitespaces which is very convenient because we do not need to implement a function to strip the whitespace characters.
// Successful read from scanf returns 1 else 0. For 'abc' it will return 0 and for 2, 3, 4 it will return 1.
// When scanf is unable to parse an integer due to invalid input (such as alphabets), it does not modify the variable where the integer is supposed to be stored. 
// The variable retains its previous value, and scanf leaves the invalid input in the buffer.
// To clear the input buffer for invalid input, we use getchar().
