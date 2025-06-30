#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_print_hex(unsigned char c) {
    char hex[] = "0123456789abcdef";
    ft_putchar(hex[c / 16]);
    ft_putchar(hex[c % 16]);
}

void ft_print_memory(void *addr, unsigned int size) {
    if (size == 0) return;
    unsigned char *ptr = (unsigned char *)addr;
    unsigned int i = 0;
    while (i < size) {
        int j = 7;
        while (j >= 0) {
            ft_putchar("0123456789abcdef"[(i >> (4 * j)) & 0xf]);
            j--;
        }
        ft_putchar(':');
        unsigned int j_hex = 0;
        while (j_hex < 16) {
            if (j_hex % 2 == 0) ft_putchar(' ');
            if (i + j_hex < size) {
                ft_print_hex(ptr[i + j_hex]);
            } else {
                ft_putchar(' ');
                ft_putchar(' ');
            }
            j_hex++;
        }
        ft_putchar(' ');
        unsigned int j_char = 0;
        while (j_char < 16) {
            if (i + j_char < size) {
                char c = ptr[i + j_char];
                ft_putchar((c >= 32 && c <= 126) ? c : '.');
            } else {
                ft_putchar(' ');
            }
            j_char++;
        }
        ft_putchar('\n');
        i += 16;
    }
}
