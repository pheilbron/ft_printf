/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:05:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:11:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

int	set_pointer_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	form.type = 'x';
	form.flags |= _ALT;
	get_unsigned_con(form, (unsigned long long)va_arg(*ap, void *), &f);
	len = 0;
	f.head = s->pos;
	f.pre_i = f.head + (len += ft_dstr_add(s, f.alt, ft_strlen(f.alt)));
	len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
