/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/03 22:41:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
//	wchar_t *a = L"ድመቶች ሰዎች አልወደውም.";
//	wchar_t *b = L"";
	int i = 0;
/*	printf("-------------------------------------------------\n");
	printf("|%%.0p|\t\t|%%6p|\t\t|%%6.p|\t|%%10.6p|\n");
	i = printf("|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|",NULL,NULL,NULL,NULL);
	printf("\tret: %d\n", i);
	i = ft_printf("|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|",NULL,NULL,NULL,NULL);
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
	printf("|%%12p||%%17p|\t|%%-22p|\n");
	i = printf("|%12p||%17p|\t|%-22p|",a,a,a);
	printf("\tret: %d\n", i);
	i = ft_printf("|%12p||%17p|\t|%-22p|",a,a,a);
	printf("\tret: %d\n", i);
	printf("-------------------------------------------------\n");
	printf("|%%.0p||%%6p|\t|%%6.p||%%.20p|\n");
	i = printf("|%.0p||%6p|\t|%6.p||%.20p|",a,a,a,a);
	printf("\tret: %d\n", i);
	i = ft_printf("|%.0p||%6p|\t|%6.p||%.20p|",a,a,a,a);
	printf("\tret: %d\n", i);
//	printf("-------------------------------------------------\n");
//	printf("|%%-07.5S||%%-02.5S||%%-020S|\t\t|%%-0.5S|\n");
//	i = printf("|%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|",a,a,a,b);
//	printf("\tret: %d\n", i);
//	i = ft_printf("|%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|",a,a,a,b);
//	printf("\tret: %d\n", i);
//	printf("-------------------------------------------------\n");
//	printf("origin	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
//	ft_printf("ft	|%-5.3S|\t\t|%-3.5S|\t|%-7S|\t|%-7.3S|\n",a,a,a,L"");
*/
//	char *tmp = ft_strdup("123");
//	i = printf("|%S|%ls|\n",L"©©",L"@©");
//	i = ft_printf("|%S|%ls|\n",L"©©",L"@©");
//	i = printf("%.3p\n", a);

//	i = printf("%%-12.8.5i|\t|%%12.-8.5i|\t|%%-12.-8.5i|\t|%%-12.-8.-5i|\t\n");
//	i = printf("|%-12.8.5i|\t|%12.-8.5i|\t|%-12.-8.5i|\t|%-12.-8.-5i|\t\n",42,42,42,42);
//	i = ft_printf("|%-12.8.5i|\t|%12.-8.5i|\t|%-12.-8.5i|\t|%-12.-8.-5i|\t\n",42,42,42,42);
//	i = printf("%ll.15.12d\n", -42);
//	i = ft_printf("%ll.15.12d\n", -42);
//	i = printf("|%20hd|\t|%20hhhd|\t|%20ld|\n", "4294967296","4294967296","4294967296");
//	i = ft_printf("|%20hd|\t|%20hhhd|\t|%20ld|\n", "4294967296","4294967296","4294967296");
//	i = ft_printf("|%20hd|\t|%20hhd|\t|%20d|\n", 4294967296,4294967296,4294967296);
//	i = ft_printf("|%20hd|\t|%20hhd|\t|%20d|\n", 4294967296,4294967296,4294967296);
//	i = printf("%S\n", 0);
//	i = ft_printf("%S\n", 0);
//	i = printf("%x\n", 42);
//	i = ft_printf("%x\n", 42);
//	i = printf("%jX, %jX\n", 0, ULLONG_MAX);
//	i = ft_printf("%jX, %jX\n", 0, ULLONG_MAX);
	
	
	
//	i = printf("{%-13p}\n", &strlen);
//	i = ft_printf("{%-13p}\n", &strlen);

//	i = printf("%lp", 42);
//	i = ft_printf("%lp", 42);
//	i = printf("%#.o %#.0o\n", 0, 0);
//	i = ft_printf("%#.o %#.0o\n", 0, 0);
//	i = printf("%#.o %#.0o\n", 9, 9);
//	i = ft_printf("%#.o %#.0o\n", 9, 9);

//	i = printf("%.4O\n", 42);
//	i = ft_printf("%.4O\n", 42);
//	i = printf("%#o\n", 42);
//	i = ft_printf("%#o\n", 42);

//	i = printf("%.d, %.0d\n", 0, 0);
//	i = ft_printf("%.d, %.0d\n", 0, 0);

//	i = printf("%hhO, %hhO\n", 0, USHRT_MAX);
//	i = ft_printf("%hhO, %hhO\n", 0, USHRT_MAX);

//	i = printf("%ld\n", -2147483649);
//	i = ft_printf("%ld\n", -2147483649);

//	i = printf("%05d\n", -42);
//	i = ft_printf("%05d\n", -42);

//	i = printf("%15.4d\n", -42);
//	i = ft_printf("%15.4d\n", -42);
	
//	i = printf("{% 03d}\n", 0);
//	i = ft_printf("{% 03d}\n", 0);

//	i = printf("%zi\n", LLONG_MIN);
//	i = ft_printf("%zi\n", LLONG_MIN);

//	i = printf("{%+03d}\n", 123456);
//	i = ft_printf("{%+03d}\n", 123456);

//	i = printf("{%05.s}\n", 0);
//	i = ft_printf("{%05.s}\n", 0);

//	i = printf("%.4s\n", "42");
//	i = ft_printf("%.4s\n", "42");

//	i = printf("%15.4s\n", "42");
//	i = ft_printf("%15.4s\n", "42");

//	i = printf("[%4.s]\n", "42");
//	i = ft_printf("[%4.s]\n", "42");

//	printf("%%#.3o\n");
//	i = printf("or %#.3o\n", 1);
//	i = ft_printf("ft %#.3o\n", 1);

//	i = printf("{%05.S}\n", L"42 c est cool");
//	i = ft_printf("{%05.S}\n", L"42 c est cool");

//	printf("[%%15.4S] _ 我是一只猫。\n");
//	i = printf("[%15.4S]\n", L"我是一只猫。");
//	i = ft_printf("[%15.4S]\n", L"我是一只猫。");

//	printf("[%%4.15S] _ 我是一只猫。\n");
//	i = printf("[%4.15S]\n", L"我是一只猫。");
//	i = ft_printf("[%4.15S]\n", L"我是一只猫。");

//	printf("[%%4.S] _ 我是一只猫。\n");
//	i = printf("[%4.S]\n", L"我是一只猫。");
//	i = ft_printf("[%4.S]\n", L"我是一只猫。");
/*
	i = printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	i = ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	i = printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &i, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	i = ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &i, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');

	printf("{%%30S}\n");	
	i = printf("{%30S}", L"我是一只猫。");
	printf("\t%d\n", i);
	i = ft_printf("{%30S}", L"我是一只猫。");
	printf("\t%d\n", i);
	printf("{%%-30S}\n");
	i = printf("{%-30S}", L"我是一只猫。");
	printf("\t%d\n", i);
	i = ft_printf("{%-30S}", L"我是一只猫。");
	printf("\t%d\n", i);
*/	

//	i = printf("{%030S}\n", L"我是一只猫。");
//	i = ft_printf("{%030S}\n\n", L"我是一只猫。");
/*
	i = printf("\n{%5p}\n", 0);
	i = ft_printf("{%5p}\n", 0);

	i = printf("{%05p}\n", 0);
	i = ft_printf("{%05p}\n", 0);
*/	
	i = printf("|%7.3S|\n", L"");
	i = ft_printf("|%7.3S|\n", L"");
	
	return (0);
}
