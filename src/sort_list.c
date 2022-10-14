/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:53:02 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/14 20:32:43 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **list)
{
	int		i;
	int		j;
	int		max;
	t_list	*node;

	j = 0;
	i = 0;
	node = *list;
	max = node->data;
	node = node->next;
	while (node)
	{
		if (max < node->data)
		{
			max = node->data;
			node = node->next;
			i++;
			j = i;
		}
		else
		{
			node = node->next;
			i++;
		}
	}
	return (j);
}

void	sort_two(t_list **list)
{
	if ((*list)->index > (*list)->next->index)
		sa_sb(list, 1);
}

void	sort_3(t_list **stack_a)
{
	if (((*stack_a)->index > ((*stack_a)->next->index))
		&& (((*stack_a)->index) < (*stack_a)->next->next->index))
		sa_sb(stack_a, 1);
	else if ((((*stack_a)->index) > ((*stack_a)->next->index))
		&& (((*stack_a)->next->index) > ((*stack_a)->next->next->index)))
	{
		sa_sb(stack_a, 1);
		rra_rrb(stack_a, 1);
	}
	else if ((((*stack_a)->index) > ((*stack_a)->next->index))
		&& (((*stack_a)->next->index) < ((*stack_a)->next->next->index)))
		ra_rb(stack_a, 1);
	else if ((((*stack_a)->index) < ((*stack_a)->next->index))
		&& (((*stack_a)->next->index) > ((*stack_a)->next->next->index))
		&& ((*stack_a)->index < (*stack_a)->next->next->index))
	{
		sa_sb(stack_a, 1);
		ra_rb(stack_a, 1);
	}
	else if ((((*stack_a)->index) < ((*stack_a)->next->index))
		&& (((*stack_a)->next->index) > ((*stack_a)->next->next->index)))
		rra_rrb(stack_a, 1);
}

void	sort_three(t_list **list)
{
	int	i;

	i = find_max(list);
	if (i == 2)
		sort_two(list);
	if (i == 1)
	{
		rra_rrb(list, 1);
		sort_two(list);
	}
	if (i == 0)
	{
		ra_rb(list, 1);
		sort_two(list);
	}
}

void	sort_foure(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = find_max(stack_a);
	if (i == 0)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		//sort_3(stack_a);
		pa(stack_a, stack_b);
		ra_rb(stack_a, 1);
	}
	else
		if (i == 3)
		{
			rra_rrb(stack_a, 1);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			//sort_3(stack_a);
			pa(stack_a, stack_b);
			ra_rb(stack_a, 1);
		}
	else
		if (i == 2)
		{
			rra_rrb(stack_a, 1);
			rra_rrb(stack_a, 1);
			pb(stack_a, stack_b);
			//sort_3(stack_a);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra_rb(stack_a, 1);  //// shxaruma
		}
	else
		if (i == 1)
		{
			ra_rb(stack_a, 1);
			pb(stack_a, stack_b);
			sort_3(stack_a);
			pa(stack_a, stack_b);
			ra_rb(stack_a, 1);
		}
}

void sort_five(t_list **stack_a, t_list **stack_b, int len)
{
	int i;
	(void)len;
	i = find_max(stack_a);
	if (i == 0)
	{
		pb(stack_a, stack_a);
		sort_foure(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra_rb(stack_a, 1);
	}
}

void	sort_list(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_foure(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b, len);
}
	// while ((*stack_a) != NULL)
	// {
	// 	printf("\ndata=>%d\nstack_a = %d\n", (*stack_a)->index, (*stack_a)->data);
	// 	(*stack_a) = (*stack_a)->next;
	// }
	// return (0);
//}
