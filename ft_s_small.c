/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:52:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/18 18:48:36 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wsf(t_ftprintf *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->fw);
	while (i < (s->fw - ft_strlen((char*)s->arg)))
	{
		s->flags[1] ? (tmp[i] = '0') :
			(tmp[i] = ' ');
		i++;
	}
	tmp[i] = '\0';
	s->output = (char*)malloc(sizeof(char) * s->fw + 1);
	s->output = ft_strcat(tmp, (char*)s->arg);
}

void		ft_s_small(t_ftprintf *s, size_t *col)
{
	if (s->fw == 0 || ft_strlen((char*)s->arg) > s->fw)
		*col += ft_putstr((char*)s->arg);
	else
	{
		ft_wsf(s);
		*col += ft_putstr((char*)s->output);
	}
}
