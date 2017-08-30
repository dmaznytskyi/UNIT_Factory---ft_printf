/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 19:18:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/30 20:02:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(unsigned short int value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char		*ft_usitoa_base(unsigned short int value, int base)
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
