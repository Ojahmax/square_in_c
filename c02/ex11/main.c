int main(void)
{
    char test[] = "Hello\nWorld\t!";
    ft_putstr_non_printable(test);
    // Output: Hello\0aWorld\09!
    return 0;
}

