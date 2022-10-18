/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/18 21:24:43 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_list(t_list **list, int len)
{
	t_list	*node;
	t_list	*max;
	int		i;

	i = 0;
	node = (*list)->next;
	max = *list;
	while (i < len)
	{
		while (node != NULL)
		{
			if (max->data > node->data && node->index == -1)
				max = node;
			node = node->next;
		}
		max->index = i;
		max = *list;
		node = *list;
		i++;
		while (i < len && max->index != -1)
			max = max->next;
	}
}

int	arr_to_list(int *arr, int len)
{
	t_parts	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_b = NULL;
	node = NULL;
	node = malloc(sizeof(t_parts));
	node->head = malloc(sizeof(t_list));
	node->tail = malloc(sizeof(t_list));
	stack_a = node->head;
	node->count = len;
	while (i < len)
	{
		stack_a->data = arr[i];
		stack_a->index = -1;
		if (i + 1 != len)
			stack_a->next = malloc(sizeof(t_list));
		else
		{
			node->tail = stack_a;
			break ;
		}
		stack_a = stack_a->next;
		stack_a->next = NULL;
		i++;
	}
	stack_a = node->head;
	index_list(&stack_a, len);
	sort_list(&stack_a, &stack_b, len);

	// while (stack_a != NULL)
	// {
	// 	printf("\nstack_a=>index  = %d\n", stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	printf("\nstack_b=>index == %d\n", stack_b->index);
	// 	stack_b = stack_b->next;
	// }
  return (0);
}
