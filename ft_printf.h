/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 12:35:36 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/17 16:29:03 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# include <stdio.h>		///////////////////////////

typedef struct	s_ftprintf
{
	size_t	f_start;	//% format start index
	size_t	f_end;		//% format end index
	char	flags[5];	//flags in a char arr
	size_t	fw;			//field width
	size_t	prec;		//precision
	char	sm;			//size modifier
	char	*output;	//string goto stdout
	char	cl;			//conversion letter
	void	*arg;		//argument itself
}				t_ftprintf;

int			ft_printf(const char *format, ...);
int			ft_putstr_until(char const *s, size_t end);
int			ft_cv(char a, t_ftprintf *st);
void		ft_pf(t_ftprintf *s, int cf);
void		ft_pfw(t_ftprintf *s);
void		ft_pprec(t_ftprintf *s);
void		ft_psm(t_ftprintf *s);
void		ft_findallmodifiers(const char *r, t_ftprintf *s, size_t *i);
void		ft_writeout(t_ftprintf *s, size_t *col);
size_t		ft_putanynbr(size_t num);
t_ftprintf	ft_ns(void *arg);

/*
** функции - конвершн леттеры
*/

void		ft_s_small(t_ftprintf *s, size_t *col);
void		ft_s_big(t_ftprintf *s, size_t *col);
void		ft_p_small(t_ftprintf *s, size_t *col);
void		ft_d_small(t_ftprintf *s, size_t *col);
void		ft_d_big(t_ftprintf *s, size_t *col);
void		ft_i_small(t_ftprintf *s, size_t *col);
void		ft_o_small(t_ftprintf *s, size_t *col);
void		ft_o_big(t_ftprintf *s, size_t *col);
void		ft_u_small(t_ftprintf *s, size_t *col);
void		ft_u_big(t_ftprintf *s, size_t *col);
void		ft_x_small(t_ftprintf *s, size_t *col);
void		ft_x_big(t_ftprintf *s, size_t *col);
void		ft_c_small(t_ftprintf *s, size_t *col);
void		ft_c_big(t_ftprintf *s, size_t *col);

void		printf_info(t_ftprintf *s);		/////////////////////////

#endif
