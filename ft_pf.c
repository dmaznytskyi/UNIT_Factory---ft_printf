/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:02:19 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/31 16:36:05 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf(t_ftprintf *s)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ft_isflag(s->output[i]))
		i++;
	tmp = ft_strsub(s->output, 0, i);
	if (ft_strchr(tmp, '-'))
		s->flags[0] = 1;
	if (ft_strchr(tmp, '0'))
		s->flags[1] = 1;
	if (ft_strchr(tmp, '+'))
		s->flags[2] = 1;
	if (ft_strchr(tmp, ' '))
		s->flags[3] = 1;
	if (ft_strchr(tmp, '#'))
		s->flags[4] = 1;
	s->output += (i);
	s->f_start += (i);
}
