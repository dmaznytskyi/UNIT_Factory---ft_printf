/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:56:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/08/07 16:09:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_ustrlen(unsigned char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

unsigned char	*ft_wstrjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*res;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	res = (unsigned char*)malloc(ft_ustrlen(s1) + ft_ustrlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	free(s1);
	while (s2[j])
		res[i++] = s2[j++];
	free(s2);
	res[i] = '\0';
	return (res);
}
