#include <stdlib.h>

int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int	is_valid_base(char *base)
{
	int i;
	int j;
	int len = ft_strlen(base);

	if (len < 2)
		return 0;
	
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return 0;
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int	ft_atoi_base(char *str, char *base)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int base_len = ft_strlen(base);

	if (!is_valid_base(base))
		return 0;
	
	// Skip whitespace
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	
	// Handle sign
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	
	// Convert number
	while (str[i])
	{
		int j = 0;
		while (j < base_len && base[j] != str[i])
			j++;
		if (j >= base_len)
			break;
		result = result * base_len + j;
		i++;
	}
	return result * sign;
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len = ft_strlen(base);
	int		len = 1;
	int		temp = nbr;
	int		i;
	
	if (!is_valid_base(base))
		return NULL;
	
	// Calculate length of result
	if (nbr <= 0)
		len++;
	temp = (nbr < 0) ? -nbr : nbr;
	while (temp >= base_len)
	{
		temp /= base_len;
		len++;
	}
	
	// Allocate memory
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;
	
	// Handle 0 case
	if (nbr == 0)
	{
		result[0] = base[0];
		result[1] = '\0';
		return result;
	}
	
	// Fill the string
	i = len - 1;
	temp = (nbr < 0) ? -nbr : nbr;
	while (temp > 0)
	{
		result[i--] = base[temp % base_len];
		temp /= base_len;
	}
	if (nbr < 0)
		result[i] = '-';
	result[len] = '\0';
	return result;
}
/*
char *result = ft_convert_base("  -101010 ", "01", "0123456789ABCDEF");
// result will be "-2A" (binary "101010" = hex "2A")
free(result);*/
