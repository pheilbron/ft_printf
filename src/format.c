/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:12:41 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 19:40:08 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_init(t_form *format)
{
	format->flags = 0;
	format->fw = 0;
	format->pre = -1;
	format->lmod = 0;
	format->type = 0;
	format->cap = 0;
}

void	format_data(t_dstring *s, const char **f_string, int *i, va_list *ap)
{
	t_form	format;

	format_init(&format);
	if (is_data_flag((*f_string)[*i]))
		set_data_flags(f_string, i, &format);
	if (ft_isdigit((*f_string)[*i]) && (*f_string)[*i] != '0') 
		format.fw = ft_atoi_end(*f_string + *i, i);
	if ((*f_string)[*i] == '.')
		set_data_precision(f_string, i, &format);
	if (is_data_lmod((*f_string)[*i]))
		set_data_lmod(f_string, i, &format);
	format.type = (*f_string)[*i];
	if (is_data_conversion(format.type))
	{
		ft_form_clean(&format);
		(*convert_data)(format.type)(s, format, ap);
		*f_string += *i + 1;
		*i = 0;
	}
}

void	format_color(t_dstring *s, const char **f_string, int *i, va_list *ap)
{
	va_list	empty;

	va_copy(*a, empty);
	va_end(empty);
	set_color_fstring(s, f_string, pos);
}

void	format_basic(t_dstring *s, const char **f_string, int *i, va_list *ap)
{
	va_list	empty;

	va_copy(*ap, empty);
	va_end(empty);
	(*i)++;
}

void	(*convert(char *format, int i))(t_dstring *, const char **,
		int *, va_list *)
{
	if (format[i] == '%')
		return (&format_data);
	else if (check_color_format(format, i))
		return (&format_color);
	else
		return (&format_basic);
}
