/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/14 22:38:12 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
//	wchar_t *a = L"ድመቶች ሰዎች አልወደውም.";
//	wchar_t *b = L"";
	int i = 0;
/*	printf("-------------------------------------------------\n");
	printf("|%%5.3S|\t|%%3.5S|\t|%%7S|\t\t\t|%%7.3S|\n");
	i = printf("|%5.3S|\t|%3.5S|\t|%7S|\t|%7.3S|",a,a,a,L"");
	printf("\tret: %d\n", i);
	i = ft_printf("|%5.3S|\t|%3.5S|\t|%7S|\t|%7.3S|",a,a,a,L"");
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
	printf("|%%.3S|\t|%%2.5S|\t|%%.10S|\t\t|%%.5S|\n");
	i = printf("|%.3S|\t|%2.5S|\t|%.10S|\t\t|%.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	i = ft_printf("|%.3S|\t|%2.5S|\t|%.10S|\t\t|%.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
	printf("|%%-7.5S||%%-2.5S||%%-.10S|\t|%%-.5S|\n");
	i = printf("|%-7.5S|\t|%-2.5S|\t|%-.10S|\t\t|%-.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	i = ft_printf("|%-7.5S|\t|%-2.5S|\t|%-.10S|\t\t|%-.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
	printf("|%%-07.5S||%%-02.5S||%%-020S|\t\t|%%-0.5S|\n");
	i = printf("|%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	i = ft_printf("|%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|",a,a,a,b);
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
//	printf("origin	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
//	ft_printf("ft	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
*/
	i = printf("|%.10S|\n",L"ድመቶች ሰዎች አልወደውም.");
	i = ft_printf("|%.10S|\n",L"ድመቶች ሰዎች አልወደውም.");
	return (0);
}
