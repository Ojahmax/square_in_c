#include <unistd.h>
#include <fcntl.h>

void ft_putstr(char *str)
{
    while (*str)
        write(2, str++, 1);
}

int main(int argc, char *argv[])
{
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    if (argc < 2)
    {
        ft_putstr("File name missing.\n");
        return (1);
    }
    else if (argc > 2)
    {
        ft_putstr("Too many arguments.\n");
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("Cannot read file.\n");
        return (1);
    }

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
        write(1, buffer, bytes_read);

    close(fd);
    return (0);
}
