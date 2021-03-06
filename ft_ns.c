/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:14:05 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/26 16:05:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ftprintf	ft_ns(void)
{
	t_ftprintf	new;
	int			i;

	i = -1;
	new.f_start = 0;
	new.f_end = 0;
	while (++i < 5)
		new.flags[i] = 0;
	new.fw = 0;
	new.ip = 0;
	new.prec = 0;
	new.sm = 0;
	new.cl = 0;
	new.arg = 0;
	new.l = 0;
	return (new);
}
