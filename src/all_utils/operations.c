/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:21 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/20 18:45:24 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **list, int i)
{
	t_list	*first;
	t_list	*second;

	if ((*list)->next != NULL)
	{
		first = *list;
		second = first->next;
		first->next = second->next;
		second->next = first;
		(*list) = second;
		if (i == 1)
			write(1, "sa\n", 3);
		if (i == 2)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *a_list, t_list *b_list)
{
	sa_sb(&a_list, 3);
	sa_sb(&b_list, 3);
	write(1, "ss\n", 3);
}

void	pa(t_list **a_list, t_list **b_list)
{
	t_list	*push;
	int		num;

	push = NULL;
	if (*b_list != NULL)
	{
		num = cut_list_front(b_list);
		push = malloc(sizeof(t_list));
		push->data = num;
		push->next = NULL;
		push->next = *a_list;
		*a_list = push;
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **a_list, t_list **b_list)
{
	t_list	*push;
	int		num;

	push = NULL;
	if (*a_list)
	{
		num = cut_list_front(a_list);
		push = malloc(sizeof(t_list));
		push->data = num;
		push->next = NULL;
		push->next = *b_list;
		*b_list = push;
		write(1, "pb\n", 3);
	}
}

void	ra_rb(t_list **list, int i)
{
	t_list	*adress;
	int		num;

	adress = *list;
	if (*list != NULL && (*list)->next != NULL)
	{
		num = cut_list_front(list);
		while (adress->next != NULL)
		{
		adress = adress->next;
		}
		adress->next = malloc(sizeof(t_list));
		adress->next->data = num;
		adress->next->next = NULL;
	}
	if (i == 1)
		write(1, "ra\n", 3);
	else if (i == 2)
		write(1, "rb\n", 3);
}
