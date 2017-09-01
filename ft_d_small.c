/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/01 23:23:35 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_cc(size_t num, char c)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * num + 1);
	while (i < num)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_casting(t_ftprintf *s)
{
	if (s->sm == 1)
		return (ft_sttoa_base((size_t)s->arg, 10, (long long int)s->arg < 0));
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

static char	*ft_ret_prec(size_t prec, char *num)
{
	if (prec > ft_strlen(num))
		num = ft_strjoin(ft_add_cc(prec - ft_strlen(num), '0'), num);
	return (num);
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	char	*num;
	char	*tmp;
	char	c;
	int		or_num;
	size_t	irepeta;

	or_num = (int)s->arg;
	if (s->ip)
		s->flags[1] = 0;
	if (s->flags[2])
		s->flags[3] = 0;
	if (s->flags[0])
		s->flags[1] = 0;
	s->flags[1] ? (c = '0') : (c = ' ');
	if (s->flags[1] && s->ip)
		c = ' ';
//	tmp = ft_strdup("");
	num = ft_casting(s);
	if (num[0] == '-' || s->flags[2])
		s->flags[3] = 0;
	(s->flags[3] && !s->flags[0] && s->fw <= s->prec) ? (tmp = ft_strdup(" ")) : (tmp = ft_strdup(""));
	if (s->prec == 0 && num[0] == '0' && s->ip)
		ft_bzero(num, ft_strlen(num));
	if ((num[0] == '-' && (s->ip || (s->flags[1] && s->fw > ft_strlen(num)))))
	{
		if (s->ip && s->prec < s->fw)
			irepeta = s->prec;
		else
			irepeta = s->fw;
		if (s->ip || (s->flags[1] && s->fw > ft_strlen(num)))
			ft_memmove(num, num + 1, ft_strlen(num));
		if ((s->ip && s->prec >= s->fw) || irepeta == s->prec)
			num = ft_ret_prec(irepeta, num);
		else
			num = ft_ret_prec(irepeta - 1, num);
		if (s->ip || (s->flags[1] && s->fw > ft_strlen(num)))
			num = ft_strjoin("-", num);
	}
	else if (s->ip && ft_isdigit((int)num[0]))
		num = ft_ret_prec(s->prec, num);
	if (s->flags[2] && num[0] != '-' && (!s->flags[1] || s->fw < ft_strlen(num)) && or_num >= 0)
		num = ft_strjoin("+", num);
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
		{
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num), c), tmp);
			tmp = ft_strjoin(tmp, num);
		}
		else
		{
			tmp = ft_strjoin(tmp, num);
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
		}
	}
	else
		tmp = ft_strjoin(tmp, num);
	if (!s->ip && s->flags[2] && tmp[0] != '+' && or_num >= 0)
		tmp[0] = '+';
	if (s->flags[1] && s->flags[3] && tmp[0] == '0')
		tmp[0] = ' ';
	*col += ft_putstr(tmp);
}
