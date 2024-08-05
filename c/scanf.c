#include<stdio.h>

int main(int argc, char* argv[]){
    int i;
    char c;

    scanf("%d", &i);
    printf("read: %d\n", i);

    printf("Let's check what is in the input buffer:");
    while (scanf("%c", &c) == 1) {
        printf("\nread from input buf: %d\n", c);
    }
}

// Input to functions
    // echo -e "5" | ./a.out
    // echo -e "5A" | ./a.out
    // echo -e "A5" | ./a.out
