/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/19 02:05:04 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wif(t_ftprintf *s, char *tmp)
{
	char	*tmp2;
	int		i;

	i = 0;
	s->fw <= s->prec ? (tmp2 = (char*)malloc()) :
		(tmp2 = (char*)malloc());
	while (i < (s->fw - (ft_strlen(tmp) + s->prec)))
	{
		s->flags[1] ? () : ();
	}
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	char	*tmp;

	tmp = ft_itoa_base((int)s->arg, 10);
	if (s->fw == 0 || s->fw < s->prec || ft_strlen(tmp) > s->fw)
		*col += ft_putstr(s->output);
	else
	{
		ft_wif(s);
		*col += ft_putstr(s->output);
	}
}
