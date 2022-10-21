/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/21 04:16:10 by lter-zak         ###   ########.fr       */
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

int	do_the_job(t_list **stack_a, t_list **stack_b, int len)
{
	index_list(stack_a, len);
	sort_list(stack_a, stack_b, len);
	while ((*stack_a) != NULL)
	{
		printf("\n(*stack_a)= = %d    indec = %d\n", (*stack_a)->data, (*stack_a)->index);
		(*stack_a) = (*stack_a)->next;
	}
	//free_liks(stack_a);
	return (0);
}

void	arr_to_list(int *arr, int len)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	stack_b = NULL;
	node = NULL;
	node = malloc(sizeof(t_list));
	stack_a = node;
	while (i < len)
	{
		stack_a->data = arr[i];
		stack_a->index = -1;
		if (i + 1 != len)
			stack_a->next = malloc(sizeof(t_list));
		else
			break ;
		stack_a = stack_a->next;
		stack_a->next = NULL;
		i++;
	}
	stack_a = node;
	index_list(&stack_a, len);
	sort_list(&stack_a, &stack_b, len);
	//do_the_job(&stack_a, &stack_b, len);
// while (stack_a != NULL)
// 	{
// 		printf("\nstack_a=>index  = %d\n", stack_a->data);
// 		stack_a = stack_a->next;
// 	}
}