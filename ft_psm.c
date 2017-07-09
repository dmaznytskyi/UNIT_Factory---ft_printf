/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:18:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/09 15:06:07 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_biggest(t_ftprintf *st, char *s)
{
	if (ft_strstr(s, "z"))
		st->sm = 1;
	if (ft_strstr(s, "j"))
		st->sm = 2;
	if (ft_strstr(s, "ll"))
		st->sm = 3;
	if (ft_strstr(s, "l"))
		st->sm = 4;
	if (ft_strstr(s, "h"))
		st->sm = 5;
	if (ft_strstr(s, "hh"))
		st->sm = 6;
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
		s->f_start += i;
		if (s->output == '\0')
			free(s->output);
		find_biggest(s, tmp);
	}
}
