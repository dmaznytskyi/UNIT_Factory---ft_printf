/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:46:57 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:33:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nl(long long value, int base)
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

char		*ft_llltoa_base(long long value, int base)
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
