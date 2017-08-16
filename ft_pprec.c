/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 18:11:10 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/17 00:02:00 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pprec(t_ftprintf *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s->output[0] == '.')
	{
		s->output += 1;
		while (s->output[i] >= '0' && s->output[i] <= '9')
			i++;
		tmp = ft_strsub(s->output, 0, i);
		s->prec = ft_atoi(tmp);
		s->output += i;
		s->f_start += i;
	}
}
