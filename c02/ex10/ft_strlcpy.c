unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (src[i] && i + 1 < size)
        dest[i] = src[i++];
    if (size)
        dest[i] = '\0';
    while (src[i])
        i++;
    return (i);
}
