#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int read_memory(pid_t pid, off_t address, void *buf, size_t size)
{
    char filename[30];
    sprintf(filename, "/proc/%d/mem", pid);
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1;

    if (lseek(fd, address, SEEK_SET) == -1)
    {
        close(fd);
        return -1;
    }

    int read_bytes = read(fd, buf, size);
    close(fd);
    return read_bytes;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <pid> <address>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    off_t address = strtol(argv[2], NULL, 0);
    int data;

    if (read_memory(pid, address, &data, sizeof(data)) == sizeof(data))
    {
        printf("Data at %p: %x\n", (void *)address, data);
    }
    else
    {
        perror("Failed to read memory");
    }

    return 0;
}
