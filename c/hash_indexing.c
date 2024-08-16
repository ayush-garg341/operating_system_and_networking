#include "hash_table/ht.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

void clear_input_buffer() {
    int ch;
    // getchar reads the next character from the standard input and returns it as an int. If there are no more characters to read (e.g., at end-of-file), it returns EOF. It is a blocking call and waits for an input character if there is nothing left in input buffer.
    // Input buffer is cleared once loop executes.
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(int argc, char *argv[])
{
    ht *table = ht_create();
    int option;
    int long write_pointer;
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Take input from user whether to insert or search
    while(1){
        printf("Select an option 1 or 2 \n 1 - Insert \n 2 - search:\n ");
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }

        printf("option = %d\n", option);
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

            write_pointer = ftell(file);
            fprintf(file, "%s", result);
            fflush(file);

            printf("write pointer position = %ld\n", write_pointer);

            ht_set(table, key, (void *)(intptr_t)write_pointer);

            // Free the allocated memory
            free(result);
            free(key);
            free(val);

        }
        else if(option == 2){
            char ch;
            char *read_key = NULL;
            size_t read_key_len = 0;
            size_t read_size;
            int long read_pointer;

            // do search using hash index
            puts("Enter the key which you want to read:");

            puts("Enter key:");
            read_size = getline(&read_key, &read_key_len, stdin);
            printf("read key = %s\n", read_key);
            if(read_size != -1){
                // Remove newline character if present
                read_key[strcspn(read_key, "\n")] = 0;
            }
            read_pointer = (long int)(intptr_t)ht_get(table, read_key);
            printf("read pointer position === %ld\n", read_pointer);

            // Seek to a specific position in the file
            if (fseek(file, read_pointer, SEEK_SET) != 0) {
                perror("Error seeking in file");
                fclose(file);
                ht_destroy(table);
                return -1;
            }

            // Read and print characters until a newline or EOF is encountered
            while ((ch = fgetc(file)) != EOF && ch != '\n') {
                putchar(ch);
            }

            if (ch == '\n') {
                putchar('\n');
            }

        }
        else {
            // Close the file
            fclose(file);
            printf("Invalid input");
            ht_destroy(table);
            exit(0);
        }
    }
}

// getchar is often used in a loop to clear the input buffer of unwanted characters. This is especially useful after using scanf to ensure the input buffer is clean before the next input operation.
// compiling it with gcc -o hash.out hash_indexing.c hash_table/ht.c
