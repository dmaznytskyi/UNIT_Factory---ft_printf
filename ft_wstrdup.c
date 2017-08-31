/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:48:37 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/31 15:57:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != 0)
			i++;
	}
	return (i);
}

wchar_t			*ft_wstrdup(const wchar_t *s)
{
	wchar_t	*dup;
	size_t	i;

	i = -1;
	dup = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}
