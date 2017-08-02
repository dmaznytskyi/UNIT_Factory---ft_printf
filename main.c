/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/02 02:56:17 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t *a = L"ድመቶች ሰዎች አልወደውም.";
	printf("origin	|%5.3S|\t|\n", a,*a,ft_itoa_base(*a,2), "lol");
	ft_printf("ft	|%5.3S|\t|\n", a,*a,ft_itoa_base(*a,2), "lol");
	return (0);
}
