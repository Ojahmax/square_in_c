#include <stdio.h>

char *ft_strcapitalize(char *str);

int main(void)
{
    char text[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    printf("%s\n", ft_strcapitalize(text));
    // Output: "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"
    return 0;
}

