/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:44:29 by                   #+#    #+#             */
/*   Updated: 2019/07/11 13:08:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			print_bite(int n)
{
	write(STDOUT_FILENO, &n, 1);
	return (0);
}

int					prepare_output_elem(t_ft_select *s)
{
	int				elems;
	int				col;
	int				row;

	elems = get_count_elem(s);
	if (!(col = (get_win_col(s) / (get_max_len_elem(s) + 1))))
		return (0);
	row = elems / col;
	if (elems % col)
		++row;
	if (row >= get_win_row(s))
		return (0);
	print_elems(s, col, row);
	return (1);
}

int					print_elems(t_ft_select *s, int col, int row)
{                   
	t_elem			**elem;
	int				c_col;
	int				c_row;
	int				space;

	elem = s->elem;
	c_row = 0;
	while (*elem && c_row++ < row)
	{
		c_col = 0;
		while (*elem && c_col++ < col)
		{
			space = (int)ft_strlen(((*elem)->name));
			ft_printf("%s", ((*(elem++))->name));
			while (space++ < (get_max_len_elem(s) + 1))
				ft_printf(" ");
		}
		ft_printf("\n");
	}
	return (0);
}
