/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_con.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:53:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:21:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CON_H
# define T_CON_H

# include "ft_printf.h"
# 
typedef struct	s_con
{
	char		type;
	int			(*f)(t_form, va_list *);
}				t_con;

int	set_hex_format_string(t_form form, va_list *ap);
int	set_octal_format_string(t_form form, va_list *ap);
int	set_unsigned_format_string(t_form form, va_list *ap);
int	set_int_format_string(t_form form, va_list *ap);
int	set_mod_format_string(t_form form, va_list *ap);
int	set_char_format_string(t_form form, va_list *ap);
int	set_string_format_string(t_form form, va_list *ap);

t_con	g_contab[] =
{
//	{'a', &get_float_partial},
//	{'b', &set_binary_format_string},
	{'c', &set_char_format_string},
	{'d', &set_int_format_string},
//	{'f', &get_float_partial},
//	{'g', &get_float_partial},
//	{'h', &get_float_partial},
	{'i', &set_int_format_string},
//	{'k', &set_date_format_string},
//	{'m', &get_error_code},
//	{'n', &set_chars_written},
	{'o', &set_octal_format_string},
//	{'p', &get_pointer_partial},
//	{'r', &set_non_print_format_string},
	{'s', &set_string_format_string},
	{'u', &set_unsigned_format_string},
	{'x', &set_hex_format_string},
	{'%', &set_mod_format_string},
	{0, &set_int_format_string}
};

#endif
