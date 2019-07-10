/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:44:29 by                   #+#    #+#             */
/*   Updated: 2019/07/10 17:54:04 by blukasho         ###   ########.fr       */
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
	struct winsize	winsize;
	int				elems;
	int				col;
	int				row;

	elems = get_count_elem(s);
	winsize = get_winsize(s);
	if (!(col = (winsize.ws_col / (get_max_len_elem(s) + 1))))
		return (0);
	row = elems / col;
	if (elems % col)
		++row;
	if (row > winsize.ws_row)
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
	c_col = 0;
	c_row = 0;
	while (c_row++ < row)
	{
		space = (int)ft_strlen(((*elem)->name));
		while (c_col < col)
		{
			ft_printf("%s", ((*(elem++))->name));
			while (space++ <= (get_max_len_elem(s) + 1))
				ft_printf(" ");
		}
		ft_printf("\n");
	}
	return (0);
}
