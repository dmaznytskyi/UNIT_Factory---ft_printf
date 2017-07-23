/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:52:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/23 12:01:39 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ret_prec(t_ftprintf *s)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;
	size_t	len;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->prec + 1);
	tmp2 = (char*)s->arg;
	s->prec > 0 ? (len = s->prec) : (len = ft_strlen(tmp2));
	while (i < len)
	{
		tmp2[i] ? (tmp[i] = tmp2[i]) : (tmp[i] = ' ');
		i++;
	}
	return (ft_putstr(tmp));
}

static size_t	ft_psp(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

static void		emp_str(t_ftprintf *s, size_t *col)
{
	if (s->fw > 0)
	{
		s->flags[1] ? ft_psp('0', s->fw) : ft_psp(' ', s->fw);
		*col += s->fw;
	}
}


static void		ft_wsf(t_ftprintf *s, size_t *col)
{
	char	*str;
	char	tmp;
	size_t	i;

	i = 0;
	tmp = ' ';
	str = (char*)s->arg;
	if (!ft_strlen(str))
	{
		emp_str(s, col);
		return ;
	}
	s->flags[1] ? tmp = '0' : 0;
	if (!s->flags[0])
	{
		if (s->fw > s->prec && s->prec > 0)
		{
			*col += ft_psp(tmp, s->fw - s->prec);
			*col += ret_prec(s);
		}
		else
		{
			if (!s->prec && s->fw > ft_strlen(str))
				*col += ft_psp(tmp, s->fw - ft_strlen(str));
			*col += ret_prec(s);
		}
	}
	else
	{
		if (s->fw > s->prec)
		{
			*col += ret_prec(s);
			s->prec > 0 ? (*col += ft_psp(' ', s->fw - s->prec)) :
				(*col += ft_psp(' ', s->fw - ft_strlen(str)));
		}
		else
			*col += ret_prec(s);
	}

}

void		ft_s_small(t_ftprintf *s, size_t *col)
{
	if (!(char*)s->arg)
		s->arg = (void*)ft_strdup("(null)");
	if (!s->fw && !s->prec)
		*col += ft_putstr((char*)s->arg);
	else
		ft_wsf(s, col);
}
