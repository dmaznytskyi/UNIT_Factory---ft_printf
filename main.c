/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/30 17:00:01 by dmaznyts         ###   ########.fr       */
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
	i = printf("|%20hd|\t|%20hhhd|\t|%20ld|\n", "4294967296","4294967296","4294967296");
	i = ft_printf("|%20hd|\t|%20hhhd|\t|%20ld|\n", "4294967296","4294967296","4294967296");
//	i = ft_printf("|%20hd|\t|%20hhd|\t|%20d|\n", 4294967296,4294967296,4294967296);
//	i = ft_printf("|%20hd|\t|%20hhd|\t|%20d|\n", 4294967296,4294967296,4294967296);
	return (0);
}
