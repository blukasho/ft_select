/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:58:28 by                   #+#    #+#             */
/*   Updated: 2019/07/08 18:48:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
		_TPUTS_TGETSTR(MOVE_RIGHT);
	return (0);
}
