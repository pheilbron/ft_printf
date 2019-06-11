/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:32:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/11 16:22:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

char	*get_int_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "hh")
		return (ft_lltoa(va_arg(*ap, char)));
	if (form.len_mod == "h")
		return (ft_lltoa(va_arg(*ap, short)));
	if (form.len_mod == "l")
		return (ft_lltoa(va_arg(*ap, long)));
	if (form.len_mod == "ll")
		return (ft_lltoa(va_arg(*ap, long long)));
	if (form.len_mod == "j")
		return (ft_lltoa(va_arg(*ap, intmax_t)));
	if (form.len_mod == "z")
		return (ft_lltoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, int)));
}

char	*get_char_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "l")
		return (&(va_arg(*ap, wint_t)));
	return (&(va_arg(*ap, char)));
}

char	*get_string_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "l")
		return (get_con(form.len_mod, va_arg(*ap, wchar_t *)));
	return (va_arg(*ap, char *));
}

char	*get_unsigned_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "hh")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned char)));
	if (form.len_mod == "h")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned short)));
	if (form.len_mod == "l")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned long)));
	if (form.len_mod == "ll")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned long long)));
	if (form.len_mod == "j")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned intmax_t)));
	if (form.len_mod == "z")
		return (get_unsigned_con(form.len_mod, va_arg(*ap, size_t)));
	return (get_unsigned_con(form.len_mod, va_arg(*ap, unsigned int)));
}

char	*get_unsigned_con(t_form form, unsigned long long value)
{
	if (form.type == 'o')
		return (ft_ulltoa_base(value, 8, form.cap));
	if (form.type == 'x')
		return (ft_ulltoa_base(value, 16, form.cap));
	if (form.type == 'u')
		return (ft_ulltoa_base(value, 10, form.cap));
	return (ft_ulltoa_base(value, 10, form.cap));
}

char	*get_float_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "l")
		return (get_float_con(form.len_mod, va_arg(*ap, double)));
	if (form.len_mod == "L")
		return (get_float_con(form.len_mod, va_arg(*ap, long double)));
	return (get_float_con(form.len_mod, va_arg(*ap, double)));
}

char	*get_float_con(t_form form, long double)
{
	//
	//
}

int set_format_string(t_form form, char *partial)
{
	char	*conv;
	int		ret;

	ret = 0;
	if (!form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	if (form.sign && partial[0] != '-')
		ret += ft_vect_add(g_con_string, "+", 1);
	else if (form.blank && partial [0] != '-')
		ret += ft_vect_add(g_con_string, " ", 1);
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	return (ret + ft_strlen(partial));
}
