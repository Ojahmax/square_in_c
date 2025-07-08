#include <stdlib.h>

extern int		ft_atoi_base(char *str, char *base);
extern char		*ft_itoa_base(int nbr, char *base);
extern int		is_valid_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return NULL;
	
	number = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(number, base_to);
	
	return result;
}
