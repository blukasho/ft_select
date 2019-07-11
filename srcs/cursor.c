/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:33:09 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/11 17:50:50 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		cursor_set_pos(t_ft_select *s, int row, int col)
{
	int	max_row;
	int	max_col;

	max_row = s->pos->max_row;
	max_col = s->pos->max_col;
	if (max_row && row)
	{}
	if (col > max_col)
	{
		s->pos->pos_col = 0;
		++(s->pos->pos_row);
	}
	return (0);
}
