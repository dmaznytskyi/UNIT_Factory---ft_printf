/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:49:33 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 00:38:02 by dmaznyts         ###   ########.fr       */
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

unsigned char			*ft_sb_fun5(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (s->prec > s->fw && s->fw > 0)
		while (*len < s->fw)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++], len, s->prec));
	else
	{
		if (!s->prec)
			tmp = ft_sb_fun1(s, st, len);
		else if (s->fw)
			tmp = ft_sb_fun2(s, st, len);
		else if (s->fw < s->prec)
			tmp = ft_sb_fun3(s, st, len);
		else
			tmp = ft_sb_fun4(s, st, len);
	}
	return (tmp);
}

unsigned char			*ft_sb_fun6(t_ftprintf *s)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (s->flags[1])
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, '0'));
	else
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, ' '));
	return (tmp);
}

unsigned char			*ft_sb_fun7(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	unsigned char	*nor;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	nor = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	nor[0] = 0;
	while (st[i])
		nor = ft_ustrjoin(nor, ft_write(st[i++], len, 2147483648));
	if (s->fw > ft_ustrlen(nor))
		tmp = ft_ustrjoin(ft_psp(s->fw -
					ft_ustrlen(nor), ' '), nor);
	else
		tmp = ft_ustrjoin(tmp, nor);
	return (tmp);
}

unsigned char			*ft_sb_fun8(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	unsigned char	*nor;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	nor = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	nor[0] = 0;
	while (*len < s->prec)
		nor = ft_ustrjoin(nor, ft_write(st[i++], len, s->prec));
	tmp = ft_ustrjoin(tmp, ft_psp(s->fw - ft_ustrlen(nor), ' '));
	st[0] != 0 ? 0 : (tmp = ft_ustrjoin(tmp, ft_psp(s->prec, ' ')));
	len += ft_ustrlen(tmp);
	tmp = ft_ustrjoin(tmp, nor);
	return (tmp);
}
