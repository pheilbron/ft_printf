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
#include "ft_dstring.h"

int	set_string_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	len = 0;
	if (form.lmod == 'l')
		f.partial = (char *)va_arg(*ap, wchar_t *);
	else
		f.partial = va_arg(*ap, char *);
	if (!f.partial)
		return (ft_dstring_add(s, "(null)", 6));
	if (form.pre > 0 && form.pre < ft_strlen(f.partial))
		f.partial[form.pre] = '\0';
	if (form.fw > ft_strlen(f.partial))
		ft_get_string_fw(&f, form.fw, ft_strlen(f.partial));
	if (!(form.flags | _LEFT_JUST) && f.fw)
		len += ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if (form.flags | _LEFT_JUST && f.fw)
		len += ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	ft_fstring_free(&f);
	return (len);
}
