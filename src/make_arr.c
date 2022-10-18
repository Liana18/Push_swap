/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:46:58 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/18 16:37:28 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_firs_join(char *str)
{	
	int		len ;
	char	*arr;
	int		j;

	j = 0;
	len = ft_strlen(str);
	arr = malloc(len + 2);
	while (str[j])
	{
		arr[j] = str[j];
		j++;
	}
	arr[len] = ' ';
	arr[len + 1] = '\0';
	return (arr);
}

char	*ft_join_str(char **str)
{
	int		i;
	char	*arr;

	i = 1;
	arr = ft_firs_join(str[i]);
	i++;
	while (str[i])
	{
		arr = ft_strjoin(arr, str[i]);
		i++;
	}
	return (arr);
}

int	*char_to_int(int len, char **map)
{
	int	*arr;
	int	i;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > 16)
			print_error();
	}
	i = -1;
	arr = malloc(sizeof(int) * len + 1);
	if (!arr)
		return (0);
	while (map[++i])
		arr[i] = ft_atoi(map[i]);
	arr[i] = '\0';
	return (arr);
}
