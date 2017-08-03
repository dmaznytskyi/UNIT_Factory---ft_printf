/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/03 20:57:17 by dmaznyts         ###   ########.fr       */
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

static void		ft_write(size_t v, size_t *col)
{
	size_t	size;

	size = ft_strlen(ft_itoa_base(v, 2));
	if (size <= 7)
	{
		ft_write_one(v);
		*col += 1;
	}
	else if (size <= 11)
	{
		ft_write_two(v);
		*col += 2;
	}
	else if (size <= 16)
	{
		ft_write_three(v);
		*col += 3;
	}
	else
	{
		ft_write_four(v);
		*col += 4;
	}
}

void			ft_s_big(t_ftprintf *s, size_t *col)
{
	size_t	i;
	size_t	sum;
	size_t	pr;
	size_t	bkp;
	wchar_t	*st;

	st = (wchar_t *)s->arg;
	if (st == 0)
		return ;
	i = 0;
	bkp = *col;
	pr = *col + s->fw;
	s->prec ? (sum = s->prec) : (sum = ft_wstrlen(st));
	if (s->flags[0])
	{ 
		//если есть флаг минус
		//выводим строку по пресижн, потом если fw > 0 и fw > *col - bkp забиваем пробелами до fw 
		if (s->prec > 0)
		{
			while (s->prec > 0)
			{
				ft_write(st[i++], col);
				s->prec -= *col - bkp;
			}
			if (s->fw > 0 && s->fw > *col - bkp)
				*col += ft_psp(s->fw - (*col - bkp));
			if ((int)st == 0)
			{
				*col += 4;
				write(1, " ", 1);
			}
		}
		else
		{
			while (i < sum)
				ft_write(st[i++], col);
		}
	}
	else
	{
		//если флага минус нет
		//выводим пробелы 
		i = 0;
	}
}
