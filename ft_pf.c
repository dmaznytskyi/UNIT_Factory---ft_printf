/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:02:19 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/08 15:09:04 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO потестить приориеты и перекрытие флагов, если флаги повторяються
//использовать strchr || strrchr

void	ft_pf(t_ftprintf *s, int cf)
{
	if (ft_strchr(s->output, '-'))
	{
		s->flags[0] = 1;
		cf++;
	}
	if (ft_strchr(s->output, '0'))
	{
		s->flags[1] = 1;
		cf++;
	}
	if (ft_strchr(s->output, '+'))
	{
		s->flags[2] = 1;
		cf++;
	}
	if (ft_strchr(s->output, ' '))
	{
		s->flags[3] = 1;
		cf++;
	}
	if (ft_strchr(s->output, '#'))
	{
		s->flags[4] = 1;
		cf++;
	}
	s->output += cf;
	s->f_start += cf;
}
