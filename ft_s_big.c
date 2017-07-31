/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/31 20:55:48 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	wchar_t	*st;

	st = (wchar_t *)s->arg;
	i = 0;
/*	if (s->flags[0])
	{
	
	}
	else
	{
	
	}
*/	s->prec ? (sum = s->prec) : (sum = ft_wstrlen(st));
	while (i < sum/* && i < s->fw*/)
		ft_write(st[i++], col);
}
