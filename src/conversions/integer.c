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
#include "ft_stdlib.h"
#include "ft_string.h"

void		get_int_precision(t_fstring *f, int len, int precision)
{
	int	i;

	if ((f->pre = malloc(sizeof(*f->pre) * (precision - len + 1))))
	{
		i = len;
		while (i < precision)
			f->pre[i++ - len] = '0';
		f->pre[i - len] = '\0';
	}
}

void		get_int_fw(t_fstring *f, int len, int precision, char fw_char)
{
	int	i;

	if ((f->fw = malloc(sizeof(*f->fw) * (fw - len + 1))))
	{
		i = len;
		while (i < fw)
			f->fw[i++ - len] = fw_char;
		f->fw[i - len] = '\0';
	}
}

t_fstring	get_int_partial(t_form form, va_list *ap)
{
	t_fstring	f;

	if (form.lmod == ('h' + 'h'))
		ft_printf_lltoa((signed char)va_arg(*ap, int), &f);
	else if (form.lmod == 'h')
		ft_printf_lltoa((short)va_arg(*ap, int), &f);
	else if (form.lmod == 'l')
		ft_printf_lltoa(va_arg(*ap, long), &f);
	else if (form.lmod == ('l' + 'l'))
		ft_printf_lltoa(va_arg(*ap, long long), &f);
	else if (form.lmod == 'j')
		ft_printf_lltoa(va_arg(*ap, intmax_t), &f);
	else if (form.lmod == 'z')
		ft_printf_lltoa(va_arg(*ap, size_t), &f);
	else
		ft_itoa(va_arg(*ap, int));
	f.pre = NULL;
	f.fw = NULL;
}

int	set_int_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			partial_len;

	f = get_int_partial(form, ap);
	partial_len = ft_strlen(f.partial);
	if (form.pre >= 0 && form.pre > partial_len)
		ft_get_int_precision(&f, partial_len, form.pre);
	partial_len += (f.pre ? ft_strlen(f.pre) : 0) +
		((form.flags | _ZERO) || (form.flags | _BLANK) ? 1 : 0);
	if (form.fw > 0 && form.fw > partial_len)
		ft_get_int_fw(&f, partial_len, form.fw);
	partial_len = 0;
	if (!((form.flags | _ZERO) || (form.flags | _LEFT_JUST)))
		partial_len = ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	if (form.flags | _SIGN || form.flags | _BLANK)
		partial_len = ft_dstr_add(s, &(f.sign), 1);
	if ((form.flags | _ZERO) && !(form.flags | _LEFT_JUST))
		partial_len = ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	if (f.pre)
		partial_len = ft_dstr_add(s, f.pre, ft_strlen(f.pre));
	if (!(form.pre == 0 && ft_strcmp(f.partial, "0"))) 
		partial_len = ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if (form.flags | _LEFT_JUST)
		partial_len = ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	return (partial_len);
}
