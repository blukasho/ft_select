/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:50:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/12 14:36:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_get_arr(size_t x, size_t y)
{
	char	**res;
	size_t	i;

	i = 0;
	if ((res = (char **)malloc(y * sizeof(char *))))
	{
		while (i < y)
			res[i++] = ft_strnew(x);
		res[y] = NULL;
	}
	return (res);
}
