/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:00:50 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/07 15:50:55 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list	t_list;
typedef struct s_stack	t_stack;
typedef struct s_sdata	t_sdata;

struct s_list
{
	int		data;
	//int		index;
	t_list	*next;
};

struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		count;
};

struct s_sdata
{
	t_stack	*stack_a;
	t_stack	*stack_b;
};

void	sa(t_list *list, int i);
void	sb(t_list *list, int i);
char	**ft_split(char *s, char c);
void	print_error(void);
int		ft_strlen(char *str);
char	*ft_join_str(char **str);
void	checker(char *str);
int		*char_to_int(int len, char **map);
int		matrix_len(char **str);
int		ft_atoi(char *str);
void	checke_dup(int *arr_int, int arr_len);
char	*ft_strjoin(char *str_main, char *str_copy);
void	arr_to_list(int *arr, int len);
void	sa(t_list *list, int i);
void	sb(t_list *list, int i);
void	ss(t_list *a_list, t_list *b_list);
int		cut_list_front(t_list **list);
void	pa(t_list **a_list,t_list **b_list, int i);
void	pb(t_list **a_list, t_list **b_list, int i);
void	ra(t_list **a_list);
#endif
