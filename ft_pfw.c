/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 17:15:45 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/08 15:09:35 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pfw(t_ftprintf *s)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s->output[i] > '0' && s->output[i] <= '9')
		i++;
	tmp = ft_strsub(s->output, 0, i);
	s->output += i;
	s->fw = ft_atoi(tmp);
	s->f_start += i;
}
