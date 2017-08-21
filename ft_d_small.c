/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/21 15:17:16 by dmaznyts         ###   ########.fr       */
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
		return (0);
	else if (s->sm == 3)
		return (0);
	else if (s->sm == 4)
		return (0);
	else if (s->sm == 5)
		return (0);
	else if (s->sm == 6)
		return (0);
	else
		return (0);
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
	return (tmp);
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	int		nu;
	char	*num;
	char	*tmp;
	char	c;

	s->flags[1] ? (c = '0') : (c = ' ');
	if (s->flags[1] && s->ip)
		c = ' ';
	nu = (int)s->arg;
	tmp = ft_strdup("");
	if (nu < 0 && nu != -2147483648)
	{
			tmp = ft_strjoin(tmp, "-");
			nu *= -1;
	}
	num = ft_itoa_base(nu, 10);
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
