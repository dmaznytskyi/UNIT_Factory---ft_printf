/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:15:20 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 18:02:44 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_u_big(t_ftprintf *s, size_t *col)
{
	if (s->sm == 0 || s->sm > 4)
		s->sm = 3;
	ft_u_small(s, col);
}
