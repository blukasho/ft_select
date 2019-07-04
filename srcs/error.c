/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:50:53 by                   #+#    #+#             */
/*   Updated: 2019/07/04 19:14:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		exit_ft_select(t_ft_select *s, char *error, int error_code)
{
	if (s)
		clear_t_ft_select(s);
	if (error)
		ft_putendl_fd(error, STDERR_FILENO);
	exit(error_code);
	return (0);
}
