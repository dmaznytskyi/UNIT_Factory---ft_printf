/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:16:20 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/21 15:52:41 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wsp(t_ftprintf *s, size_t *col)
{
	size_t	i;

	i = 0;
	*col += 1;
	while (i < s->fw - 1)
	{
		write(1, " ", 1);
		i++;
	}
}

static void	ft_wcf(t_ftprintf *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->fw);
	if (!s->flags[0])
	{
		while (i < s->fw - 1)
		{
			s->flags[1] ? (tmp[i] = '0') :
				(tmp[i] = ' ');
			i++;
		}
		s->l == 0 ? (tmp[i++] = (char)s->arg) : (tmp[i++] = s->l);
	}
	else
	{
		s->l == 0 ? (tmp[i] = (char)s->arg) : (tmp[i] = s->l);
		i++;
		while (i < s->fw)
			tmp[i++] = ' ';
	}
	tmp[i] = '\0';
	s->output = ft_strdup(tmp);
}

void		ft_c_small(t_ftprintf *s, size_t *col)
{
	if (s->fw == 0)
	{
		s->l == 0 ? ft_putchar((char)s->arg) : ft_putchar(s->l);
		*col += 1;
	}
	else
	{
		(s->arg == 0 && !s->l && s->flags[0]) ? ft_wsp(s, col) : 0;
		ft_wcf(s);
		*col += ft_putstr_until(s->output, s->fw);
	}
}
