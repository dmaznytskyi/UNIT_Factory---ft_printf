/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:09:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/23 20:30:21 by dmaznyts         ###   ########.fr       */
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

void	ft_d_big(t_ftprintf *s, size_t *col)
{
	long	nu;
	char	*num;
	char	*tmp;
	char	c;

	s->flags[1] ? (c = '0') : (c = ' ');
	nu = (long)s->arg;
	tmp = ft_strdup("");
	if (nu < 0 && nu != -2147483648)
	{
			tmp = ft_strjoin(tmp, "-");
			nu *= -1;
	}
	num = ft_lltoa_base(nu, 10);
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
		{
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num) - ft_strlen(tmp), c));
			tmp = ft_strjoin(tmp, num);
		}
		else
		{
			tmp = ft_strjoin(tmp, num);
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
		}
	}
	else
		tmp = num;
	*col += ft_putstr(tmp);
}
