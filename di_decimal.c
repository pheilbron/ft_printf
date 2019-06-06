/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:32:12 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/03 15:59:28 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_toa.h"
#include "libft.h"

extern	t_vector	*g_con_string;

int di_decimal(t_form form, va_list *ap)
{
	char	*partial;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (g_dtoa[i].type != 0 && !ft_strcmp(g_dtoa[i].type, form.lmod))
		i++;
	partial = (*g_dtoa[i].f)(va_arg(*ap, char *));
	i = g_con_string->pos;
	if (!form.left_just)
		ret += adjust_field_width(form.fw - ft_strlen(partial) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "), i);
	if (form.sign)
		ret += ft_vect_add(g_con_string, "+", 1);
	else if (form.blank)
		ret += ft_vect_add(g_con_string, " ", 1);
	if (form.pre > 0)
		ret += adjust_integer_precision(form.pre, i);
	if (form.left_just)
		ret += adjust_field_width(form.fw - ft_strlen(partial) -
				(form.blank || form.sign ? 1 : 0), (form.zero ? "0" : " "), i);
	return (ret + ft_strlen(partial));
}
