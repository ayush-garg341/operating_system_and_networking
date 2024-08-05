#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void clear_input_buffer() {
    int ch;
    // getchar reads the next character from the standard input and returns it as an int. If there are no more characters to read (e.g., at end-of-file), it returns EOF.
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(int argc, char *argv[])
{
    int option;
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Take input from user whether to insert or search
    while(1){
        printf("Select an option 1 or 2 \n 1 - Insert \n 2 - search:\n ");
        // scanf ignores whitespaces which is very convenient because we do not need to implement a function to strip the whitespace characters.
        scanf("%d", &option);

        // Input buffer contains newline character which will read by getline. To avoid that use below fn.
        clear_input_buffer();
        if(option == 1){
            // do insert and append into a file
            char *key = NULL;
            size_t len = 0;
            ssize_t read;
            puts("Enter key:");
            read = getline(&key, &len, stdin);
            if (read != -1) {
                // Remove newline character if present
                key[strcspn(key, "\n")] = 0;
            }

            puts("Enter value:");
            char *val = NULL;
            size_t val_len = 0;
            read = getline(&val, &val_len, stdin);

            if (read != -1) {
                // Remove newline character if present
                val[strcspn(val, "\n")] = 0;
            }

            int total_len = strlen(key) + strlen(val) + 2;

            // Allocate memory for the result string
            char *result;
            result = (char *)malloc(total_len * sizeof(char));
            if (result == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            // Copy the first string
            strcpy(result, key);

            // Append the colon
            strcat(result, ":");

            // Append the second string
            strcat(result, val);

            // Initialize the result string to be empty
            result[total_len-1] = '\n';

            // Print the resulting string
            printf("Concatenated string: %s\n", result);

            fprintf(file, "%s", result);

            // TODO: Save the address of key in hash map

            // Free the allocated memory
            free(result);

        }
        else if(option == 2){
            // do search using hash index
            printf("Currently not implemented\n");

            // TODO: Get the address of key from hash map and seek in file.
        }
        else {
            // Close the file
            fclose(file);
            printf("Invalid input");
            exit(0);
        }
    }
}

// getchar is often used in a loop to clear the input buffer of unwanted characters. This is especially useful after using scanf to ensure the input buffer is clean before the next input operation.
