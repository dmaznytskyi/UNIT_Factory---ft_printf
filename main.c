/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/03 20:57:23 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t *a = L"ድመቶች ሰዎች አልወደውም.";
	wchar_t *b = L"";
	int i = 0;
	i = printf("|%-7.4S|\t", b);
	printf("ret: %d\n", i);
	i = ft_printf("|%-7.4S|\t", b);
	printf("ret: %d\n", i);
	printf("%s\n", ft_itoa_base((int)*b, 2));
//	printf("origin	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
//	ft_printf("ft	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
	return (0);
}
