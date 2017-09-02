/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 12:35:36 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/02 13:17:02 by dmaznyts         ###   ########.fr       */
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
	int		ip;			//if precision
	size_t	prec;		//precision
	char	sm;			//size modifier
	char	*output;	//string goto stdout
	char	cl;			//conversion letter
	void	*arg;		//argument itself
	char	l;			//extra kostyl_letter
}				t_ftprintf;

int				ft_printf(const char *format, ...);
int				ft_putstr_until(char const *s, size_t end);
int				ft_cv(char a, t_ftprintf *st);
int				ft_isflag(char a);
int				ft_is_sm(char a);
char			*ft_itoa_base(int value, int base);
char			*ft_uitoa_base(unsigned int value, int base);
char			*ft_luitoa_base(unsigned int value, int base);
char			*ft_lltoa_base(long value, int base);
char			*ft_llltoa_base(long long value, int base);
char			*ft_sttoa_base(size_t value, int base, int lol);
char			*ft_lsttoa_base(size_t value, int base);
char			*ft_imttoa_base(intmax_t value, int base);
char			*ft_suimttoa_base(uintmax_t value, int base);
char			*ft_luimttoa_base(uintmax_t value, int base);
char			*ft_sultoa_base(unsigned long value, int base);
char			*ft_lultoa_base(unsigned long value, int base);
char			*ft_sitoa_base(short int value, int base);
char			*ft_usitoa_base(unsigned short int value, int base);
char			*ft_lusitoa_base(unsigned short int value, int base);
char			*ft_ctoa_base(char value, int base);
char			*ft_uctoa_base(unsigned char value, int base);
char			*ft_luctoa_base(unsigned char value, int base);
void			ft_pf(t_ftprintf *s);
void			ft_pfw(t_ftprintf *s);
void			ft_pprec(t_ftprintf *s);
void			ft_psm(t_ftprintf *s);
void			ft_findallmodifiers(const char *r, t_ftprintf *s, size_t *i);
void			ft_writeout(t_ftprintf *s, size_t *col);
size_t			ft_ustrlen(unsigned char *s);
wchar_t			*ft_wstrdup(const wchar_t *s);
t_ftprintf		ft_ns(void);
unsigned char	*ft_ustrjoin(unsigned char *s1, unsigned char *s2);

/*
** функции - конвершн леттеры
*/

void			ft_s_small(t_ftprintf *s, size_t *col);
void			ft_s_big(t_ftprintf *s, size_t *col);
void			ft_p_small(t_ftprintf *s, size_t *col);
void			ft_d_small(t_ftprintf *s, size_t *col);
void			ft_d_big(t_ftprintf *s, size_t *col);
void			ft_i_small(t_ftprintf *s, size_t *col);
void			ft_o_small(t_ftprintf *s, size_t *col);
void			ft_o_big(t_ftprintf *s, size_t *col);
void			ft_u_small(t_ftprintf *s, size_t *col);
void			ft_u_big(t_ftprintf *s, size_t *col);
void			ft_x_small(t_ftprintf *s, size_t *col);
void			ft_x_big(t_ftprintf *s, size_t *col);
void			ft_c_small(t_ftprintf *s, size_t *col);
void			ft_c_big(t_ftprintf *s, size_t *col);

void			printf_info(t_ftprintf *s);		/////////////////////////

/*
**	 функции для wchar_t
*/

unsigned char	*ft_one(size_t val);
unsigned char	*ft_two(size_t val);
unsigned char	*ft_three(size_t val);
unsigned char	*ft_four(size_t val);

#endif
