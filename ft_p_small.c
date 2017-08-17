/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:06:14 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/17 13:50:05 by dmaznyts         ###   ########.fr       */
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

static char	*ft_ret_prec(t_ftprintf *s)
{
	char	*tmp;
	char	*adr;

	adr = ft_strdup(ft_sultoa_base((unsigned long)s->arg, 16));
	tmp = ft_strdup("0x");
	if (s->ip && s->prec > 0 && s->fw > 0 && adr > 0)
	{
		tmp = ft_strjoin(tmp, ft_add_cc(s->fw - 2 - ft_strlen(adr), '0'));
		tmp = ft_strjoin(tmp, adr);
	}
	if (s->fw > 0 && ft_strlen(tmp) == 2)
		tmp = ft_strjoin(tmp, adr);
	return (tmp);
}

void	ft_p_small(t_ftprintf *s, size_t *col)
{
	char	*tmp;
	char	*prec;

	prec = ft_ret_prec(s);
	tmp = ft_strdup("");
	if (s->flags[0])
	{
		tmp = ft_strjoin(tmp, prec);
		tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(tmp), ' '));
	}
	else
	{
		if (s->fw > ft_strlen(prec))
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(prec), ' '), prec);
		else
			tmp = prec;
	}
	*col += ft_putstr(tmp);
}
