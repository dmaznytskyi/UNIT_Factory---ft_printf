/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lultoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 20:19:55 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:56:00 by dmaznyts         ###   ########.fr       */
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

char		*ft_lultoa_base(unsigned long value, int base)
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
