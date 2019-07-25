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
