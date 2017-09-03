/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 00:38:06 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t			ft_putustr(unsigned char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

unsigned char			*ft_write(size_t v, size_t *len, size_t max)
{
	size_t			size;

	if (max == 0)
	{
		*len = 0;
		max = 5;
	}
	size = ft_strlen(ft_itoa_base(v, 2));
	if (size <= 7 && *len + 1 <= max)
		return (ft_so(len, v));
	else if (size <= 11 && *len + 2 <= max)
		return (ft_st(len, v));
	else if (size <= 16 && *len + 3 <= max)
		return (ft_sh(len, v));
	else if (size > 16 && *len + 4 <= max)
		return (ft_sf(len, v));
	else
		*len += 5;
	return ((unsigned char*)"");
}

static unsigned char	*ololo(unsigned char *t, size_t i)
{
	while (t[i] == ' ')
		t[i++] = '0';
	return (t);
}

void					ft_s_big(t_ftprintf *s, size_t *col)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			len;
	wchar_t			*st;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if ((wchar_t*)s->arg == NULL)
		s->arg = (void*)ft_wstrdup(L"(null)");
	st = (wchar_t *)s->arg;
	i = 0;
	len = 0;
	if (s->prec == 0 && s->fw == 0)
		while (st[i])
			tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, 0));
	else if (s->flags[0])
		tmp = ft_sb_fun5(s, st, &len);
	else if (s->ip && s->prec == 0)
		tmp = ft_sb_fun6(s);
	else
		tmp = ft_sb_fun11(s, st, &len);
	i = 0;
	if (s->flags[1] && tmp[0] == ' ')
		tmp = ololo(tmp, i);
	*col += ft_putustr(tmp);
}
