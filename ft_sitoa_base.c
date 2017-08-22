/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:14:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/22 17:16:02 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(short int value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_sitoa_base(short int value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		str[i++] = '-';
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
