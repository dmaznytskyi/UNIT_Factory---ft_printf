/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_small_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 21:06:57 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 21:18:51 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_psp(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

size_t			s_ret_prec(t_ftprintf *s)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;
	size_t	len;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * s->prec + 1);
	tmp2 = (char*)s->arg;
	s->prec > 0 ? (len = s->prec)
		: (len = ft_strlen(tmp2));
	if (s->prec == 0 && s->ip)
		return (ft_psp(' ', s->fw - ft_strlen(tmp2)));
	while (i < len && i < ft_strlen(tmp2))
	{
		(tmp2[i] && ft_strlen(tmp2) > i) ? (tmp[i] = tmp2[i])
			: (tmp[i] = ' ');
		i++;
	}
	return (ft_putstr(tmp));
}
