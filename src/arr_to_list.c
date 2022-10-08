/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/08 12:49:17 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(int *arr, int len)
{
	t_list	*list;
	t_list	*head;
	int		i;

	i = 0;
	head = malloc(sizeof(t_list));
	list = head;
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
list = head;
// 	 sa(list);
t_list *b_list;
t_list *one = NULL;
t_list *two = NULL;
t_list *three = NULL;


  // Allocate memory
  one = malloc(sizeof( t_list));
  two = malloc(sizeof( t_list));
  three = malloc(sizeof( t_list));

  // Assign value values
  one->data = 1;
  two->data = 2;
  three->data = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  b_list = one;
	//int z = b_list->data;

//pb(&list, &b_list, 1);
ra(&list);
//pa(&list, &b_list, 1);

while (b_list != NULL) {
    printf("b_list=>%d\n", b_list->data);
   b_list = b_list->next;
  }

  while (list != NULL) {
    printf("a_list=>%d\n", list->data);
        list = list->next;
  }


  while (head != NULL) {
    printf("head =>%d\n", head ->data);
   head  = head ->next;
  }
  //cut_list_data(t_list lis)

}
