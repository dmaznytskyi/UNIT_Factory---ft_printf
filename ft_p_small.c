/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:06:14 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/16 17:46:16 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_cc(size_t num, char c)
{
	char	*tmp;
	size_t	i;

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
/*	char	*adr;

	adr = ft_sultoa_base((unsigned long)s->arg, 16);
*/	tmp = ft_strdup("0x");
/*	if (s->flags[0])
	{
		if (s->prec > 0)
		{
			
		}
	}
	else
	{}
*/	tmp = ft_strjoin(tmp, ft_sultoa_base((unsigned long)s->arg, 16));
	tmp = ft_strjoin(tmp, ft_add_cc(0, '0'));
	*col += ft_putstr(tmp);
}
