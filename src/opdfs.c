/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opdfs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:44:01 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/07 15:59:32 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cut_list_front(t_list **list)
{
	t_list	*push;
	int 	num;

	push = *list;
	num = push->data;
	// *push = *push->next;    
	// *list = push;          nuynna
	*list = push->next;
	return (num);
}