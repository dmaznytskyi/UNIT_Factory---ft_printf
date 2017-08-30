/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luctoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 20:00:18 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/30 20:00:24 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(unsigned char value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char		*ft_luctoa_base(unsigned char value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
