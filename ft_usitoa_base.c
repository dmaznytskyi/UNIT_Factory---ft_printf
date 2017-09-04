/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 19:18:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:47:12 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nl(unsigned short value, int base)
{
	int	i;

	i = 0;
	while (value <= -base || value >= base)
	{
		i++;
		value /= base;
	}
	i++;
	return (i);
}

char		*ft_usitoa_base(unsigned short int value, int base)
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
	if (base == 10 && value < 0)
		str[i++] = '-';
	else
		l--;
	while (l >= i)
	{
		str[l] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
		l--;
		value /= base;
	}
	return (str);
}
