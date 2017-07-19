/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/19 18:57:25 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wif(t_ftprintf *s, char *tmp)
{
	char	*tmp2;
	size_t	i;
	size_t	numlen;

	i = 0;
	numlen = ft_strlen(tmp);
	if (s->fw > numlen || s->prec > numlen)
	{
		s->fw <= s->prec ? (tmp2 = (char*)malloc(sizeof(char) * s->prec)) :
			(tmp2 = (char*)malloc(sizeof(char) * s->fw));
	}
	else
		tmp2 = (char*)malloc(sizeof(char) * numlen);
	while (i < (s->fw - s->prec))
	{
		tmp2[i] = ' ';
		i++;
	}
	while (i < (s->fw - (ft_strlen(tmp))))
	{
		tmp2[i] = '0';
		i++;
	}
	tmp2[i] = '\0';
	s->output = (char*)malloc(sizeof(char) * s->fw + 1);
	s->output = ft_strcat(tmp2, tmp);
}

void		ft_d_small(t_ftprintf *s, size_t *col)
{
	char	*tmp;

	tmp = ft_itoa_base((int)s->arg, 10);
	if (s->fw == 0 || s->fw < s->prec || ft_strlen(tmp) > s->fw)
		*col += ft_putstr(s->output);
	else
	{
		ft_wif(s, tmp);
		*col += ft_putstr(s->output);
	}
}
