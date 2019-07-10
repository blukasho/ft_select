/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:34:31 by                   #+#    #+#             */
/*   Updated: 2019/07/10 13:55:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				init_terminal_config(t_ft_select *s)
{
	if (tcgetattr(STDOUT_FILENO, &(s->old_config)))
		exit_ft_select(s, "ERROR. tcgetattr().", FAIL);
	if (tcgetattr(STDOUT_FILENO, &(s->new_config)))
		exit_ft_select(s, "ERROR. tcgetattr().", FAIL);
	s->new_config.c_lflag &= ~(ICANON | ECHO);
	s->new_config.c_cc[VMIN] = 0;
	s->new_config.c_cc[VTIME] = 0;
	if (tcsetattr(STDOUT_FILENO, TCSANOW, &(s->new_config)) == -1)
		exit_ft_select(s, "ERROR. tcsetattr().", FAIL);
//	_TPUTS_TGETSTR(HIDE_CURSOR);
	_TPUTS_TGETSTR(START_PROGRAM);
	_TPUTS_TGETSTR(CLEAR_TERMINAL);
	return (0);
}

int				init_old_terminal_config(t_ft_select *s)
{
	_TPUTS_TGETSTR(END_PROGRAM);
	_TPUTS_TGETSTR(SHOW_CURSOR);
	if (tcsetattr(STDOUT_FILENO, TCSANOW, &(s->old_config)) == -1)
		exit_ft_select(s, "ERROR. tcsetattr().", FAIL);
	return (0);
}

int				init_terminal_name(t_ft_select *s)
{
	char		*name;
	int			i;

	if (!(name = getenv("TERM")))
		exit_ft_select(s, "ERROR. The env variable TERM is not set.", FAIL);
	if ((i = tgetent(NULL, name)) == -1)
		exit_ft_select(s, "ERROR. Terminfo database could not be found.", FAIL);
	if (!i)
		exit_ft_select(s, "ERROR. No such entry.", FAIL);
	s->config_name = ft_strdup(name);
	return (0);
}

t_curs			*init_t_curs(t_ft_select *s)
{
	t_curs		*curs;

	if (!(curs = (t_curs *)malloc(sizeof(t_curs))))
		exit_ft_select(s, "ERROR. malloc init.c 61.", FAIL);
	ft_bzero(curs, sizeof(t_curs));
	return (curs);
}

t_ft_select		*init_t_ft_select(int argc, char **argv)
{
	t_ft_select	*s;
	int			i;

	s = (t_ft_select *)malloc(sizeof(t_ft_select));
	if (!s)
		exit_ft_select(s, "ERROR. malloc() init.c 61.", FAIL);
	ft_bzero(s, sizeof(t_ft_select));
	s->pos = init_t_curs(s);
	(s->elem) = (t_elem **)malloc((argc + 1) * sizeof(t_elem *));
	if (!(s->elem))
		exit_ft_select(s, "ERROR. malloc() init.c 65.", FAIL);
	i = 0;
	while (i < argc)
	{
		(s->elem)[i] = (t_elem *)malloc(sizeof(t_elem));
		((s->elem)[i])->name = ft_strdup(argv[i]);
		++i;
	}
	(s->elem)[i] = NULL;
	(*(s->elem))->is_pos = 1;
	return (s);
}
