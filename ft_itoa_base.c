/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:47:15 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/18 20:49:19 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(int value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base) < 0 ? -(value % base) : (value % base)];
}

char		*ft_itoa_base(int value, int base)
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
