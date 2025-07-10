#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>

#define BUF_SIZE 30000  // Slightly less than 30KB

void print_error(char *prog_name, char *file_name)
{
    char *base = basename(prog_name);
    write(2, base, strlen(base));
    write(2, ": ", 2);
    write(2, file_name, strlen(file_name));
    write(2, ": ", 2);
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}

int main(int argc, char *argv[])
{
    int fd;
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    if (argc == 1)
    {
        // Read from stdin if no arguments
        while ((bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0)
            write(STDOUT_FILENO, buffer, bytes_read);
        return (0);
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-") == 0)
        {
            // Treat "-" as stdin
            while ((bytes_read = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0)
                write(STDOUT_FILENO, buffer, bytes_read);
            continue;
        }

        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            print_error(argv[0], argv[i]);
            continue;
        }

        while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0)
        {
            if (bytes_read == -1)
            {
                print_error(argv[0], argv[i]);
                break;
            }
            write(STDOUT_FILENO, buffer, bytes_read);
        }

        close(fd);
    }

    return (0);
}
