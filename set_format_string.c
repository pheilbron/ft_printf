/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:32:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/13 16:52:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_con.h"
#include "libft.h"

extern	t_vector	*g_con_string;

char	*(*get_con(char type))(t_form, va_list *)
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
	if (ft_strcmp(form.lmod, "hh") == 0)
		return (ft_lltoa((char)va_arg(*ap, int)));
	if (ft_strcmp(form.lmod, "h") == 0)
		return (ft_lltoa((short)va_arg(*ap, int)));
	if (ft_strcmp(form.lmod, "l") == 0)
		return (ft_lltoa(va_arg(*ap, long)));
	if (ft_strcmp(form.lmod, "ll") == 0)
		return (ft_lltoa(va_arg(*ap, long long)));
	if (form.lmod[0] == 'j')
		return (ft_lltoa(va_arg(*ap, intmax_t)));
	if (form.lmod[0] == 'z')
		return (ft_lltoa(va_arg(*ap, size_t)));
	return (ft_itoa(va_arg(*ap, int)));
}

//char	*get_char_partial(t_form form, va_list *ap)
//{
//	if (ft_strcmp(form.lmod, "l") == 0)
//		return ((char)va_arg(*ap, wint_t));
//	return ((char)va_arg(*ap, int));
//}

char	*get_string_partial(t_form form, va_list *ap)
{
	if (ft_strcmp(form.lmod, "l") == 0)
		return ((char *)va_arg(*ap, wchar_t *));
	return (va_arg(*ap, char *));
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

char	*get_unsigned_partial(t_form f, va_list *ap)
{
	if (ft_strcmp(f.lmod, "hh") == 0)
		return (get_unsigned_con(f, (unsigned char)va_arg(*ap, unsigned int)));
	if (ft_strcmp(f.lmod, "h") == 0)
		return (get_unsigned_con(f, (unsigned short)va_arg(*ap, unsigned int)));
	if (ft_strcmp(f.lmod, "l") == 0)
		return (get_unsigned_con(f, va_arg(*ap, unsigned long)));
	if (ft_strcmp(f.lmod, "ll") == 0)
		return (get_unsigned_con(f, va_arg(*ap, unsigned long long)));
	if (f.lmod[0] == 'j')
		return (get_unsigned_con(f, va_arg(*ap, uintmax_t)));
	if (f.lmod[0] == 'z')
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

int set_format_string(t_form form, char *partial)
{
	int		ret;

	ret = 0;
	if (form.alt)
		ret += adjust_alternate_form(form, partial);
	if (!form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre)
				- (form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	if (form.sign && partial[0] != '-')
		ret += ft_vect_add(g_con_string, "+", 1);
	else if (form.blank && partial [0] != '-')
		ret += ft_vect_add(g_con_string, " ", 1);
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre)
				- (form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	return (ret + ft_strlen(partial));
}
