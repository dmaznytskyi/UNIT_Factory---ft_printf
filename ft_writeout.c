/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 17:11:14 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/14 19:02:04 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writeout(t_ftprintf s, size_t *col)
{
	s.cl == 's' ? ft_s_small(s, col) : 0;
	s.cl == 'S' ? ft_s_big(s, col) : 0;
	s.cl == 'p' ? ft_p_small(s, col) : 0;
	s.cl == 'd' ? ft_d_small(s, col) : 0;
	s.cl == 'D' ? ft_d_big(s, col) : 0;
	s.cl == 'i' ? ft_i_small(s, col) : 0;
	s.cl == 'o' ? ft_o_small(s, col) : 0;
	s.cl == 'O' ? ft_o_big(s, col) : 0;
	s.cl == 'u' ? ft_u_small(s, col) : 0;
	s.cl == 'U' ? ft_u_big(s, col) : 0;
	s.cl == 'x' ? ft_x_small(s, col) : 0;
	s.cl == 'X' ? ft_x_big(s, col) : 0;
	s.cl == 'c' ? ft_c_small(s, col) : 0;
	s.cl == 'C' ? ft_c_big(s, col) : 0;
}
