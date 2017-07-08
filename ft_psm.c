/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:18:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/08 15:34:10 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO дописать выбор самого большого флага (лонг итд)

void	find_biggest(t_ftprintf *st, char *s)
{
	
}

void	ft_psm(t_ftprintf *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s->output[0] != '\0')
	{
		while (s->output[i] != '\0')
			i++;
		tmp = ft_strsub(s->output, 0, i);
		s->output += i;
		if (s->output == '\0')
			free(s->output);
		if (ft_strlen(tmp) > 2 || tmp[0] != tmp[1])
			find_biggest(s, tmp);
		else
			s->sm = 'l';
	}
}
