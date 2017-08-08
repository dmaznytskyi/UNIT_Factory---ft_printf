/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:59:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/08 12:12:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_one(size_t val)
{
	unsigned char	*s;

	s = (unsigned char*)malloc(sizeof(unsigned char) * 2);
	s[0] = val;
	s[1] = '\0';
	return (s);
}

unsigned char	*ft_two(size_t val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	*s;

	s = (unsigned char*)malloc(sizeof(unsigned char) * 3);
	o2 = val & 63;
	o1 = (val >> 6) & 31;
	s[0] = 192 | o1;
	s[1] = 128 | o2;
	s[2] = '\0';
	return (s);
}

unsigned char	*ft_three(size_t val)
{
	unsigned char	o3 = val & 63;
	unsigned char	o2 = (val >> 6) & 63;
	unsigned char	o1 = (val >> 12) & 15;
	unsigned char	*s;

	s = (unsigned char*)malloc(sizeof(unsigned char) * 4);
	s[0] = 224 | o1;
	s[1] = 128 | o2;
	s[2] = 128 | o3;
	s[3] = '\0';
//	printf("[%d|%s][%d|%s][%d|%s]\n",s[0],ft_itoa_base(s[0],2),s[1],ft_itoa_base(s[1],2),s[2],ft_itoa_base(s[2],2));
	return (s);
}

unsigned char	*ft_four(size_t val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	*s;

	s = (unsigned char*)malloc(sizeof(unsigned char) * 5);
	o4 = val & 63;
	o3 = (val >> 6) & 63;
	o2 = (val >> 12) & 63;
	o1 = (val >> 18) & 7;
	s[0] = 240 | o1;
	s[1] = 128 | o2;
	s[2] = 128 | o3;
	s[3] = 128 | o4;
	s[4] = '\0';
	return (s);
}
