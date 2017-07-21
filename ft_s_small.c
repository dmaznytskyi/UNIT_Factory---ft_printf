/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:52:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/21 22:42:42 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ret_prec(t_ftprintf *s)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->prec + 1);
	tmp2 = (char*)s->arg;
	while (i < s->prec)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (tmp);
}

static char	*ret_zsp(t_ftprintf *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (s->fw - s->prec));
	while (i < (s->fw - s->prec))
		s->flags[1] ? (tmp[i++] = '0') : (tmp[i++] = ' ');
	return (tmp);
}

static void	ft_wsf(t_ftprintf *s)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp1 = ret_prec(s);
	s->output = (char*)malloc(sizeof(char) * s->fw + 1);
	if (!s->flags[0])
	{
		if (s->fw > s->prec)
		{
			tmp2 = ret_zsp(s);
			s->output = ft_strcat(tmp2, tmp1);
		}
		else
		{
			s->output = ft_strdup(tmp1);
//			if (s->fw < ft_strlen((char*)s->arg))
//			{
//				s->output = ft_strdup((char*)s->arg);
//				return ;
//			}
		}
	}
	else
	{
		s->output = ft_strcat(tmp1, tmp2);
	}
}

void		ft_s_small(t_ftprintf *s, size_t *col)
{
	if (!(char*)s->arg)
	{
		s->prec > 0 ? (*col += ft_putstr_until("(null)", s->prec)) :
			(*col += ft_putstr("(null)"));
		return ;
	}
	if (!s->fw && !s->prec)
		*col += ft_putstr((char*)s->arg);
	else
	{
		ft_wsf(s);
		*col += ft_putstr((char*)s->output);
	}
}
