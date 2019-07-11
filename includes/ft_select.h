/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:13:46 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/11 16:30:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define FAIL EXIT_FAILURE

# define CLEAR_TERMINAL "cl"
# define HIDE_CURSOR "vi"
# define SHOW_CURSOR "ve"
# define START_PROGRAM "ti"
# define END_PROGRAM "te"
# define START_CURSOR_POS "ho"
# define SAVE_CURSOR_POS "sc"
# define RESTORE_CURSOR_POS "rc"

# define MOVE_UP "up"
# define MOVE_DOWN "do"
# define MOVE_LEFT "le"
# define MOVE_RIGHT "nd"

# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define LEFT_KEY 4479771
# define RIGHT_KEY 4414235

# define SPACE '.'

# define _TPUTS(s) tputs(s, STDOUT_FILENO, print_bite)
# define _TPUTS_TGETSTR(s) tputs(tgetstr(s, NULL), STDOUT_FILENO, print_bite)

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/ioctl.h>

typedef struct		s_elem
{
	char			*name;
	char			is_select;
	char			is_remove;
	char			is_pos;
}					t_elem;

typedef struct		s_curs
{
	int				pos_row;
	int				pos_col;
	int				max_row;
	int				max_col;
}					t_curs;

typedef struct		s_ft_select
{
	char			*config_name;
	struct termios	old_config;
	struct termios	new_config;
	t_elem			**elem;
	t_curs			*pos;
}					t_ft_select;

int					handle_keys(t_ft_select *s, long key);
int					init_terminal_config(t_ft_select *s);
int					init_old_terminal_config(t_ft_select *s);
int					init_terminal_name(t_ft_select *s);
int					print_bite(int n);
int					print_elems(t_ft_select *s, int col, int row);
int					read_input(t_ft_select *s);
int					clear_t_ft_select(t_ft_select *s);
int					exit_ft_select(t_ft_select *s, char *error, int error_code);
int					print_size_window(t_ft_select *s);//test func
int					get_max_len_elem(t_ft_select *s);
int					get_count_elem(t_ft_select *s);
int					prepare_output_elem(t_ft_select *s);//test
int					get_win_row(t_ft_select *s);
int					get_win_col(t_ft_select *s);

t_curs				*init_t_curs(t_ft_select *s);
t_ft_select			*init_t_ft_select(int argc, char **argv);

#endif
