/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 18:40:51 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <inttypes.h>

# define _ALT 1
# define _ZERO 2
# define _LEFT_JUST 4
# define _BLANK 8
# define _SIGN 16
# define _CAP 32

# define NAN (0.0 / 0)
# define INF (1.0 / 0)
# define NEG_INF (-1.0 / 0)

typedef struct	s_form
{
	uint8_t			flags;
	int				fw;
	int				pre;
	unsigned char	lmod;
	char			type;
}				t_form;

typedef struct	s_fstring
{
	int		head;	
	char	sign;
	char	*alt;
	int		pre_i;	
	int		pre;
	char	*partial;
}				t_fstring;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

int				is_data_lmod(char c);
int				is_data_conversion(char c);
int				is_data_flag(char c);
int				is_con_indicator(char c);

int				ft_printf_adjust_fw(t_dstring *s, t_fstring f, t_form form);

void			get_unsigned_con(t_form form, unsigned long long value,
		t_fstring *f);

void			ft_fstring_init(t_fstring *f);
int				ft_fstring_free(t_fstring *f);

int				(*convert_data(char type))(t_dstring *, t_form, va_list *);

#endif
