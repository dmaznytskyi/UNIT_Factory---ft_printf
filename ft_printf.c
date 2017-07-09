/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:51:15 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/09 18:03:55 by dmaznyts         ###   ########.fr       */
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
	t_ftprintf	head;

	i = 0;
	count_letters = 0;
	va_start(p, format);
	while (format[i] != '%' && format[i] != '\0')
		i++;
	count_letters = ft_putstr_until(format, i);
	if (format[i] == '\0')
		return (count_letters);
	i++;
//	if (format[i] == '%')
//		write(1, &format[i++], 1);
	head = ft_ns(va_arg(p, void*));
	ft_findallmodifiers(format, &head, i);
//	count_letters += ft_printf(format + head.f_end, p);
	return (count_letters);
}
