/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:13:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/26 18:18:07 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	job(char a, t_ftprintf *st)
{
	if (a != '\0')
	{
		st->cl = 'c';
		st->arg = (void*)0;
		st->l = a;
	}
	else
		st->cl = 0;
}

int			ft_cv(char a, t_ftprintf *st)
{
	char	*s;
	int		i;

	s = "sSpdDioOuUxXcC";
	i = 0;
	while (a != s[i] && i < 14)
		i++;
	if (i == 14)
	{
		if (ft_is_sm(a) || ft_isdigit(a) || ft_isflag(a) || a == '.')
			return (0);
		else
		{
			job(a, st);
			return (1);
		}
	}
	else
	{
		st->cl = s[i];
		return (1);
	}
}
