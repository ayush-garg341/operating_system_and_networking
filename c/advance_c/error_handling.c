#include<stdio.h>
#include<assert.h>
#include<errno.h>
#include<string.h>

int main(void)
{
    FILE *f = fopen("c/advance_c/error_handling.c", "r");
    if(f == NULL)
    {
        // printf("%d\n", errno);
        // perror(NULL);
        // perror("HEllo");

        printf("%d: %s\n", errno, strerror(errno));
        return 1;
    }

    char c;
    while((c = fgetc(f)) != EOF)
        fputc(c, stdout);

    return 0;
}


