/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 12:35:36 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/09/04 14:52:33 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_ftprintf
{
	size_t	f_start;
	size_t	f_end;
	char	flags[5];
	size_t	fw;
	int		ip;
	size_t	prec;
	char	sm;
	char	*output;
	char	cl;
	void	*arg;
	char	l;
}				t_ftprintf;

int				ft_printf(const char *format, ...);
int				ft_putstr_until(char const *s, size_t end);
int				ft_cv(char a, t_ftprintf *st);
int				ft_isflag(char a);
int				ft_is_sm(char a);
char			ft_fl_w(t_ftprintf *s);
char			ft_o_fl(t_ftprintf *s);
char			*ft_itoa_base(int value, int base);
char			*ft_uitoa_base(unsigned int value, int base);
char			*ft_luitoa_base(unsigned int value, int base);
char			*ft_lltoa_base(long value, int base);
char			*ft_llltoa_base(long long value, int base);
char			*ft_sttoa_base(size_t value, int base);
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
char			*ret_x_sm_z(t_ftprintf *s, unsigned int nu, char *num, char c);
char			*ret_x_sm_o(t_ftprintf *s, unsigned int nu, char *num, char c);
char			*ret_x_sm_t(t_ftprintf *s, unsigned int nu, char *num);
char			*ret_x_sm_n(t_ftprintf *s, char *num);
char			*ft_d_sm_n(t_ftprintf *s, char *num, size_t irepeta);
char			*ft_tmp_ret(t_ftprintf *s, char *num, char *tmp, char c);
char			*ft_work(t_ftprintf *s, char *num, char *tmp, char c);
void			ft_pf(t_ftprintf *s);
void			ft_pfw(t_ftprintf *s);
void			ft_pprec(t_ftprintf *s);
void			ft_psm(t_ftprintf *s);
void			ft_findallmodifiers(const char *r, t_ftprintf *s, size_t *i);
void			ft_writeout(t_ftprintf *s, size_t *col);
size_t			ft_ustrlen(unsigned char *s);
size_t			s_ret_prec(t_ftprintf *s);
wchar_t			*ft_wstrdup(const wchar_t *s);
t_ftprintf		ft_ns(void);
unsigned char	*ft_ustrjoin(unsigned char *s1, unsigned char *s2);
unsigned char	*ft_so(size_t *len, size_t v);
unsigned char	*ft_st(size_t *len, size_t v);
unsigned char	*ft_sh(size_t *len, size_t v);
unsigned char	*ft_sf(size_t *len, size_t v);

/*
**	функции - конвершн леттеры
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

/*
**	функции для wchar_t
*/

unsigned char	*ft_one(size_t val);
unsigned char	*ft_two(size_t val);
unsigned char	*ft_three(size_t val);
unsigned char	*ft_four(size_t val);
unsigned char	*ft_write(size_t v, size_t *len, size_t max);
unsigned char	*ft_sb_fun1(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun2(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun3(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun4(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun5(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun6(t_ftprintf *s);
unsigned char	*ft_sb_fun7(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun8(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun9(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun10(t_ftprintf *s, wchar_t *st, size_t *len);
unsigned char	*ft_sb_fun11(t_ftprintf *s, wchar_t *st, size_t *len);

#endif
