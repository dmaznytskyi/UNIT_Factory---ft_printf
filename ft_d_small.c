/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 00:57:31 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_casting(t_ftprintf *s)
{
	if (s->sm == 1)
		return (ft_lltoa_base((long)s->arg, 10));
	else if (s->sm == 2)
		return (ft_imttoa_base((intmax_t)s->arg, 10));
	else if (s->sm == 3)
		return (ft_llltoa_base((long long)s->arg, 10));
	else if (s->sm == 4)
		return (ft_lltoa_base((long)s->arg, 10));
	else if (s->sm == 5)
		return (ft_sitoa_base((short int)s->arg, 10));
	else if (s->sm == 6)
		return (ft_ctoa_base((char)s->arg, 10));
	else
		return (ft_itoa_base((int)s->arg, 10));
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	char	*num;
	char	*tmp;
	char	c;
	int		or_num;

	tmp = 0;
	or_num = (int)s->arg;
	c = ft_fl_w(s);
	num = ft_casting(s);
	num = ft_d_sm_n(s, num, 0);
	(s->flags[3] && !s->flags[0] && s->fw <= s->prec) ? (tmp = ft_strdup(" "))
		: (tmp = ft_strdup(""));
	if (s->flags[2] && num[0] != '-' && (!s->flags[1] || s->fw < ft_strlen(num)
				|| s->fw - ft_strlen(num) == 1))
		num = ft_strjoin("+", num);
	if (ft_strlen(num) < s->fw)
		tmp = ft_tmp_ret(s, num, tmp, c);
	else
		tmp = ft_strjoin(tmp, num);
	if (!s->ip && s->flags[2] && tmp[0] != '+' && or_num >= 0 && tmp[0] != ' ')
		tmp[0] = '+';
	if (s->flags[1] && s->flags[3] && tmp[0] == '0')
		tmp[0] = ' ';
	*col += ft_putstr(tmp);
}
