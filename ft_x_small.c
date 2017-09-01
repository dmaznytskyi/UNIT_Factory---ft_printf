/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 21:15:41 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/01 23:25:14 by dmaznyts         ###   ########.fr       */
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
		return (ft_sttoa_base((size_t)s->arg, 16, 0));
	else if (s->sm == 2)
		return (ft_suimttoa_base((uintmax_t)s->arg, 16));
	else if (s->sm == 3 || s->sm == 4)
		return (ft_sultoa_base((unsigned long)s->arg, 16));
	else if (s->sm == 5)
		return (ft_usitoa_base((unsigned short int)s->arg, 16));
	else if (s->sm == 6)
		return (ft_uctoa_base((unsigned char)s->arg, 16));
	else
		return (ft_uitoa_base((unsigned int)s->arg, 16));
}

void	ft_ololo(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_toupper((int)s[i]);
		i++;
	}
}

void	ft_x_small(t_ftprintf *s, size_t *col)
{
	unsigned int	nu;
	char			*num;
	char			*tmp;
	char			c;

	s->flags[0] ? (s->flags[1] = 0) : 0;
	s->flags[1] ? (c = '0') : (c = ' ');
	nu = (intmax_t)s->arg;
	tmp = ft_strdup("");
	num = ft_casting(s);
	if (s->prec > ft_strlen(num))
		num = ft_strjoin(ft_add_cc(s->prec - ft_strlen(num), '0'), num);
	if (s->prec == 0 && num[0] == '0' && s->ip)
		ft_bzero(num, ft_strlen(num));
	if (ft_strlen(num) < s->fw)
	{
		if (!s->flags[0])
		{
			(s->flags[4] && nu != 0) ? (tmp = ft_strjoin("0x", tmp)) : 0;
			if (c == '0')
				tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num) -
							ft_strlen(tmp), c));
			else
				tmp = ft_strjoin(ft_add_cc(s->fw - ft_strlen(num) -
							ft_strlen(tmp), c), tmp); 
			tmp = ft_strjoin(tmp, num);
		}
		else
		{
			(s->flags[4] && nu != 0) ? (num = ft_strjoin("0x", num)) : 0;
			tmp = ft_strjoin(tmp, num);
			tmp = ft_strjoin(tmp, ft_add_cc(s->fw - ft_strlen(num), c));
		}
	}
	else
	{
		(s->flags[4] && nu != 0) ? (tmp = ft_strjoin("0x", tmp)) : 0;
		tmp = ft_strjoin(tmp, num);
	}
	if (s->cl == 'X')
		ft_ololo(tmp);
	*col += ft_putstr(tmp);
}
