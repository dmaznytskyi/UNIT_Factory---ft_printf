/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:12:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 00:37:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*ft_psp(size_t len, unsigned char c)
{
	unsigned char	*ret;
	size_t			i;

	ret = (unsigned char*)malloc(sizeof(unsigned char) * len + 1);
	i = -1;
	while (++i < len)
		ret[i] = c;
	ret[i] = '\0';
	return (ret);
}

unsigned char			*ft_sb_fun9(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	unsigned char	*nor;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	nor = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	nor[0] = 0;
	if (st[0] != 0)
		while (*len < s->prec)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++],
						len, s->prec));
	else
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, ' '));
	return (tmp);
}

unsigned char			*ft_sb_fun10(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	unsigned char	*nor;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	nor = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	nor[0] = 0;
	if (st[0] != 0)
		while (*len < s->prec)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++],
						len, s->prec));
	else
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, ' '));
	return (tmp);
}

unsigned char			*ft_sb_fun11(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (s->prec > s->fw && s->fw > 0)
		while (*len < s->prec)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++], len, s->prec));
	else
	{
		if (!s->prec)
			tmp = ft_sb_fun7(s, st, len);
		else if (s->fw && st[0] != 0)
			tmp = ft_sb_fun8(s, st, len);
		else if (s->fw < s->prec)
			tmp = ft_sb_fun9(s, st, len);
		else
			tmp = ft_sb_fun10(s, st, len);
	}
	return (tmp);
}
