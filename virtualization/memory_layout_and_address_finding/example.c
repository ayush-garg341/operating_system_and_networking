#include <stdio.h>
#include <unistd.h>

int global_var = 0x00112233;

int main(int argc, char *argv[])
{
    volatile int local_var = 0x44556677;
    volatile int change_me = 0x01;

    printf("Entry: global_var = 0x%08x :: local_var = 0x%08x\n", global_var, local_var);
    while(change_me)
    {
        sleep(2);
    }
    printf("Exit: global_var = 0x%08x :: local_var = 0x%08x\n", global_var, local_var);

    return 0;
}
