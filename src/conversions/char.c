/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:12:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

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
