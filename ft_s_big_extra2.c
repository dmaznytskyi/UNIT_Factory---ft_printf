/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 22:20:29 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 22:29:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_so(size_t *len, size_t v)
{
	*len += 1;
	return (ft_one(v));
}

unsigned char	*ft_st(size_t *len, size_t v)
{
	*len += 2;
	return (ft_two(v));
}

unsigned char	*ft_sh(size_t *len, size_t v)
{
	*len += 3;
	return (ft_three(v));
}

unsigned char	*ft_sf(size_t *len, size_t v)
{
	*len += 4;
	return (ft_four(v));
}
