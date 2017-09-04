/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:10:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:51:20 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nl(unsigned int value, int base)
{
	int	i;

	i = 0;
	while (value >= (unsigned int)base)
	{
		i++;
		value /= base;
	}
	i++;
	return (i);
}

char		*ft_luitoa_base(unsigned int value, int base)
{
	char	*tmp;
	int		i;
	int		l;
	char	*str;

	tmp = "0123456789ABCDEF";
	i = 0;
	l = nl(value, base);
	if (base < 2 || base > 16 || !(str = ft_strnew(l)))
		return (0);
	str[l] = '\0';
	l--;
	while (l >= i)
	{
		str[l] = tmp[(value % base)];
		l--;
		value /= base;
	}
	return (str);
}
