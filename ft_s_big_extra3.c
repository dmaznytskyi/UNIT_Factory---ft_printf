/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 22:29:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 23:51:43 by dmaznyts         ###   ########.fr       */
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

unsigned char			*ft_sb_fun1(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	i = 0;
	while (st[i])
		tmp = ft_ustrjoin(tmp, ft_write(st[i++], len, 2147483648));
	if (s->fw > ft_ustrlen(tmp))
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw -
					ft_ustrlen(tmp), ' '));
	return (tmp);
}

unsigned char			*ft_sb_fun2(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	unsigned char	*nor;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	nor = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	nor[0] = 0;
	*len += ft_ustrlen(tmp);
	while (*len < s->prec)
		nor = ft_ustrjoin(nor, ft_write(st[i++], len, s->prec));
	if (s->fw > ft_ustrlen(nor))
		tmp = ft_ustrjoin(nor, ft_psp(s->fw -
					ft_ustrlen(nor), ' '));
	else
		tmp = ft_ustrjoin(tmp, nor);
	return (tmp);
}

unsigned char			*ft_sb_fun3(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (st[0] != 0)
		while (*len < s->prec)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++],
						len, s->prec));
	else
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, ' '));
	return (tmp);
}

unsigned char			*ft_sb_fun4(t_ftprintf *s, wchar_t *st, size_t *len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	tmp[0] = 0;
	if (st[0] != 0)
		while (*len < s->prec)
			tmp = ft_ustrjoin(tmp, ft_write(st[i++],
						len, s->prec));
	else
		tmp = ft_ustrjoin(tmp, ft_psp(s->fw, ' '));
	return (tmp);
}
