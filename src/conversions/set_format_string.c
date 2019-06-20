/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 09:54:56 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_con.h"
#include "libft.h"
#include "color_tab.h"

extern	t_vector	*g_con_string;

int		(*get_con(char type))(t_form, va_list *)
{
	size_t	i;

	i = 0;
	while (g_contab[i].type != 0)
	{
		if (g_contab[i].type == type)
			return (g_contab[i].f);
		i++;
	}
	return (g_contab[i].f);
}

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

//char	*get_float_con(t_form form, long double value)
//{
//	
//	//
//}
//
//char	*get_float_partial(t_form form, va_list *ap)
//{
//	if (form.lmod[0] == "l")
//		return (get_float_con(form.lmod, va_arg(*ap, double)));
//	if (form.lmod[0] == "L")
//		return (get_float_con(form.lmod, va_arg(*ap, long double)));
//	return (get_float_con(form.lmod, va_arg(*ap, double)));
//}

int	print_wchar(t_form form, va_list *ap)
{
	int		ret;
	int		i;
	wchar_t	w_partial;
	
	w_partial = va_arg(*ap, wchar_t);
	i = 0;
	write(1, g_con_string, g_con_string->pos);
	g_con_string->pos = 0;
	ret = form.pre > 1 ? form.pre : 1;
	if (!form.left_just && form.fw > i++)
		write(1, " ", 1);
	write(1, &w_partial, 1);
	if (form.left_just && form.fw > i++)
		write(1, " ", 1);
	return (ret + i);
}

int	set_char_format_string(t_form form, va_list *ap)
{
	int		ret;
	char	partial;

	ret = 0;
	if (form.lmod == 'l')
		return (print_wchar(form, ap));
	partial = (char)va_arg(*ap, int);
	if (!form.left_just && form.fw - 1 > 0)
		ret += adjust_field_width(form.fw - 1, " ");
	ret += ft_vect_add(g_con_string, &partial, 1);
	if (form.left_just && form.fw - 1 > 0)
		ret += adjust_field_width(form.fw - 1, " ");
	return (ret);
}

int	print_wstring(t_form form, va_list *ap)
{
	int		ret;
	int		i;
	wchar_t	*w_partial;
	
	w_partial = va_arg(*ap, wchar_t *);
	i = 0;
	write(1, g_con_string, g_con_string->pos);
	g_con_string->pos = 0;
	ret = form.pre > 0 ? form.pre : ft_wstrlen(w_partial);
	if (!form.left_just && form.fw > i++)
		write(1, " ", 1);
	write(1, w_partial, ret);
	if (form.left_just && form.fw > i++)
		write(1, " ", 1);
	return (ret);
}

int	set_string_format_string(t_form form, va_list *ap)
{
	int		ret;
	int		precision;
	char	*partial;

	ret = 0;
	if (form.lmod == 'l')
		return (print_wstring(form, ap));
	partial = va_arg(*ap, char *);
	if (!partial)
		return (ft_vect_add(g_con_string, "(null)", 6));
	precision = ft_strlen(partial);
	if (form.pre > 0)
		precision = ft_min(form.pre, precision);
	if (!form.left_just && form.fw - precision > 0)
		ret += adjust_field_width(form.fw - precision, " ");
	ret += ft_vect_add(g_con_string, partial, precision);
	if (form.left_just && form.fw - precision > 0)
		ret += adjust_field_width(form.fw - precision, " ");
	return (ret);
}

int	set_mod_format_string(t_form form, va_list *ap)
{
	int		ret;
	va_list	empty;

	ret = 0;
	va_copy(empty, *ap);
	if (!form.left_just && form.fw - 1 > 0)
		ret += adjust_field_width(form.fw - 1, " ");
	ret += ft_vect_add(g_con_string, "%", 1);
	if (form.left_just && form.fw - 1 > 0)
		ret += adjust_field_width(form.fw - 1, " ");
	return (ret);
}

int	set_color_format_string(const char **s, int *pos)
{
	int	i;

	i = 0;
	while (g_color_tab[i].name && ft_memcmp(*s + 1, g_color_tab[i].name, 4) != 0)
		i++;
	if (g_color_tab[i].name)
	{
		(*s) += 5;
		return (ft_vect_add(g_con_string, g_color_tab[i].escape_code, 8));
	}
	(*pos)++;
	//return (ft_vect_add(g_con_string, (char *)s, 1));
	return (0);
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
