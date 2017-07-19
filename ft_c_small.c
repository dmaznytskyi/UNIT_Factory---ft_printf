/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:16:20 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/19 20:28:05 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wcf(t_ftprintf *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->fw);
	if (!s->flags[0])
	{
		while (i < (s->fw - s->prec))
		{
			s->flags[1] ? (tmp[i] = '0') :
				(tmp[i] = ' ');
			i++;
		}
	}
	tmp[i] = '\0';
	s->output = (char*)malloc(sizeof(char) * s->fw + 1);
	s->output = ft_strncat(tmp, (char*)s->arg, s->prec);
}

void		ft_c_small(t_ftprintf *s, size_t *col)
{
	if (s->fw == 0)
	{
		ft_putchar((char)s->arg);
		*col += 1;
	}
	else
	{
		ft_wcf(s);
		*col += ft_putstr((char*)s->output);
	}
}
