/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:40:19 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/04 18:43:46 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int a_nb, char *str[])
{
	char	*arr_char;
	char	**map;
	int		*arr_int;
	int		mtx_len;

	mtx_len = 0;
	arr_int = NULL;
	arr_char = NULL;
	if (a_nb > 2)
	{
		arr_char = ft_join_str(str);
		checker(arr_char);
		map = ft_split(arr_char, ' ');
		mtx_len = matrix_len(map);
		arr_int = char_to_int(mtx_len, map);
		checke_dup(arr_int, mtx_len);
	}
	return (0);
}
