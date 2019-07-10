/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:58:28 by                   #+#    #+#             */
/*   Updated: 2019/07/10 17:50:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	move_right(t_ft_select *s)
{
	int		len;
	t_elem	**elem;

	elem = s->elem;
	while (*elem && !((*elem)->is_pos))
		++elem;
	(*elem)->is_pos = 0;
	len = ft_strlen((*elem)->name) + 1;
	while (--len >= 0)
		_TPUTS_TGETSTR(MOVE_RIGHT);
	if (*(elem + 1))
		(*(elem + 1))->is_pos = 1;
	else
	{
		(*(s->elem))->is_pos = 1;
		_TPUTS_TGETSTR("ho");
	}
	return (0);
}

int			handle_keys(t_ft_select *s, long key)
{
	if (s && key)
	{
//		ft_printf("%\n%ld\n", key);
	}
	if (key == UP_KEY)
		_TPUTS_TGETSTR(MOVE_UP);
	else if (key == DOWN_KEY)
		_TPUTS_TGETSTR(MOVE_DOWN);
	else if (key == LEFT_KEY)
		_TPUTS_TGETSTR(MOVE_LEFT);
	else if (key == RIGHT_KEY)
		move_right(s);
	return (0);
}
