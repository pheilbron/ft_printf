/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:14:12 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

extern	t_vector	*g_con_string;

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
