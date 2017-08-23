/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findallmodifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:10:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/23 20:30:31 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findallmodifiers(const char *r, t_ftprintf *s, size_t *i)
{
	s->f_start = *i;
	while (!ft_cv(r[*i], s) && r[*i] != '\0')
		*i += 1;
	s->f_end = *i;
	*i += 1;
	s->output = ft_strsub(r, s->f_start, s->f_end - s->f_start);
	while (s->f_start < s->f_end && s->output)
	{
		ft_pf(s);
		ft_pfw(s);
		ft_pprec(s);
		ft_psm(s);
		if (!s->output[0])
			break ;
	}
//	printf_info(s);
}
