/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/03 15:58:28 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

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
	char		*lmod;
}				t_form;

int		ft_printf(const char *format, ...);

int		di_decimal(t_form, va_list *ap);

void	format_init(t_form *format);
int		ft_islmod(char c);
int		ft_isconversion(char c);
int		ft_isflag(char c);

int		adjust_field_width(size_t fw_len, char *pad, size_t start);
int		adjust_integer_precision(size_t precision_len, size_t start);

int		di_decimal(t_form format, va_list *ap);

#endif
