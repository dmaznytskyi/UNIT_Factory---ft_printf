/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sultoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:55:46 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:49:21 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nl(unsigned long value, int base)
{
	int	i;

	i = 0;
	while (value >= (unsigned long)base)
	{
		i++;
		value /= base;
	}
	i++;
	return (i);
}

char		*ft_sultoa_base(unsigned long value, int base)
{
	char	*tmp;
	int		i;
	int		l;
	char	*str;

	tmp = "0123456789abcdef";
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
