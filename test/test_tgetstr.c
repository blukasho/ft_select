/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tgetstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:23:53 by                   #+#    #+#             */
/*   Updated: 2019/07/05 11:39:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static int	print_test(int n)
{
	return (write(STDOUT_FILENO, &n, 1));
}

int			main(void)
{
	char	buf[1024];
	char	buf2[30];
	char	*ap = buf2;
	char *clearstr, *gotostr, *standstr, *stendstr, *vi, *ti;

	tgetent(buf, getenv("TERM"));

//	clearstr = tgetstr("cl", &ap);
//	gotostr = tgetstr("cm", &ap);
//	standstr = tgetstr("so", &ap);
//	stendstr = tgetstr("se", &ap);
	tputs(tgetstr("vi", NULL), STDOUT_FILENO, print_test);
	tputs(tgetstr("ti", NULL), STDOUT_FILENO, print_test);
//	printf("%s", vi);
//	printf("%s", ti);

	sleep(3);

	tputs(tgetstr("ve", &ap), STDOUT_FILENO, print_test);
	tputs(tgetstr("te", &ap), STDOUT_FILENO, print_test);
//	vi = tgetstr("ve", &ap);
//	ti = tgetstr("te", &ap);printf
//	printf("%s", vi);
//	printf("%s", ti);

//	sleep(3);
//	tputs(vi, STDOUT_FILENO, ft_putnbr);
//	tputs(ti, STDOUT_FILENO, ft_putnbr);
//	tputs(tgoto(gotostr, 20, 10), STDOUT_FILENO);
//	printf("Hello, ");
//	tputs(standstr, STDOUT_FILENO);
//	printf("world");
//	tputs(stendstr, STDOUT_FILENO);
//	putchar('!');
	return (0);
}
