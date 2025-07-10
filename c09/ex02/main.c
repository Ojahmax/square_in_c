#include <stdio.h>

int main(void)
{
    char **result = ft_split("hello,world!this.is,a.test", ",!.");
    
    for (int i = 0; result[i]; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    
    return 0;
}
