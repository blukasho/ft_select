/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:44:29 by                   #+#    #+#             */
/*   Updated: 2019/07/08 18:07:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			print_bite(int n)
{
	write(STDOUT_FILENO, &n, 1);
	return (0);
}

int			print_argv(t_ft_select *s)
{
	t_elem	**elem;

	elem = s->elem;
	while (*elem)
		ft_printf("%s ", ((*(elem++))->name));
	return (0);
}
