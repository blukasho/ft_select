/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:47:48 by                   #+#    #+#             */
/*   Updated: 2019/07/09 14:29:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					clear_t_ft_select(t_ft_select *s)
{
	t_elem			**argv;

	argv = s->elem;
	if (s->config_name)
		ft_strdel(&(s->config_name));
	free(s->pos);
	if (argv)
	{
		while (*argv && !ft_strdel(&(*(argv))->name))
			free(*(argv++));
		free((s->elem));
	}
	if (s)
		free(s);
	return (0);
}
