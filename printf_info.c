/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:39:16 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/23 12:32:55 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_info(t_ftprintf *s)
{
	printf("\n-INFO START----------\n");
//	printf("arg of first %% [%s]\n", (char*)s->arg);
	printf("start of first %% format [%zu], end [%zu]\n", s->f_start, s->f_end);
	printf("flags ['-' - %d, '0' - %d, '+' - %d, ' ' - %d, '#' - %d]\n",
				s->flags[0], s->flags[1], s->flags[2],
				s->flags[3], s->flags[4]);
	printf("fw [%zu] output [%s]\n", s->fw, s->output);
	s->ip ?	printf("prec [%zu] output [%s]\n", s->prec, s->output) : printf("no precision\n");
	printf("sm [%hhd] output [%s]\n", s->sm, s->output);
}
