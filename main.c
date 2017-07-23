/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 13:56:50 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/23 11:42:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char *A = "this is tEEEEst!";
//	printf("|%-020s|\t|%7s|\t|%10s is a string|\n", A, A, "this");
//	ft_printf("|%-020s|\t|%7s|\t|%10s is a string|\n", A, A, "this");
	printf("|%5.2s is a string|\t|%-5.2s is a string|\t|\n", "", "");
	ft_printf("|%5.2s is a string|\t|%-5.2s is a string|\t|\n", "", "");
	return (0);
}
