/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:18:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/30 17:00:27 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_biggest(t_ftprintf *st, char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == 'z')
			st->sm = 1;
		else if (s[cnt] == 'j' && (st->sm > 1 || !st->sm))
			st->sm = 2;
		else if (s[cnt] == 'l' && st->sm == 4)
			st->sm = 3;
		else if (s[cnt] == 'l' && (st->sm >= 3 || !st->sm))
			st->sm = 4;
		else if (s[cnt] == 'h' && (st->sm > 5 || !st->sm))
			st->sm = 5;
		else if (s[cnt] == 'h' && st->sm == 5)
			st->sm = 6;
		cnt++;
	}
}

void	ft_psm(t_ftprintf *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s->output[0] != '\0')
	{
		while (ft_is_sm(s->output[i]))
			i++;
		tmp = ft_strsub(s->output, 0, i);
		s->output += i;
		s->f_start += i;
		if (s->output == '\0')
			free(s->output);
		find_biggest(s, tmp);
	}
}

/*
** пояснение за sm:
** z	-> 1
** j	-> 2
** ll	-> 3
** l	-> 4
** h	-> 5
** hh	-> 6
*/
