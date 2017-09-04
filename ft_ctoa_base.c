/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:15:48 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:54:22 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nl(char value, int base)
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

char		*ft_ctoa_base(char value, int base)
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
