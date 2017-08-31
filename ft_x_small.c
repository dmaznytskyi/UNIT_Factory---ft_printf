/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:15:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/31 16:29:49 by dmaznyts         ###   ########.fr       */
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

static char	*ft_casting(t_ftprintf *s)
{
	if (s->sm == 1)
		return (ft_sttoa_base((size_t)s->arg, 16));
	else if (s->sm == 2)
		return (ft_uimttoa_base((uintmax_t)s->arg, 16));
	else if (s->sm == 3 || s->sm == 4)
		return (ft_sultoa_base((unsigned long)s->arg, 16));
	else if (s->sm == 5)
		return (ft_usitoa_base((unsigned short int)s->arg, 16));
	else if (s->sm == 6)
		return (ft_uctoa_base((unsigned char)s->arg, 16));
	else
		return (ft_uitoa_base((unsigned int)s->arg, 16));
}

void	ft_x_small(t_ftprintf *s, size_t *col)
{
	unsigned int	nu;
	char			*num;
	char			*tmp;
	char			c;

	s->flags[1] ? (c = '0') : (c = ' ');
	nu = (unsigned int)s->arg;
	tmp = ft_strdup("");
	num = ft_casting(s);//ft_uitoa_base(nu, 16);
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
		{
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
			tmp = ft_strjoin(tmp, num);
		}
		else
		{
			tmp = ft_strjoin(tmp, num);
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
		}
	}
	else
		tmp = ft_strjoin(tmp, num);
	s->flags[4] ? (tmp = ft_strjoin("0x", tmp)) : 0;
	*col += ft_putstr(tmp);
}
