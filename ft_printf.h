/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/24 18:55:55 by pheilbro         ###   ########.fr       */
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
	char		zero_pad;
	char		left_just;
	char		blank;
	char		sign;
	int			field_width;
	int			precision;
	char		*length_mod;
}				t_form;

typedef struct	s_con
{
	char		*type;
	int			(*f)();
}				t_con;

t_con	*g_contab[] =
{
	{"s", &integer},
	{"p", &integer},
	{"d", &integer},
	{"i", &integer},
	{"o", &integer},
	{"u", &integer},
	{"x", &integer},
	{"c", &integer}
}

int	ft_printf(const char *format, ...);

void	format_init(t_form *format);
int	ft_islen_mod(char c);
int	ft_isconversion(char c);
int	ft_isflag(char c);

#endif
