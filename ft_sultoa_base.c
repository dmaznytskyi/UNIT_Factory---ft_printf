/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:55:46 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/16 15:03:34 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(long value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[value % base];
}

char		*ft_sultoa_base(unsigned long value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(64)))
		return (0);
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
