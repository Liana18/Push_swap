/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/06 20:08:14 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(int *arr, int len)
{
	t_list	*list;
	t_list	*head;
	int		i;

	i = 0;
	list = malloc(sizeof(t_list));
	head = list;
	while (i < len)
	{
		list->data = arr[i];
		if (i + 1 != len)
			list->next = malloc(sizeof(t_list));
		else
			break ;
		list = list->next;
		list->next = 0;
		i++;
	}
// 	list = head;
// 	 sa(list);
}
