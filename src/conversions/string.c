/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:13:27 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

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
