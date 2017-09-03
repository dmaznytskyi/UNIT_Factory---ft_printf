/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:51:15 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 20:55:14 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	write, malloc, free, exit, stdarg_lib
*/

#include "ft_printf.h"

void	ft_out(size_t *i, size_t *cl, char c)
{
	write(1, &c, 1);
	*i += 1;
	*cl += 1;
}

int		ft_printf(const char *format, ...)
{
	va_list		p;
	size_t		i;
	size_t		count_letters;
	t_ftprintf	s;

	i = 0;
	count_letters = 0;
	va_start(p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (count_letters++);
			s = ft_ns();
			ft_findallmodifiers(format, &s, &i);
			if (!s.l)
				s.arg = va_arg(p, void*);
			ft_writeout(&s, &count_letters);
		}
		else
			ft_out(&i, &count_letters, format[i]);
	}
	return (count_letters);
}
