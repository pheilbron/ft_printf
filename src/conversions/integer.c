/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:12:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

char	*get_int_partial(t_form form, va_list *ap)
{
	if (form.lmod == ('h' + 'h'))
		return (ft_lltoa((signed char)va_arg(*ap, int)));
	if (form.lmod == 'h')
		return (ft_lltoa((short)va_arg(*ap, int)));
	if (form.lmod == 'l')
		return (ft_lltoa(va_arg(*ap, long)));
	if (form.lmod == ('l' + 'l'))
		return (ft_lltoa(va_arg(*ap, long long)));
	if (form.lmod == 'j')
		return (ft_lltoa(va_arg(*ap, intmax_t)));
	if (form.lmod == 'z')
		return (ft_lltoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, int)));
}

char	*get_unsigned_con(t_form form, unsigned long long value)
{
	if (form.type == 'b')
		return (ft_ulltoa_base(value, 2, form.cap));
	if (form.type == 'o')
		return (ft_ulltoa_base(value, 8, form.cap));
	if (form.type == 'x')
		return (ft_ulltoa_base(value, 16, form.cap));
	if (form.type == 'u')
		return (ft_ulltoa_base(value, 10, form.cap));
	return (ft_ulltoa_base(value, 10, form.cap));
}

char	*get_unsigned_partial(t_form f, va_list *ap)
{
	if (f.lmod == ('h' + 'h'))
		return (get_unsigned_con(f, (unsigned char)va_arg(*ap, unsigned int)));
	if (f.lmod == 'h')
		return (get_unsigned_con(f, (unsigned short)va_arg(*ap, unsigned int)));
	if (f.lmod == 'l')
		return (get_unsigned_con(f, va_arg(*ap, unsigned long)));
	if (f.lmod == ('l' + 'l'))
		return (get_unsigned_con(f, va_arg(*ap, unsigned long long)));
	if (f.lmod == 'j')
		return (get_unsigned_con(f, va_arg(*ap, uintmax_t)));
	if (f.lmod == 'z')
		return (get_unsigned_con(f, va_arg(*ap, size_t)));
	return (get_unsigned_con(f, va_arg(*ap, unsigned int)));
}

int set_hex_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		fw;
	char	*partial;

	ret = 0;
	partial = get_unsigned_partial(form, ap);
	form.alt = (ft_strcmp(partial, "0") == 0) ? 0 : form.alt;
	fw = form.fw - (form.alt * 2) -
		ft_max((ft_strcmp(partial, "0") ? ft_strlen(partial) : 0), form.pre);
	if (!form.left_just && form.fw - form.pre > 0 && !form.zero)
		ret += adjust_field_width(fw, " ");
	if (form.alt)
		ret += adjust_alternate_form(form, partial);
	if (!form.left_just && form.fw - form.pre > 0 && form.zero)
		ret += adjust_field_width(fw, "0");
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	if (form.pre != 0 || ft_strcmp(partial, "0") != 0)
		ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, " ");
	ret += ft_strlen(partial);
	free(partial);
	return (ret);
}

int set_binary_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		fw;
	char	*partial;

	ret = 0;
	partial = get_unsigned_partial(form, ap);
	form.alt = (ft_strcmp(partial, "0") == 0) ? 0 : form.alt;
	fw = form.fw - (form.alt * 2) -
		ft_max((ft_strcmp(partial, "0") ? ft_strlen(partial) : 0), form.pre);
	if (!form.left_just && form.fw - form.pre > 0 && !form.zero)
		ret += adjust_field_width(fw, " ");
	if (form.alt)
		ret += adjust_alternate_form(form, partial);
	if (!form.left_just && form.fw - form.pre > 0 && form.zero)
		ret += adjust_field_width(fw, "0");
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	if (form.pre != 0 || ft_strcmp(partial, "0") != 0)
		ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, " ");
	ret += ft_strlen(partial);
	free(partial);
	return (ret);
}

int set_octal_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		fw;
	char	*partial;

	ret = 0;
	partial = get_unsigned_partial(form, ap);
	fw = form.fw - ft_max(ft_strlen(partial), form.pre) - form.alt;
	if (!form.left_just && form.fw - form.pre > 0 && !form.zero)
		ret += adjust_field_width(fw, " ");
	if (form.alt)
		ret += adjust_alternate_form(form, partial);
	if (!form.left_just && form.fw - form.pre > 0 && form.zero)
		ret += adjust_field_width(fw, "0");
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	if (form.pre != 0 || ft_strcmp(partial, "0") != 0)
		ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, " ");
	ret += ft_strlen(partial);
	free(partial);
	return (ret);
}

int set_unsigned_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		fw;
	char	*partial;

	ret = 0;
	partial = get_unsigned_partial(form, ap);
	fw = form.fw - ft_max(ft_strlen(partial), form.pre) - form.alt;
	if (!form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, form.zero ? "0" : " ");
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, " ");
	ret += ft_strlen(partial);
	free(partial);
	return (ret);
}

int set_int_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		fw;
	char	*partial;

	ret = 0;
	partial = get_int_partial(form, ap);
	fw = form.fw - ft_max(ft_strlen(partial), form.pre) -
		(form.blank || form.sign);
	if (!form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, form.zero ? "0" : " ");
	if (form.sign && partial[0] != '-')
		ret += ft_vect_add(g_con_string, "+", 1);
	else if (form.sign && partial[0] == '-')
		ret += ft_vect_add(g_con_string, partial++, 1);
	else if (form.blank && partial[0] != '-')
		ret += ft_vect_add(g_con_string, " ", 1);
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	if (form.pre != 0 || ft_strcmp(partial, "0") != 0)
		ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(fw, " ");
	ret += ft_strlen(partial);
	free(partial);
	return (ret + ft_strlen(partial));
}
