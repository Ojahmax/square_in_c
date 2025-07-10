#include <stdlib.h>

int     is_separator(char c, char *charset)
{
    while (*charset)
    {
        if (c == *charset)
            return (1);
        charset++;
    }
    return (0);
}

int     count_words(char *str, char *charset)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (is_separator(*str, charset))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}

char    *get_next_word(char **str, char *charset)
{
    char    *start;
    char    *word;
    int     len = 0;

    // Skip leading separators
    while (**str && is_separator(**str, charset))
        (*str)++;

    start = *str;

    // Find end of word
    while (**str && !is_separator(**str, charset))
    {
        (*str)++;
        len++;
    }

    if (len == 0)
        return (NULL);

    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);

    // Copy the word
    for (int i = 0; i < len; i++)
        word[i] = start[i];
    word[len] = '\0';

    return (word);
}

char    **ft_split(char *str, char *charset)
{
    int     word_count;
    char    **result;
    int     i;

    if (!str || !charset)
        return (NULL);

    word_count = count_words(str, charset);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);

    i = 0;
    while (i < word_count)
    {
        result[i] = get_next_word(&str, charset);
        if (!result[i])
        {
            // Free previously allocated memory if allocation fails
            while (--i >= 0)
                free(result[i]);
            free(result);
            return (NULL);
        }
        i++;
    }
    result[word_count] = NULL;
    return (result);
}
