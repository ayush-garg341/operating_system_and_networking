#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

long get_data(pid_t child, long addr)
{
    long data = ptrace(PTRACE_PEEKDATA, child, addr, NULL);
    if (errno != 0)
    {
        fprintf(stderr, "ptrace PEEKDATA failed: %s\n", strerror(errno));
        return -1;
    }
    return data;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <pid> <address>\n", argv[0]);
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);
    long address = strtol(argv[2], NULL, 16);

    if (ptrace(PTRACE_ATTACH, target_pid, NULL, NULL) == -1)
    {
        perror("ptrace attach");
        return 1;
    }

    waitpid(target_pid, NULL, 0);
    long data = get_data(target_pid, address);
    printf("Data at %lx: %lx\n", address, data);

    ptrace(PTRACE_DETACH, target_pid, NULL, NULL);
    return 0;
}
