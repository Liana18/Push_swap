/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:46:58 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/03 00:11:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_firs_join(char *str)
{	int		len ;
	char	*arr;
	int		j; 
	
	j = 0;
	
	len = ft_strlen(str);
	arr = malloc(len + 1);
	while (str[j])
	{
		arr[j] = str[j];
		j++;
	}
	arr[len] = ' ';
	arr[len + 1] = '\0';
	return (arr);
}

char	*ft_join_str(int a_nb, char **str)
{
	int		i;
	char	*arr;
	
	i = 1;
	arr = ft_firs_join(str[i]);
	//printf("arr = %s\n\n", arr);
	i++;
	(void)a_nb;
	
	while (str[i])
	{
		arr = ft_strjoin(arr, str[i]);
		i++;
	}
	   printf("arr = %s\n", arr);
	return (arr);
}
