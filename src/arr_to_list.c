/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/10 20:26:11 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(int *arr, int len)
{
	t_parts	*node;
	t_list *stack_a;
	t_list *stack_b;
	//t_list	*head;
	int		i;
	stack_b = NULL;
	i = 0;
	node = NULL;
	node = malloc(sizeof(t_parts));
	node->head = malloc(sizeof(t_list));
	node->tail = malloc(sizeof(t_list));
	stack_a = node->head;
	node->count = len;
	while (i < len)
	{
		stack_a->data = arr[i];
		if (i + 1 != len)
			stack_a->next = malloc(sizeof(t_list));
		else
		{
			node->tail = stack_a;   /// avelacrel emmm
			break ;
		}
		stack_a = stack_a->next;
		stack_a->next = NULL;
		i++;
	}
	stack_a = node->head;

////////////////////////////    pa pb ..    ///////////////////////////

//sa(stack_a, 1);              // OK
//sb(stack_b, 1)			  // OK
//pb(&stack_a, &stack_b);     // OK
//pa(&stack_a, &stack_b);      // OK
//ra_rb(&stack_b, 2);
rra_rrb(&stack_a, 1);

while (stack_b != NULL) {
    printf("\nstack_b=>%d\n", stack_b->data);
    stack_b = stack_b->next;
  }

  while (stack_a != NULL) {
    printf("\na_list=>%d\n", stack_a->data);
       stack_a  = stack_a->next;
  }


// while (node->head != NULL) {
//    printf("head =>%d\n", node->head->data);
//     node->head = node->head->next;
//   }
  //cut_list_data(t_list lis)

}
