/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 21:41:58 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 22:03:55 by dmaznyts         ###   ########.fr       */
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

static char	*ft_ret_prec(size_t prec, char *num)
{
	if (prec > ft_strlen(num))
		num = ft_strjoin(ft_add_cc(prec - ft_strlen(num), '0'), num);
	return (num);
}

char		ft_fl_w(t_ftprintf *s)
{
	char	c;

	c = ' ';
	if (s->ip)
		s->flags[1] = 0;
	if (s->flags[2])
		s->flags[3] = 0;
	if (s->flags[0])
		s->flags[1] = 0;
	s->flags[1] ? (c = '0')
		: (c = ' ');
	if (s->flags[1] && s->ip)
		c = ' ';
	return (c);
}

char		*ft_d_sm_n(t_ftprintf *s, char *num, size_t irepeta)
{
	if (num[0] == '-' || s->flags[2])
		s->flags[3] = 0;
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
	return (num);
}

char		*ft_tmp_ret(t_ftprintf *s, char *num, char *tmp, char c)
{
	if (!s->flags[0])
	{
		if (s->flags[2] && num[0] != '+' && s->fw - ft_strlen(num) == 1
				&& num[0] != '-')
			num = ft_strjoin("+", num);
		else
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num), c), tmp);
		tmp = ft_strjoin(tmp, num);
	}
	else
	{
		tmp = ft_strjoin(tmp, num);
		tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
	}
	return (tmp);
}
