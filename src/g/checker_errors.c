/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:44 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/04 21:29:31 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	char	*str1;
	char	*str2;

	str1 = "\n\n\n\n\n------------------------\n\n\n";
	str2 = "\n\n\n------------------------\n\n\n\n\n";
	write(1, str1, ft_strlen(str1));
	write(1, "         error", 14);
	write(1, str2, ft_strlen(str2));
	exit(1);
}

void	checker(char *str)
{
	int	i;

	i = 0;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
		|| str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ' '))
				i++;
		else if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9')
			&& str[i - 1] == ' ')
			i++;
		else
			print_error();
	}
}

void	checke_dup(int *arr_int, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			printf("arr_int-i[%d] = %d\n", i, arr_int[i]);
			printf("arr_int-j[%d] = %d\n", j, arr_int[j]);
			if (arr_int[i] == arr_int[j] && i != j)
				print_error();
			j++;
		}
		i++;
	}
}