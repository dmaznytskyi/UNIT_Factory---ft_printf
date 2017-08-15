/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:06:14 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/15 17:27:53 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_cc(size_t num, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * num + 1);
	while (i < num)
	{
		tmp[i] = c;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_p_small(t_ftprintf *s, size_t *col)
{
	char	*tmp;

	tmp = ft_strdup("0x");
	if (s->prec || s->fw)
		tmp = ft_strjoin(tmp, ft_sltoa_base((long)s->arg, 16));
	*col += ft_putstr(tmp);
}
