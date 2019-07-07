/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:13:46 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/07 14:14:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define FAIL EXIT_FAILURE

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct		s_elem
{
	char			*name;
	char			is_select;
	char			is_remove;
	char			is_pos;
}					t_elem;

typedef struct		s_ft_select
{
	char			*config_name;
	struct termios	old_config;
	struct termios	new_config;
	struct s_elem	**elem;
}					t_ft_select;

int					init_terminal_config(t_ft_select *s);
int					init_old_terminal_config(t_ft_select *s);
int					init_terminal_name(t_ft_select *s);
int					print_bite(int n);
int					print_argv(t_ft_select *s);
int					read_input(t_ft_select *s);
int					clear_t_ft_select(t_ft_select *s);
int					exit_ft_select(t_ft_select *s, char *error, int error_code);

t_ft_select			*init_t_ft_select(int argc, char **argv);

#endif
