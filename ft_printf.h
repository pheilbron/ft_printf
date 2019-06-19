/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/19 13:38:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <inttypes.h>

# include "libft.h"

typedef struct	s_form
{
	char		alt;
	char		zero;
	char		left_just;
	char		blank;
	char		sign;
	int			fw;
	int			pre;
	unsigned char	lmod;
	char		type;
	char		cap;
}				t_form;

int		ft_printf(const char *format, ...);

int		set_color_format_string(const char *s, int *pos);

void	format_init(t_form *format);
int		ft_islmod(char c);
int		ft_isconversion(char c);
int		ft_isflag(char c);

int		adjust_field_width(int fw_len, char *pad);
int		adjust_integer_precision(int precision_len);
int		adjust_alternate_form(t_form form, char *partial);

int		(*get_con(char type))(t_form, va_list *);

#endif
