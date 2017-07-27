/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/27 14:17:14 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

//ft_wstrlen() для обрезки по пресижену
//ft_wchar_to_char() каждый вчар_т выводит как масив чаров/интов

static size_t	ft_bitcnt(int n)
{
	return (ft_strlen(ft_itoa_base(n, 2)));
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
	setlocale(LC_ALL, "en_US.UTF-8");

	unsigned int mask1 = 49280;
	unsigned int mask2 = 14712960;
	unsigned int mask3 = 4034953344;

	size_t	size = ft_bitcnt(v);
	size_t	octet;

	if (size <= 7)
	{
		octet = v;
		write(1, &octet, 1);
	}
	else  if (size <= 11)
	{
		unsigned char o2 = (v << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
		unsigned char o1 = ((v >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

		octet = (mask1 >> 8) | o1; // Применение первой битовой маски ко первому байту
		write(1, &octet, 1);
		octet = ((mask1 << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
	}
	else  if (size <= 16)
	{
		unsigned char o3 = (v << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
		unsigned char o2 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
		unsigned char o1 = ((v >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx

		octet = (mask2 >> 16) | o1; // Применение первой битовой маски ко первому байту
		write(1, &octet, 1);
		octet = ((mask2 << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
		octet = ((mask2 << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
		write(1, &octet, 1);
	}
	else
	{
		unsigned char o4 = (v << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
		unsigned char o3 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
		unsigned char o2 = ((v >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
		unsigned char o1 = ((v >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

		octet = (mask3 >> 24) | o1; // Применение бит первого байта на первый байт маски
		write(1, &octet, 1);
		octet = ((mask3 << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
		write(1, &octet, 1);
		octet = ((mask3 << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
		write(1, &octet, 1);
		octet = ((mask3 << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
		write(1, &octet, 1);
	}
	*col += 1;
}

void			ft_s_big(t_ftprintf *s, size_t *col)
{
	size_t	i;
	wchar_t	*st;

	st = (wchar_t *)s->arg;
	i = 0;
	while (i < ft_wstrlen(st))
	{
		ft_write(st[i], col);
		i++;
	}
}
