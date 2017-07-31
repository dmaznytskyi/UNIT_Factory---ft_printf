/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/29 21:35:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//ft_wstrlen() для обрезки по пресижену
//ft_wchar_to_char() каждый вчар_т выводит как масив чаров/интов
/*
static size_t	ft_bitcnt(int n)
{
	return (ft_strlen(ft_itoa_base(n, 2)));
}
*/
static size_t	ft_wstrlen(wchar_t *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void		ft_write(size_t v)
{
	if (v <= 127)
	{
		ft_write_one(v);
	}
	else if (v >= 128 && v <= 2047)
	{
		ft_write_two(v, 49280, 0);
	}
	else if (v >= 2018 && v <= 65535)
	{
		ft_write_three(v, 14712960, 0);
	}
	else
	{
		ft_write_four(v, 4034953344, 0);
	}
}

void			ft_s_big(t_ftprintf *s, size_t *col)
{
	size_t	i;
	wchar_t	*st;

	st = (wchar_t *)s->arg;
	i = 0;
	while (i < ft_wstrlen(st))
	{
		ft_write(st[i]);
		i++;
		*col += 1;
	}
}
