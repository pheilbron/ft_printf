/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 19:52:39 by pheilbro         ###   ########.fr       */
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

typedef struct	s_form
{
	uint8_t			flags;
	int				fw;
	int				pre;
	unsigned char	lmod;
	char			type;
	char			cap;
}				t_form;

typedef struct	s_fstring
{
	char	sign;
	char	*alt;
	char	*fw;
	char	*precision;
	char	*partial;
}				t_fstring;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

void			format_init(t_form *format);
int				is_data_lmod(char c);
int				is_data_conversion(char c);
int				is_data_flag(char c);
int				is_con_indicator(char c);

int				adjust_field_width(int fw_len, char *pad);
int				adjust_integer_precision(int precision_len);
int				adjust_alternate_form(t_form form, char *partial);

int				(*get_con(char type))(t_form, va_list *);

char			*get_unsigned_con(t_form form, unsigned long long value);

#endif
