/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:01:32 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/14 17:44:30 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	del_start_from(const char *str, char del)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != del && str[i])
// 		++i;
// 	return (i);
// }

// static size_t	word_counter(const char *str, char del)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == del)
// 			++i;
// 		i += del_start_from(str + i, del);
// 		if (str[i - 1] != del)
// 			j++;
// 	}
// 	return (j);
// }

// char	*ft_substr(char *s,  int start, int len)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	k;

// 	i = 0;
// 	if (start > ft_strlen(s))
// 		k = 0;
// 	else if (ft_strlen(s) - start > len)
// 		k = len;
// 	else
// 		k = ft_strlen(s) - start;
// 	str = (char *) malloc(k * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	while (s[i] && len > 0 && start < ft_strlen(s))
// 	{
// 		str[i++] = s[start++];
// 		len--;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	**ft_split(char  *s, char c)
// {
// 	char	**split;
// 	size_t	j;
// 	size_t	i;
// 	size_t	k;
// 	size_t	w;

// 	j = 0;
// 	i = 0;
// 	k = 0;
// 	w = word_counter(s, c);
// 	split = malloc(sizeof(char *) * (w + 1));
// 	if (!split)
// 		return (NULL);
// 	while (k < w)
// 	{
// 		while (s[i] == c)
// 			i++;
// 		j = del_start_from(s + i, c);
// 		split[k] = ft_substr(s, i, j);
// 		k++;
// 		i += j;
// 	}
// 	split[w] = NULL;
// 	return (split);
// }
static int	unleah(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, const char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc (sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (unleah(split, word - 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;

	words = count_words(s, c);
	ptr = (char **)malloc (sizeof(char *) * (words + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[words] = 0;
	if (write_split(ptr, s, c) == -1)
		return (NULL);
	return (ptr);
}