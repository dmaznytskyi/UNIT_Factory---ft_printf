/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:52:05 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/08 15:02:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_until(char const *s, size_t end)
{
	size_t	i;

	i = -1;
	if (!s)
		return (-1);
	while (++i < end)
		write(1, &s[i], 1);
	return (i);
}
