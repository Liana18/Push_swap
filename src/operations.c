/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:21 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/10 20:54:00 by lter-zak         ###   ########.fr       */
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
			write(1, "sa\n", 3);
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
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *a_list, t_list *b_list)
{
	sa(a_list, 1);
	sb(b_list, 1);
	write(1, "ss\n", 3);
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
		write(1, "pa\n", 3);
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
		write(1, "pb\n", 2);
		free(push);
	}
}

void	ra_rb(t_list **list, int n)
  {
	t_list	*tmp;
	int		num;
	if(*list != NULL)
	{
	num = cut_list_front(list);
		tmp = *list;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp ->next= malloc(sizeof(t_list));
		tmp->next->data = num;
		tmp->next->next = NULL;
		if (n == 1)
			write(1, "ra\n", 3);
		else if (n == 2)
			write(1, "rb\n", 3);
		//free(tmp);
	}
}
void	rr(t_list **list_a, t_list **list_b)
{
	ra_rb(list_a, 3);
	ra_rb(list_b, 3);
	write(1, "rr\n", 3);
}


void rra_rrb(t_list **list, int n)
{
	t_list *adress;
	t_list *tmp;
	t_list  *tmp2;
	if (*list)
	{
		adress = *list;
		tmp = *list;
		while(adress->next!=NULL)
		{
			tmp2 = adress;
			adress= adress->next;
		}
		tmp2->next = NULL;
		adress->next = tmp;
		*list = adress;
		if (n == 1)
			write(1, "rra\n", 4);
		if (n == 2)
			write(1, "rrb\n", 4);
	}
}

void	rra(t_list **list_a, t_list **list_b)
{
	rra_rrb(list_a, 3);
	rra_rrb(list_b, 3);
	write(1, "rrr\n", 4);
} 