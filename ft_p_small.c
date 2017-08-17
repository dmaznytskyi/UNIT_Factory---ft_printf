/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:06:14 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/17 18:03:55 by dmaznyts         ###   ########.fr       */
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
	size_t	i;

	adr = ft_strdup(ft_sultoa_base((unsigned long)s->arg, 16));
	tmp = ft_strdup("0x");
	if (!s->ip)
		i = 0;
	else if (s->prec && s->fw)
		i = s->prec - ft_strlen(adr);
	else
		i = s->fw - (s->prec + ft_strlen(adr));
	if ((s->fw > 0 && (s->prec > 0 || !s->ip)))
	{
		tmp = ft_strjoin(tmp, ft_add_cc(i, '0'));
		tmp = ft_strjoin(tmp, adr);
	}
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
//		if ((unsigned long)s->arg > 0 && ft_strlen(prec) == 2)
//			prec = ft_strjoin(prec, ft_sultoa_base((unsigned long)s->arg, 16));
		if (s->fw > ft_strlen(prec))
			tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(prec), ' '), prec);
		else
			tmp = prec;
	}
	*col += ft_putstr(tmp);
}
