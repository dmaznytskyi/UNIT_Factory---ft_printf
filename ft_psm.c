/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:18:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/23 13:13:34 by dmaznyts         ###   ########.fr       */
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

void	ft_count_sm(t_ftprintf *st, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'h' && st->sm == 5)
			st->sm = 6;
		if (s[i] == 'l' && st->sm == 4)
			st->sm = 3;
		if (s[i] == 'h' && st->sm == 6)
			st->sm = 5;
		if (s[i] == 'l' && st->sm == 3)
			st->sm = 4;
		i++;
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
		ft_count_sm(s, tmp);
	}
}
