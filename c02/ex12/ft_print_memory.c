#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_print_hex(unsigned char c) {
    char hex[] = "0123456789abcdef";
    ft_putchar(hex[c / 16]);
    ft_putchar(hex[c % 16]);
}

void ft_print_addr(unsigned int i) {
    int j = 7;
    while (j >= 0) {
        ft_putchar("0123456789abcdef"[(i >> (4 * j)) & 0xf]);
        j--;
    }
    ft_putchar(':');
}

void ft_print_hex_content(unsigned char *ptr, unsigned int i, unsigned int size) {
    unsigned int j = 0;
    while (j < 16) {
        if (j % 2 == 0) ft_putchar(' ');
        if (i + j < size) ft_print_hex(ptr[i + j]);
        else { ft_putchar(' '); ft_putchar(' '); }
        j++;
    }
    ft_putchar(' ');
}

void ft_print_char_content(unsigned char *ptr, unsigned int i, unsigned int size) {
    unsigned int j = 0;
    while (j < 16) {
        if (i + j < size) {
            char c = ptr[i + j];
            ft_putchar((c >= 32 && c <= 126) ? c : '.');
        } else ft_putchar(' ');
        j++;
    }
    ft_putchar('\n');
}

void ft_print_memory(void *addr, unsigned int size) {
    if (size == 0) return;
    unsigned char *ptr = (unsigned char *)addr;
    unsigned int i = 0;
    while (i < size) {
        ft_print_addr(i);
        ft_print_hex_content(ptr, i, size);
        ft_print_char_content(ptr, i, size);
        i += 16;
    }
}
