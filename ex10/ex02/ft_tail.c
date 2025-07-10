#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_LINES 10

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

void tail_file(int fd, int byte_count, char *filename, char *prog_name)
{
    char *buffer;
    off_t file_size, offset;
    ssize_t bytes_read;

    // Get file size
    file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1)
    {
        print_error(prog_name, filename);
        return;
    }

    // Calculate how much to read
    offset = (byte_count > file_size) ? 0 : file_size - byte_count;

    // Allocate buffer
    buffer = malloc(byte_count + 1);
    if (!buffer)
    {
        write(2, "malloc failed\n", 13);
        return;
    }

    // Seek to position and read
    if (lseek(fd, offset, SEEK_SET) == -1)
    {
        print_error(prog_name, filename);
        free(buffer);
        return;
    }

    bytes_read = read(fd, buffer, byte_count);
    if (bytes_read == -1)
    {
        print_error(prog_name, filename);
        free(buffer);
        return;
    }

    write(STDOUT_FILENO, buffer, bytes_read);
    free(buffer);
}

int main(int argc, char *argv[])
{
    int fd;
    int byte_count = DEFAULT_LINES;
    int file_start = 1;

    // Parse -c option
    if (argc > 1 && strcmp(argv[1], "-c") == 0)
    {
        if (argc < 3)
        {
            write(2, "ft_tail: option requires an argument -- 'c'\n", 42);
            return (1);
        }
        byte_count = atoi(argv[2]);
        if (byte_count <= 0)
        {
            write(2, "ft_tail: invalid number of bytes\n", 32);
            return (1);
        }
        file_start = 3;
    }

    if (file_start >= argc)
    {
        // Read from stdin
        tail_file(STDIN_FILENO, byte_count, "stdin", argv[0]);
        return (0);
    }

    for (int i = file_start; i < argc; i++)
    {
        if (strcmp(argv[i], "-") == 0)
        {
            // Treat "-" as stdin
            tail_file(STDIN_FILENO, byte_count, "stdin", argv[0]);
            continue;
        }

        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            print_error(argv[0], argv[i]);
            continue;
        }

        if (argc > file_start + 1)
        {
            write(STDOUT_FILENO, "==> ", 4);
            write(STDOUT_FILENO, argv[i], strlen(argv[i]));
            write(STDOUT_FILENO, " <==\n", 5);
        }

        tail_file(fd, byte_count, argv[i], argv[0]);
        close(fd);
    }

    return (0);
}
