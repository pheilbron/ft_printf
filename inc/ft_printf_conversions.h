/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_con.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:53:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 19:21:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERSIONS_H
# define FT_PRINTF_CONVERSIONS_H

typedef struct	s_con
{
	char		type;
	int			(*f)(t_form, va_list *);
}				t_con;

//int				set_float_hex_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_char_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_int_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_e_notation_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_float_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_choose_float_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_date_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_error_code_fstring(t_dstring *s, t_form form, va_list *ap);
int				get_chars_written(t_dstring *s, t_form form, va_list *ap);
int				set_pointer_fstring(t_dstring *s, t_form form, va_list *ap);
//int				set_non_print_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_string_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_unsigned_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_mod_fstring(t_dstring *s, t_form form, va_list *ap);

#endif
