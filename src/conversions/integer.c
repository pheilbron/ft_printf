/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/24 19:49:40 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"

t_fstring	get_int_partial(t_form form, va_list *ap)
{
	t_fstring	f;

	if (form.lmod == ('h' + 'h'))
		ft_printf_lltoa((signed char)va_arg(*ap, int), &f);
	else if (form.lmod == 'h')
		ft_printf_lltoa((short)va_arg(*ap, int), &f);
	else if (form.lmod == 'l')
		ft_printf_lltoa(va_arg(*ap, long), &f);
	else if (form.lmod == ('l' + 'l'))
		ft_printf_lltoa(va_arg(*ap, long long), &f);
	else if (form.lmod == 'j')
		ft_printf_lltoa(va_arg(*ap, intmax_t), &f);
	else if (form.lmod == 'z')
		ft_printf_lltoa(va_arg(*ap, size_t), &f);
	else
		ft_itoa(va_arg(*ap, int));
	if (
}

int	set_int_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;

	f.data = get_int_partial(form, ap);
	f.sign = '\0';
	if (form.sign)
		f.sign = (*(f.data) == '-' ? '-' : '+');

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
