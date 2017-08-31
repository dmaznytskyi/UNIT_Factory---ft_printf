/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:11:34 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/31 18:11:48 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f(size_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= (size_t)base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char		*ft_sttoa_base(size_t value, int base)
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
