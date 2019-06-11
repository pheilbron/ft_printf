/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_con.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:53:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/11 16:36:17 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CON_H
# define T_CON_H

# include "ft_printf.h"

typedef struct	s_con
{
	char		type;
	char		(*f)(t_form, va_list *);
}				t_con;

t_con	g_contab[] =
{
//	{'a', &get_float_partial}
	{'c', &get_unsigned_partial}
	{'d', &get_int_partial},
//	{'f', &get_float_partial}
//	{'g', &get_float_partial}
//	{'h', &get_float_partial}
	{'i', &get_int_partial},
//	{'m', &get_error_code},
//	{'n', &set_chars_written},
	{'o', &get_unsigned_partial},
//	{'p', &get_pointer_partial},
	{'s', &get_string_partial},
	{'u', &get_unsigned_partial},
	{'x', &get_unsigned_partial},
	{0, &get_int_partial}
};

#endif
