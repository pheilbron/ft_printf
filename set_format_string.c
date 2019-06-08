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
#include "t_toa.h"
#include "libft.h"

extern	t_vector	*g_con_string;

int di_decimal(t_form form, va_list *ap)
{
	char	*conv;
	int		ret;

	ret = 0;
	partial = (*get_con((get_con_tab(form, ap) (va_arg(*ap, char *));
	if (!form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	if (form.sign)
		ret += ft_vect_add(g_con_string, "+", 1);
	else if (form.blank)
		ret += ft_vect_add(g_con_string, " ", 1);
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre - ft_strlen(partial));
	ret += ft_vect_add(g_con_string, partial, ft_strlen(partial));
	if (form.left_just && form.fw - form.pre > 0)
		ret += adjust_field_width(form.fw - ft_max(ft_strlen(partial), form.pre) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "));
	return (ret + ft_strlen(partial));
}
