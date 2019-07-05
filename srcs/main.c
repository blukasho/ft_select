/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:16:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/05 02:49:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(void)
{
	char		*term_name;
	t_ft_select	*s;

	s = init_t_ft_select();
	init_terminal_name(s);
	init_terminal_config(s);
	if (s)
	{}
	read_input(s);
	term_name = getenv("TERM");
	ft_printf("term_name = %s\n", term_name);
	ft_printf("_POSIX_VDISABLE = %d\n", _POSIX_VDISABLE);
	ft_printf("ttyname() = %s\n", ttyname(0));
	ft_printf("is STDIN %d\n", isatty(STDIN_FILENO));
	ft_printf("is STDOUT %d\n", isatty(STDOUT_FILENO));
	ft_printf("is STDERR %d\n", isatty(STDERR_FILENO));
	ft_printf("STDIN_FILENO %d STDOUT_FILENO %d STDERR_FILENO %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	ft_putendl_fd("STDERR_FILENO", STDERR_FILENO);
	ft_putendl_fd("STOUT_FILENO", STDOUT_FILENO);
	ft_putendl_fd("STDIN_FILENO", STDIN_FILENO);
	ft_printf("tgetstr() %s\n", tgetstr("vi", NULL));

	init_old_terminal_config(s);
	if (s)
		clear_t_ft_select(s);
	return (0);
}

