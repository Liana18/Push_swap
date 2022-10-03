/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:44 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/03 17:36:28 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(void)
{
	printf("error\n");
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
