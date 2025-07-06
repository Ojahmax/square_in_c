#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	if (base == NULL || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_recursive(int nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!validate_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			ft_putnbr_base_recursive(-(nbr / base_len), base, base_len);
			ft_putnbr_base_recursive(-(nbr % base_len), base, base_len);
			return ;
		}
		nbr = -nbr;
	}
	ft_putnbr_base_recursive(nbr, base, base_len);
}
