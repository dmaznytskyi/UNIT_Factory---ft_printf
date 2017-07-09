/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 10:13:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/09 15:35:13 by dmaznyts         ###   ########.fr       */
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
		if (a == 'h' || a == 'l' || a == 'j' || a == 'z')
			return (0);
		else
		{
			st->cl = a;
			return (1);
		}
	}
	else
	{
		st->cl = s[i];
		return (1);
	}
}
