#include "push_swap.h"

static int  word_count(const char *s, char c)
{
    int wc;
    int flip;

    wc = 0;
    flip = 0;
    while (*s)
    {
        if (*s != c && flip == 0)
        {
            flip = 1;
            wc++;
        }
        else if (*s == c)
            flip = 0;
        s++;
    }
    return (wc);
}

static void ft_free(char **ar)
{
    int i;

    i = 0;
    while (ar[i])
    {
        free(ar[i]);
        i++;
    }
    ar = NULL;
    free(ar);
}

static char	*wordup(const char *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*process_arr(char const *s, char **arr, char c)
{
	int	i;
	int		j;
	int		beg;

	i = 0;
	j = 0;
	beg = -1;
	while (j < word_count(s, c))
	{
		if (s[i] != c && beg < 0)
			beg = i;
		else if ((s[i] == c || i == ft_strlen(s)) && beg >= 0)
		{
			arr[j] = wordup(s, beg, i);
			if (!arr[j])
				return (ft_free(arr), NULL);
			j++;
			beg = -1;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = malloc((sizeof(char *) * (word_count(s, c) + 1)));
	if (!s || !arr)
		return (ft_free(arr), NULL);
	arr = process_arr(s, arr, c);
	return (arr);
}