/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lultoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 20:19:55 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/30 20:21:30 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(unsigned long value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value >= (unsigned long)base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[value % base];
}

char		*ft_lultoa_base(unsigned long value, int base)
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
