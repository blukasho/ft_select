/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:05:03 by                   #+#    #+#             */
/*   Updated: 2019/07/08 14:18:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			read_input(t_ft_select *s)
{
	long	buf;
	int		i;//test parameter

	i = 0;
	buf = 0;
	while (!0 && buf != 27 && !(buf = 0))
	{
		_TPUTS_TGETSTR(SAVE_CURSOR_POS);
		if (read(STDIN_FILENO, &buf, 4))
		{
			_TPUTS_TGETSTR(CLEAR_TERMINAL);
			print_argv(s);
			if (!i && (i = 1))
				_TPUTS_TGETSTR(START_CURSOR_POS);
			_TPUTS_TGETSTR("nd");
		}
		_TPUTS_TGETSTR(RESTORE_CURSOR_POS);
	}
	return (0);
}
