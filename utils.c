/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:04:24 by lter-zak          #+#    #+#             */
/*   Updated: 2022/10/01 21:28:08 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strjoin(char *str_main, char *str_copy)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(str) + ft_strlen(str_copy);
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (str_main[++i])
			str[i] = str_main[i];
	while (str_copy[++j])
		str[i++] = str_copy[j];
		str[i] = '\0';
	free(str_main);
	return (str);
}