/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:29:38 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/10 17:47:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			get_max_len_elem(t_ft_select *s)
{
	t_elem	**elem;
	int		max_len;

	elem = s->elem;
	max_len = 0;
	while (*elem)
		if ((int)ft_strlen(((*elem)->name)) > max_len)
			max_len = ft_strlen(((*(elem++))->name));
		else
			++elem;
	return (max_len);
}

int			get_count_elem(t_ft_select *s)
{
	t_elem	**elems;
	int		count_elems;

	count_elems = 0;
	elems = s->elem;
	while (*(elems++))
		++count_elems;
	return (count_elems);
}
