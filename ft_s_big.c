/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:01:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/26 18:25:54 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*ft_psp(size_t len)
{
	unsigned char	*ret;
	size_t			i;

	ret = (unsigned char*)malloc(sizeof(unsigned char) * len + 1);
	i = -1;
	while (++i < len)
		ret[i] = ' ';
	ret[i] = '\0';
	return (ret);
}

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

static unsigned char	*ft_write(size_t v, size_t *len, size_t max)
{
	size_t			size;

	if (max == 0)
	{
		*len = 0;
		max = 5;
	}
	size = ft_strlen(ft_itoa_base(v, 2));
	if (size <= 7 && *len + 1 <= max)
	{
		*len += 1;
		return (ft_one(v));
	}
	else if (size <= 11 && *len + 2 <= max)
	{
		*len += 2;
		return (ft_two(v));
	}
	else if (size <= 16 && *len + 3 <= max)
	{
		*len += 3;
		return (ft_three(v));
	}
	else if (size > 16 && *len + 4 <= max)
	{
		*len += 4;
		return (ft_four(v));
	}
	else
		*len += 5;
	return ((unsigned char*)"");
}

void					ft_s_big(t_ftprintf *s, size_t *col)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			len;
	wchar_t			*st;

	st = (wchar_t *)s->arg;
	i = 0;
	len = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (s->prec == 0 && s->fw == 0)
		while (st[i])
			tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, 0));
	else if (s->flags[0])
	{
		if (s->prec > s->fw && s->fw > 0)
			while (len < s->fw)
				tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
		else
		{
			if (!s->prec)
			{
				while (st[i])
					tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, 2147483648));
			}
			else if (s->fw)
			{
				len += ft_ustrlen(tmp);
				while (len < s->prec)
					tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
				tmp = ft_ustrjoin(tmp, ft_psp(s->fw - ft_ustrlen(tmp)));
			}
			else if (s->fw < s->prec)
			{
				if (st[0] != 0)
					while (len < s->prec)
						tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
				else
					tmp = ft_ustrjoin(tmp, ft_psp(s->fw));
			}
			else
			{
				if (st[0] != 0)
					while (len < s->prec)
						tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
				else
					tmp = ft_ustrjoin(tmp, ft_psp(s->fw));
			}
		}
	}
	else
	{
		if (s->prec > s->fw && s->fw > 0)
			while (len < s->fw)
				tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
		else
		{
			if (!s->prec)
			{
				while (st[i])
					tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, 2147483648));
			}
			else if (s->fw)
			{
				tmp = ft_ustrjoin(tmp, ft_psp(s->fw - s->prec));
				st[0] != 0 ? 0 : (tmp = ft_ustrjoin(tmp, ft_psp(s->prec)));
				len += ft_ustrlen(tmp);
				while (len < s->fw)
					tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->fw));
			}
			else if (s->fw < s->prec)
			{
				if (st[0] != 0)
					while (len < s->prec)
						tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
				else
					tmp = ft_ustrjoin(tmp, ft_psp(s->fw));
			}
			else
			{
				if (st[0] != 0)
					while (len < s->prec)
						tmp = ft_ustrjoin(tmp, ft_write(st[i++], &len, s->prec));
				else
					tmp = ft_ustrjoin(tmp, ft_psp(s->fw));
			}
		}
	}
	*col += ft_putustr(tmp);
}
