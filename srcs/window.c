/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:10:45 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/10 16:56:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int					print_size_window(t_ft_select *s)
{
	struct winsize	size;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
	   exit_ft_select(s, "ERROR. window.c 20", FAIL);	
	ft_printf("->%d\n->%d\n", size.ws_row, size.ws_col);
	return (0);
}

struct winsize		get_winsize(t_ft_select *s)
{
	struct winsize	size;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
	   exit_ft_select(s, "ERROR. window.c 30", FAIL);	
	return (size);
}
