/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:32:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/07 14:09:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

char	*get_partial(t_form form, va_list *ap)
{
	if (form.len_mod == "hh")
		return (get_con(form.len_mod, va_arg(*ap, char)));
	if (form.len_mod == "h")
		return (get_con(form.len_mod, va_arg(*ap, short)));
	if (form.len_mod == "l")
		return (get_con(form.len_mod, va_arg(*ap, long)));
	if (form.len_mod == "ll")
		return (get_con(form.len_mod, va_arg(*ap, long long)));
	if (form.len_mod == "j")
		return (get_con(form.len_mod, va_arg(*ap, intmax_t)));
	if (form.len_mod == "z")
		return (get_con(form.len_mod, va_arg(*ap, size_t)));
	return ("\0");
}

int di_decimal(t_form form, va_list *ap)
{
	char	*conv;
	int		ret;

	ret = 0;
	partial = get_partial(form, ap);
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
