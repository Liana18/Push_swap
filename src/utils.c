/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:04:24 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/04 18:35:04 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	matrix_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin(char *str_main, char *str_copy)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	len = ft_strlen(str_main) + ft_strlen(str_copy);
	str = malloc(len + 2);
	if (!str)
		return (0);
	while (str_main[++i])
			str[i] = str_main[i];
	while (str_copy[++j])
		str[i++] = str_copy[j];
		str[i] = ' ';
		str[++i] = '\0';
	if (str_main)
		free(str_main);
	return (str);
}

////////////////im split /////////////////////////

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

// char	**ft_split(char const *s, char c)
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

////////////////im split /////////////////////////

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

int		ft_atoi(char *str)
{
	int			i;
	long int	num;
	int			min;

	min = 1;
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num * min > INT_MAX || num * min < INT_MIN)
		print_error();
	return (num * min);
}
