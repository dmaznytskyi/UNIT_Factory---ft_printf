/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/05 23:27:34 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_psp(size_t len)
{
	while (len-- > 0)
		write(1, " ", 1);
	return (len);
}

static size_t	ft_wstrlen(wchar_t *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void		ft_write(size_t v, size_t *col, size_t *len, size_t max)
{
	size_t	size;

	size = ft_strlen(ft_itoa_base(v, 2));
	if (size <= 7 && *len + 1 <= max)
	{
		ft_write_one(v);
		*col += 1;
		*len += 1;
	}
	else if (size <= 11 && *len + 2 <= max)
	{
		ft_write_two(v);
		*col += 2;
		*len += 2;
	}
	else if (size <= 16 && *len + 3 <= max)
	{
		ft_write_three(v);
		*col += 3;
		*len += 3;
	}
	else if (*len + 4 <= max)
	{
		ft_write_four(v);
		*col += 4;
		*len += 4;
	}
}

void			ft_s_big(t_ftprintf *s, size_t *col)
{
	size_t	i;
	size_t	sum;
	size_t	pr;
	size_t	bkp;
	size_t	len;
	wchar_t	*st;

	st = (wchar_t *)s->arg;
	if (st == 0)
		return ;
	i = 0;
	len = 0;
	bkp = *col;
	pr = *col + s->fw;
	s->prec ? (sum = s->prec) : (sum = ft_wstrlen(st));
	if (s->flags[0])
	{ 
		//если есть флаг минус
		if (s->prec > s->fw)
			while (*col - bkp < s->fw && len < *col - bkp && s->fw > 0)
				ft_write(st[i++], col, &len, s->fw);
		else
		{
			while (len < s->prec)
				ft_write(st[i++], col, &len, s->prec);
			if (len < s->fw)
				*col += ft_psp(s->fw - (*col - bkp));
		}
	}
	else
	{
		//если флага минус нет
		if (s->prec == 0 && s->fw == 0)
			while (st[i])
				ft_write(st[i++], col, &len, 2147483648);
		else if (s->prec > s->fw)
			while (len < s->fw)
				ft_write(st[i++], col, &len, s->fw);
		else
		{
			if (s->fw > ft_wstrlen(st))
				while (st[i])
					ft_write(st[i++], col, &len, 2147483648);
			else
			{
				*col += ft_psp(s->fw - s->prec);
				len += (s->fw - s->prec);
				while (len < s->fw)
					ft_write(st[i++], col, &len, s->fw);
			}
		}
	}
}
