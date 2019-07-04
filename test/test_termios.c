/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 12:01:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/04 15:43:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int					main(void)
{
	struct termios	term;
	long			vdisable;

	vdisable = 0;

	if (isatty(STDIN_FILENO) == 0)
		return (printf("ERROR is not stdin.\n"));
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		return (printf("ERROR tcgetattr()\n"));
}
