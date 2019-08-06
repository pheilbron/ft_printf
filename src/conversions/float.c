/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:07:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/05 18:37:12 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

void	ft_printf_ldtoa(long double n, t_fstring *f, t_form form)
{
	long double	decimal;
	int			i;

	decimal = (n < 0 ? -n : n) - (long long)(n < 0 ? -n : n);
	i = 0;
	if (!is_float_dne(n, f, form))
	{
		ft_printf_lltoa((long long)n, f);
		if ((f->alt = malloc(sizeof(*f->alt) * (form.pre + 1))))
		{
			while (i < form.pre)
			{
				f->alt[i++] = (int)(decimal *= 10) + '0';
				decimal -= (int)decimal;
			}
			f->alt[i] = '\0';
			if (decimal * 10 >= 5)
				ft_printf_ldround(f, i - 1);
		}
	}
}

int set_float_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == ('l' + 'l'))
		ft_printf_ldtoa(va_arg(*ap, long double), &f, form);
	else
		ft_printf_ldtoa(va_arg(*ap, double), &f, form);
	len = 0;
	f.head = s->pos;
	if (form.flags & _SIGN || form.flags & _BLANK)
		f.pre_i = f.head + (len +=
				ft_dstr_add(s, (form.flags & _SIGN ? &(f.sign) : " "), 1));
	if (!(form.pre == 0 && ft_strcmp(f.partial, "0")))
		len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if (f.alt && *f.alt)
	{
		len += ft_dstr_add(s, ".", 1);
		len += ft_dstr_add(s, f.alt, ft_strlen(f.alt));
	}
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
