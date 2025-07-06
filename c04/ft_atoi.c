int ft_atoi(char *str)
{
    int sign;
    int result;
    int i;

    sign = 1;
    result = 0;
    i = 0;
    // Skip whitespace
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    // Handle signs
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    // Convert digits
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}
