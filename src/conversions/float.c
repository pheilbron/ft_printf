/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:07:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 16:11:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

t_fstring	*ft_printf_ldtoa(long double n, t_fstring *f, t_form form)
{
	long double	decimal;
	int			i;

	decimal = (n < 0 ? -n : n) - (long long)(n < 0 ? -n : n);
	i = 0;
	if (is_float_dne(n, f))
		return (f);
	ft_printf_lltoa((long long)n, f);
	if (f->alt = malloc(sizeof(*f->alt) * (form.pre + 1)))
	{
		while (i < form.pre)
			f->alt[i++] = (int)(decimal *= 10) + '0';
		f->alt[i] = '\0';
		if (decimal >= 5)
			ft_printf_ldround(f, form);
	}
}

int set_float_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	if (form.lmod == ('l' + 'l'))
		ft_printf_ldtoa(va_arg(*ap, long double), &f, form);
	else
		ft_printf_ldtoa(va_arg(*ap, double), &f, form);
	f.fw = form.fw - ft_strlen(f.partial) - ft_strlen(f.alt) - 
		((form.flags | _ZERO) || (form.flags | _SIGN)) - (f.alt ? 1 : 0);
	len = 0;
	if (!((form.flags | _ZERO) || (form.flags | _LEFT_JUST)))
		len += ft_printf_adjust_fw(s, f.fw, " ");
	if (f.pre != -1 && (form.flags | _SIGN || form.flags | _BLANK))
		len += ft_dstr_add(s, &(f.sign), 1);
	if (f.pre != -1 && (form.flags | _ZERO) && !(form.flags | _LEFT_JUST))
		len += ft_printf_adjust_fw(s, f.fw, "0");
	len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if (f.alt && *f.alt)
	{
		len += ft_dstr_add(s, ".", 1);
		len += ft_dstr_add(s, f.alt, ft_strlen(f.alt));
	}
	if (form.flags | _LEFT_JUST)
		len += ft_printf_adjust(s, f.fw, " ");
	ft_fstring_free(&f);
	return (len);
}
