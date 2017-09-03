/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_small_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 22:08:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 22:19:30 by dmaznyts         ###   ########.fr       */
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

char		ft_o_fl(t_ftprintf *s)
{
	char	c;

	c = ' ';
	s->flags[0] ? (s->flags[1] = 0) : 0;
	(s->flags[1] && !s->ip) ? (c = '0')
		: (c = ' ');
	(s->flags[4] && s->ip && s->prec > 0) ? (s->prec -= 1) : 0;
	return (c);
}

char		*ft_work(t_ftprintf *s, char *num, char *tmp, char c)
{
	if (!s->flags[0])
	{
		(s->flags[4] && s->prec <= ft_strlen(num)) ?
			(num = ft_strjoin("0", num)) : 0;
		if (c == '0')
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num) -
						ft_strlen(tmp), c));
		else
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num) -
						ft_strlen(tmp), c), tmp);
		tmp = ft_strjoin(tmp, num);
	}
	else
	{
		(s->flags[4] && s->prec <= ft_strlen(num)) ?
			(num = ft_strjoin("0", num)) : 0;
		if (s->prec == s->fw)
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), '0'));
		tmp = ft_strjoin(tmp, num);
		if (s->prec != s->fw)
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
	}
	return (tmp);
}
