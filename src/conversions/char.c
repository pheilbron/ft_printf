/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:36:30 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 18:40:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	set_char_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	char		c;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == 'l')
		c = ((wchar_t)va_arg(*ap, int));
	else
		c = ((char)va_arg(*ap, int));
	f.head = (f.pre_i = s->pos);
	len = ft_dstr_add(s, f.partial, ft_strlen(&c));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
