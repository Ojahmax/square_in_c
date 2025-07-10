#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 16

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

void print_hex(unsigned char c)
{
    char hex_digits[] = "0123456789abcdef";
    write(1, &hex_digits[c >> 4], 1);
    write(1, &hex_digits[c & 0x0f], 1);
}

void print_line(unsigned char *buffer, int count, unsigned long offset, int canonical)
{
    char offset_buf[16];
    int i;

    // Print offset
    snprintf(offset_buf, sizeof(offset_buf), "%08lx", offset);
    write(1, offset_buf, 8);
    write(1, "  ", 2);

    // Print hex values
    for (i = 0; i < count; i++)
    {
        print_hex(buffer[i]);
        write(1, " ", 1);
        if (i == 7)
            write(1, " ", 1);
    }

    // Pad if needed
    if (canonical)
    {
        for (; i < 16; i++)
        {
            write(1, "   ", 3);
            if (i == 7)
                write(1, " ", 1);
        }
    }

    if (canonical)
    {
        write(1, " |", 2);
        // Print ASCII representation
        for (i = 0; i < count; i++)
        {
            if (isprint(buffer[i]))
                write(1, &buffer[i], 1);
            else
                write(1, ".", 1);
        }
        write(1, "|", 1);
    }
    write(1, "\n", 1);
}

void hexdump_file(int fd, char *filename, char *prog_name, int canonical)
{
    unsigned char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    unsigned long offset = 0;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        print_line(buffer, bytes_read, offset, canonical);
        offset += bytes_read;
    }

    if (bytes_read == -1)
        print_error(prog_name, filename);
}

int main(int argc, char *argv[])
{
    int fd;
    int canonical = 0;
    int file_start = 1;

    // Parse -C option
    if (argc > 1 && strcmp(argv[1], "-C") == 0)
    {
        canonical = 1;
        file_start = 2;
    }

    if (file_start >= argc)
    {
        // Read from stdin
        hexdump_file(STDIN_FILENO, "stdin", argv[0], canonical);
        return (0);
    }

    for (int i = file_start; i < argc; i++)
    {
        if (strcmp(argv[i], "-") == 0)
        {
            // Treat "-" as stdin
            hexdump_file(STDIN_FILENO, "stdin", argv[0], canonical);
            continue;
        }

        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            print_error(argv[0], argv[i]);
            continue;
        }

        hexdump_file(fd, argv[i], argv[0], canonical);
        close(fd);
    }

    return (0);
}
