/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:59:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/31 16:47:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puts(unsigned char *s)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0')
		write(1, &s[i], 1);
}

void	ft_write_one(size_t val)
{
	write(1, &val, 1);
}

void	ft_write_two(size_t val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	s[3];

	o2 = val & 63;
	o1 = (val >> 6) & 31;
	s[0] = 192 | o1;
	s[1] = 128 | o2;
	s[2] = '\0';
	ft_puts(s);
}

void	ft_write_three(size_t val)
{
	unsigned char	o3 = val & 63;
	unsigned char	o2 = (val >> 6) & 63;
	unsigned char	o1 = (val >> 12) & 15;
	unsigned char	s[4];

	s[0] = 224 | o1;
	s[1] = 128 | o2;
	s[2] = 128 | o3;
	s[3] = '\0';
//	printf("[%d|%s][%d|%s][%d|%s]\n",s[0],ft_itoa_base(s[0],2),s[1],ft_itoa_base(s[1],2),s[2],ft_itoa_base(s[2],2));
	ft_puts(s);
}

void	ft_write_four(size_t val)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	s[5];

	o4 = val & 63;
	o3 = (val >> 6) & 63;
	o2 = (val >> 12) & 63;
	o1 = (val >> 18) & 7;
	s[0] = 240 | o1;
	s[1] = 128 | o2;
	s[2] = 128 | o3;
	s[3] = 128 | o4;
	s[4] = '\0';
	ft_puts(s);
}
