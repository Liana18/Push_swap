/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:00:50 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/18 17:27:12 by lter-zak         ###   ########.fr       */
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
typedef	struct s_parts	t_parts;

struct s_parts
{
	t_list *head;
	t_list *tail;
	int 	count;
};

struct s_list
{
	int		data;
	int		index;
	t_list	*next;
	//t_parts	*node;
};


// struct s_sdata
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// };

void	sa(t_list *list, int i);
void	sb(t_list *list, int i);
//char	**ft_split(char *s, char c);
char	**ft_split(char const *s, char c);
void	print_error(void);
int		ft_strlen(char *str);
char	*ft_join_str(char **str);
void	checker(char *str);
int		*char_to_int(int len, char **map);
int		matrix_len(char **str);
int		ft_atoi(char *str);
void	checke_dup(int *arr_int, int arr_len);
char	*ft_strjoin(char *str_main, char *str_copy);
int		arr_to_list(int *arr, int len);
void	ss(t_list *a_list, t_list *b_list);
int		cut_list_front(t_list **list);
void	index_list(t_list **list, int len);
void	sort_list(t_list **stack_a, t_list **stack_b, int len);
void	pa(t_list **a_list, t_list **b_list);
void	pb(t_list **a_list, t_list **b_list);
void	sa_sb(t_list **list, int i);
void	ra_rb(t_list **list, int i);
void	butterfly_sort(t_list **stack_a, t_list **stack_b, int len);
void	push_stack_a(t_list **stack_a, t_list **stack_b, int n);
void	rr(t_list **list_a, t_list **list_b);
int		find_max(t_list **list);
int		is_sorted(int *arr, int len);
void	rra_rrb(t_list **list, int n);
#endif
