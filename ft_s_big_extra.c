/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:59:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/27 17:36:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_one(size_t val)
{
	size_t	octet;

	octet = val;
	write(1, &octet, 1);
}

void	ft_write_two(size_t val, unsigned int mask, size_t octet)
{
	unsigned char o1;
	unsigned char o2;

	o1 = ((val >> 6) << 27) >> 27;
	o2 = (val << 26) >> 26;
	octet = (mask >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void	ft_write_three(size_t val, unsigned int mask, size_t octet)
{
	unsigned char o3 = (val << 26) >> 26;
	unsigned char o2 = ((val >> 6) << 26) >> 26;
	unsigned char o1 = ((val >> 12) << 28) >> 28;

	octet = (mask >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o3;
	write(1, &octet, 1);
}

void	ft_write_four(size_t val, unsigned int mask, size_t octet)
{
	unsigned char o1;
	unsigned char o2;
	unsigned char o3;
	unsigned char o4;
	
	o4 = (val << 26) >> 26;
	o3 = ((val >> 6) << 26) >> 26;
	o2 = ((val >> 12) << 26) >> 26;
	o1 = ((val >> 18) << 29) >> 29;
	octet = (mask >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | o4;
	write(1, &octet, 1);
}
