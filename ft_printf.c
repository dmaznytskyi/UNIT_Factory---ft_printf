/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:51:15 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/11 14:50:45 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	write, malloc, free, exit, stdarg_lib
*/

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		p;
	int			i;
	long		count_letters;
	t_ftprintf	s;

	i = 0;
	count_letters = 0;
	va_start(p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				i++;
				s = ft_ns(va_arg(p, void*));
				ft_findallmodifiers(format, &s, &i);
				ft_writeout(s, &count_letters);
			}
			else
			{
				write(1, "%", 1);
				i++;
				count_letters++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count_letters++;
		}
	}
	return (count_letters);
}
