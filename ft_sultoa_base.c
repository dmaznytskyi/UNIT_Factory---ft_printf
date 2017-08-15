/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 14:18:33 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/15 17:42:53 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(unsigned long value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_sltoa_base(unsigned long value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(64)))
		return (0);
	if (base == 10 && value < 0)
		str[i++] = '-';
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
