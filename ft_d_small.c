/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/22 17:21:48 by dmaznyts         ###   ########.fr       */
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
		return (ft_sttoa_base((size_t)s->arg, 10));
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
	char	*tmp;

	tmp = ft_strdup("");
	if (prec > ft_strlen(num))
	{
		tmp = ft_strjoin(tmp, ft_add_cc(prec - ft_strlen(num), '0'));
		tmp = ft_strjoin(tmp, num);
	}
	else
		tmp = ft_strjoin(tmp, num);
	return (tmp);
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	char	*num;
	char	*tmp;
	char	c;
	int		i;

	i = 0;
	s->flags[1] ? (c = '0') : (c = ' ');
	if (s->flags[1] && s->ip)
		c = ' ';
	tmp = ft_strdup("");
	num = ft_casting(s);
	num = ft_ret_prec(s->prec, num);
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
		{
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num) - ft_strlen(tmp), c), tmp);
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
	*col += ft_putstr(tmp);
}
