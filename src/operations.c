/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:21 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/06 21:48:05 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list, int i)
{
	int	nb;

	nb = list->data;
	list->data = list->next->data;
	list->next->data = nb;
	if (i == 1)
		write(1, "sa", 2);
}

void	sb(t_list *list, int i)
{
	int	nb;

	nb = list->data;
	list->data = list->next->data;
	list->next->data = nb;
	if (i == 1)
		write(1, "sb", 2);
}

void	ss(t_list *a_list, t_list *b_list)
{
	sa(a_list, 1);
	ab(b_list, 1);
	write(1, "ss", 2);
}

void	pa(t_list *a_list, t_list *b_list, int i)
{
	t_list	*push;
	t_list	*head;

	if (b_list)
	{
		head = a_list;
		push = malloc(sizeof(t_list));
		a_list = push;
		push->data = b_list->data;
		push->next = head;
		if (i == 1)
			write(1, "pa", 2);
	}
}

// void	pb(t_list *a_list, t_list *b_list)
// {
// }

////////////// neet stack ////////////////