/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:42 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/08 19:43:54 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_list(int *arr, int len)
{
	t_sdata	stack;
	t_list	*head;
	int		i;

	i = 0;
	head = malloc(sizeof(t_list));
	stack.stack_a = head;
	stack.stack_a->head = head;   ///avelllllllll
	stack.stack_a->count = len;
	stack.stack_a->tail = malloc(sizeof(t_list));
	while (i < len)
	{
		stack.stack_a->data = arr[i];
		if (i + 1 != len)
			stack.stack_a->next = malloc(sizeof(t_list));
		else
		{
			stack.stack_a->tail = stack.stack_a;   /// avelacrel emmm
			break ;
		}
		stack.stack_a = stack.stack_a->next;
		stack.stack_a->next = NULL;
		i++;
	}
	stack.stack_a = head;
	printf("smt = %d\n", stack.stack_a->head->data);

/////////////////////////////    steck_b      ////////////////////////////
t_list *b_list;
t_list *one = NULL;
t_list *two = NULL;
t_list *three = NULL;


// Allocate memory
  one = malloc(sizeof(t_list));
  two = malloc(sizeof(t_list));
  three = malloc(sizeof(t_list));

// Assign value values
  one->data = 1;
  two->data = 2;
  three->data = 3;

// Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;
  b_list = one;
////////////////////////////    pa pb ..    ///////////////////////////

//sa(stack.stack_a, 1);              // OK
//pb(&stack.stack_a, &b_list);
//ra(&list);
//pa(&stack->stack_a, &b_list);

// while (b_list != NULL) {
//     printf("b_list=>%d\n", b_list->data);
//    b_list = b_list->next;
//   }

//printf("stack->stack_a = %d\n", stack.stack_a->data);
printf("smt = %d\n", stack.stack_a->head->data);
  while (stack.stack_a != NULL) {
    printf("\na_list=>%d\n", stack.stack_a->data);
       stack.stack_a  = stack.stack_a->next;
  }


//   while (head != NULL) {
//     printf("head =>%d\n", head ->data);
//    head  = head ->next;
//   }
  //cut_list_data(t_list lis)

}
