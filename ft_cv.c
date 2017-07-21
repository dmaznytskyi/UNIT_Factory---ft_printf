/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:13:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/21 14:03:06 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cv(char a, t_ftprintf *st)
{
	char	*s;
	int		i;

	s = "sSpdDioOuUxUcC";
	i = 0;
	while (a != s[i] && i < 14)
		i++;
	if (i == 14)
	{
		if (ft_is_sm(a) || ft_isdigit(a) || ft_isflag(a) || a == '.')
			return (0);
		else
		{
			st->cl = 'c';
			st->arg = (void*)0;
			st->l = a;
			return (1);
		}
	}
	else
	{
		st->cl = s[i];
		return (1);
	}
}
