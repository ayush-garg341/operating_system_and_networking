#include <stdio.h>

int main() {
    int option;
    while (1) {
        printf("Enter an option: ");
        if (scanf("%d", &option) != 1) {
            // Clear the input buffer if invalid input is encountered
            while (getchar() != '\n');
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }
        printf("option = %d\n", option);
    }
    return 0;
}
