/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/29 21:35:44 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t *a = L"米";
	printf("origin	|%S|%d|%s\t|%s|\n", a,*a,ft_itoa_base(*a,2), "lol");
	ft_printf("ft	|%S|%d|%s\t|%s|\n", a,*a,ft_itoa_base(*a,2), "lol");
	return (0);
}
