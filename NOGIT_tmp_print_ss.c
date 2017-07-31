/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:52:53 by rkonoval          #+#    #+#             */
/*   Updated: 2017/07/31 10:31:26 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_ssp3(char *s, wint_t *ws, int *i, int *j)
{
	s[(*j)++] = (char)(((ws[(*i)] & 0xF000) >> 12) + 0xE0);
	s[(*j)++] = (char)(((ws[(*i)] & 0x0Fc0) >> 6) + 0x80);
	s[(*j)++] = (char)((ws[(*i)] & 0x003F) + 0x80);
	return (s);
}

static char	*print_ssp4(char *s, wint_t *ws, int *i, int *j)
{
	s[(*j)++] = (char)(((ws[(*i)] & 0x1c0000) >> 18) + 0xF0);
	s[(*j)++] = (char)(((ws[(*i)] & 0x03F000) >> 12) + 0x80);
	s[(*j)++] = (char)(((ws[(*i)] & 0x0Fc0) >> 6) + 0x80);
	s[(*j)++] = (char)((ws[(*i)] & 0x003F) + 0x80);
	return (s);
}

static int	check_len(wint_t *ws)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (ws[i])
	{
		if (ws[i] <= 0x7F)
			len++;
		else if (ws[i] <= 0x7FF)
			len += 2;
		else if (ws[i] <= 0xFFFF)
			len += 3;
		else if (ws[i] <= 0x1FFFFF)
			len += 4;
		i++;
	}
	return (len);
}

static void	print_ssp2(wint_t *ws, int i, int j)
{
	char *s;

	s = ft_memalloc(check_len(ws) + 1);
	while (ws[i])
	{
		if (ws[i] <= 0x7F)
			s[j++] = ws[i];
		else if (ws[i] <= 0x7FF)
		{
			s[j] = (char)(((ws[i] & 0x07c0) >> 6) + 0xc0);
			s[j] = (char)((ws[i] & 0x003F) + 0x80);
		}
		else if (ws[i] <= 0xFFFF)
			s = print_ssp3(s, ws, &i, &j);
		else if (ws[i] <= 0x1FFFFF)
			s = print_ssp4(s, ws, &i, &j);
		i++;
	}
	s[j] = '\0';
	ft_putstr(s);
	if (s)
		free(s);
}

void		print_ss(void *data)
{
	wint_t *ws;

	ws = (wint_t *)data;
	if (!ws)
	{
		ft_putstr("(null)");
		g_len += 6;
		return ;
	}
	g_len += check_len(ws);
	print_ssp2(ws, 0, 0);
}
