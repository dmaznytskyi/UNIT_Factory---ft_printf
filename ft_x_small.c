/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:15:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:53:29 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_casting(t_ftprintf *s)
{
	if (s->sm == 1)
		return (ft_sttoa_base((size_t)s->arg, 16));
	else if (s->sm == 2)
		return (ft_suimttoa_base((uintmax_t)s->arg, 16));
	else if (s->sm == 3 || s->sm == 4)
		return (ft_sultoa_base((unsigned long)s->arg, 16));
	else if (s->sm == 5)
		return (ft_usitoa_base((unsigned short int)s->arg, 16));
	else if (s->sm == 6)
		return (ft_uctoa_base((unsigned char)s->arg, 16));
	else
		return (ft_uitoa_base((unsigned int)s->arg, 16));
}

void		ft_ololo(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_toupper((int)s[i]);
		i++;
	}
}

void		ft_x_small(t_ftprintf *s, size_t *col)
{
	unsigned int	nu;
	char			*num;
	char			*tmp;
	char			c;

	s->flags[0] ? (s->flags[1] = 0) : 0;
	(s->flags[1] && !s->ip) ? (c = '0')
		: (c = ' ');
	nu = (intmax_t)s->arg;
	tmp = ft_strdup("");
	num = ft_casting(s);
	num = ret_x_sm_n(s, num);
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
			tmp = ret_x_sm_z(s, nu, num, c);
		else
			tmp = ret_x_sm_o(s, nu, num, c);
	}
	else
		tmp = ret_x_sm_t(s, nu, num);
	if (s->cl == 'X')
		ft_ololo(tmp);
	*col += ft_putstr(tmp);
}
