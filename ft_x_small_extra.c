/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_small_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 21:19:56 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 21:40:38 by dmaznyts         ###   ########.fr       */
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

char		*ret_x_sm_z(t_ftprintf *s, unsigned int nu, char *num, char c)
{
	char	*tmp;

	tmp = ft_strdup("");
	(s->flags[4] && nu != 0) ? (tmp = ft_strjoin("0x", tmp)) : 0;
	if (c == '0')
		tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num) -
					ft_strlen(tmp), c));
	else
		tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num) -
					ft_strlen(tmp), c), tmp);
	tmp = ft_strjoin(tmp, num);
	return (tmp);
}

char		*ret_x_sm_o(t_ftprintf *s, unsigned int nu, char *num, char c)
{
	char	*tmp;

	tmp = ft_strdup("");
	(s->flags[4] && nu != 0) ? (num = ft_strjoin("0x", num)) : 0;
	tmp = ft_strjoin(tmp, num);
	tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
	return (tmp);
}

char		*ret_x_sm_t(t_ftprintf *s, unsigned int nu, char *num)
{
	char	*tmp;

	tmp = ft_strdup("");
	(s->flags[4] && nu != 0) ? (tmp = ft_strjoin("0x", tmp)) : 0;
	tmp = ft_strjoin(tmp, num);
	return (tmp);
}

char		*ret_x_sm_n(t_ftprintf *s, char *num)
{
	if (s->prec > ft_strlen(num))
		num = ft_strjoin(ft_add_cc(s->prec - ft_strlen(num), '0'), num);
	if (s->prec == 0 && num[0] == '0' && s->ip)
		ft_bzero(num, ft_strlen(num));
	return (num);
}
