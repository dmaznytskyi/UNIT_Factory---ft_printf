/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findallmodifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:10:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/09 14:57:07 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findallmodifiers(const char *r, t_ftprintf *s, int i)
{
	s->f_start = i;
	while (!ft_cv(r[i], *s))
		i++;
	s->f_end = i;
	while (s->f_start < s->f_end)
	{
		printf("\n-INFO START----------\narg of first %% [%d]\n", (int)s->arg);
		printf("start of first %% format [%d], end [%d]\n", s->f_start, s->f_end);
		s->output = ft_strsub(r, s->f_start, s->f_end - s->f_start);
		printf("output [%s]\n", s->output);
		ft_pf(s, 0);
		printf("flags ['-' - %d, '0' - %d, '+' - %d, ' ' - %d, '#' - %d]",
				s->flags[0], s->flags[1], s->flags[2],
				s->flags[3], s->flags[4]);
		printf(" output [%s]\n", s->output);
		ft_pfw(s);
		printf("fw [%d] output [%s]\n", s->fw, s->output);
		ft_pprec(s);
		printf("prec [%d] output [%s]\n", s->prec, s->output);
		ft_psm(s);
		printf("sm [%d] output [%s]\n", s->sm, s->output);
	}
}
