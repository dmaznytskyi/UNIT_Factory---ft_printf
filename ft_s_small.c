/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:52:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 21:18:10 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void		ft_s_helper(t_ftprintf *s, size_t *col, char *str, char tmp)
{
	if (s->fw > s->prec && s->prec > 0)
	{
		*col += ft_psp(tmp, s->fw - s->prec);
		*col += s_ret_prec(s);
	}
	else
	{
		if (!s->prec && s->fw > ft_strlen(str))
			*col += ft_psp(tmp, s->fw - ft_strlen(str));
		*col += s_ret_prec(s);
	}
}

static void		ft_wsf(t_ftprintf *s, size_t *col, char tmp)
{
	char	*str;

	str = (char*)s->arg;
	if (!str || !ft_strlen(str))
	{
		emp_str(s, col);
		return ;
	}
	if (ft_strlen(str) < s->prec)
		s->prec = ft_strlen(str);
	s->flags[1] ? tmp = '0' : 0;
	if (!s->flags[0])
		ft_s_helper(s, col, str, tmp);
	else
	{
		if (s->fw > s->prec)
		{
			*col += s_ret_prec(s);
			s->prec > 0 ? (*col += ft_psp(' ', s->fw - s->prec)) :
				(*col += ft_psp(' ', s->fw - ft_strlen(str)));
		}
		else
			*col += s_ret_prec(s);
	}
}

void			ft_s_small(t_ftprintf *s, size_t *col)
{
	if (!(char*)s->arg && !s->flags[1])
		s->arg = (void*)ft_strdup("(null)");
	if (s->sm == 4)
		ft_s_big(s, col);
	else if (!s->fw && !s->prec)
		*col += ft_putstr((char*)s->arg);
	else
		ft_wsf(s, col, ' ');
}
