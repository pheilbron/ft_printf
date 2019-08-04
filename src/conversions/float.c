/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:07:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 12:25:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"

t_fstring	get_float_partial(t_form form, va_list *ap)
{
	t_fstring	f;

	if (form.lmod == ('l' + 'l'))
		ft_printf_ldtoa(va_arg(*ap, long double), &f);
	else
		ft_printf_ldtoa(va_arg(*ap, double), &f);
}

int set_float_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	if (form.lmod == ('l' + 'l'))
		ft_printf_ldtoa(va_arg(*ap, long double), &f, form);
	else
		ft_printf_ldtoa(va_arg(*ap, double), &f, form);
	
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
