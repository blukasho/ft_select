/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:34:31 by                   #+#    #+#             */
/*   Updated: 2019/07/05 03:22:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				init_terminal_config(t_ft_select *s)
{
	char		buf[1024];
	char		*dub = buf;

	if (tcgetattr(STDIN_FILENO, &(s->old_config)))
		exit_ft_select(s, "ERROR. tcgetattr().", FAIL);
	if (tcgetattr(STDIN_FILENO, &(s->new_config)))
		exit_ft_select(s, "ERROR. tcgetattr().", FAIL);
	s->new_config.c_lflag &= ~(ICANON | ECHO);
	s->new_config.c_cc[VMIN] = 0;
	s->new_config.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(s->new_config)) == -1)
		exit_ft_select(s, "ERROR. tcsetattr().", FAIL);
	ft_printf("-> %s\n", tgetstr(NULL, &dub)); //not work
	ft_printf("-> %s\n", dub); //not work
	return (0);
}

//
int				init_old_terminal_config(t_ft_select *s)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(s->old_config)) == -1)
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

t_ft_select		*init_t_ft_select(void)
{
	t_ft_select	*s;

	s = (t_ft_select *)malloc(sizeof(t_ft_select));
	if (!s)
		exit_ft_select(s, "ERROR. malloc().", FAIL);
	if (s)
		ft_bzero(s, sizeof(t_ft_select));
	return (s);
}
