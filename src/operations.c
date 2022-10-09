/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:21 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/09 13:51:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list, int i)
{
	int	nb;

	if (list->next != NULL)
	{
		nb = list->data;
		list->data = list->next->data;
		list->next->data = nb;
		if (i == 1)
			write(1, "sa", 2);
	}
}

void	sb(t_list *list, int i)
{
	int	nb;
	
	if (list->next != NULL)
	{
		nb = list->data;
		list->data = list->next->data;
		list->next->data = nb;
		if (i == 1)
			write(1, "sb", 2);
	}
}

void	ss(t_list *a_list, t_list *b_list)
{
	sa(a_list, 1);
	sb(b_list, 1);
	write(1, "ss", 2);
}

void	pa(t_list **a_list, t_list **b_list)
{
	t_list	*push;
	int		num;

	if (*b_list)
	{
		num = cut_list_front(b_list);
		push = malloc(sizeof(t_list));
		push->data = num;
		push->next = NULL;
		push->next = *a_list;
		*a_list = push;
		write(1, "pa", 2);
		free(push);
	}
}

void	pb(t_list **a_list, t_list **b_list)
{
	t_list	*push;
	int		num;
	if (*a_list)
	{
	    num = cut_list_front(a_list);
		push = malloc(sizeof(t_list));
		push->data = num;
		push->next = NULL;
		push->next= *b_list;
		*b_list = push;
		write(1, "pb", 2);
		free(push);
	}
}

void	ra(t_list **a_list)
  {
	t_list	*tmp;
	int		num;

	num = cut_list_front(a_list);
	tmp = malloc(sizeof(t_list));
	tmp = *a_list;
	while (tmp->next != 0)
		tmp = tmp->next;
		tmp ->next= malloc(sizeof(t_list));
		tmp->next->data = num;
		tmp->next->next = NULL;
}
