/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:28:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/24 18:54:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(const char **s, int *pos, t_form *format)
{
	while (ft_isflag((*s)[*pos]))
	{
		if ((*s)[*pos] == '#')
			format->alt = 1;
		else if ((*s)[*pos] == '0')
			format->zero_pad = 1;
		else if ((*s)[*pos] == '-')
			format->left_just = 1;
		else if ((*s)[*pos] == '+')
			format->sign = 1;
		else if ((*s)[*pos] == ' ')
			format->blank = 1;
		(*pos)++;
	}
}

void	set_precision(const char **s, int *pos, t_form *format)
{
	(*pos)++;
	if (ft_isdigit((*s)[*pos]))
		format->precision = ft_atoi_end(*s + *pos, pos);
	else
		format->precision = 0;
}

void	set_length_mod(const char **s, int *pos, t_form *format)
{
	int	start;

	start = *pos;
	format->length_mod = malloc(sizeof(*(format->length_mod)) * 3);
	while (ft_islen_mod((*s)[*pos]))
	{
		*(format->length_mod + *pos - start) = (*s)[*pos];
		(*pos)++;
	}
	*(format->length_mod + *pos - start) = '\0';
	*s += *pos;
	*pos = 0;
}

int	(*get_con(char type))(t_form, va_list)
{
	size_t	i;

	i = 0;
	while (g_contab[i]->type != 0)
	{
		if (g_contab[i]->type == *type)
			return (g_contab[i]->f);
		i++;
	}
	return (g_contab[i]->f);
}

int	conversion(const char **s, int *pos, va_list *ap)
{
	t_form	format;
	int		ret;

	format_init(&format);
	if (ft_isflag((*s)[*pos]))
		set_flags(s, pos, &format);
	if (ft_isdigit((*s)[*pos]) && (*s)[*pos] != '0') 
		format.field_width = ft_atoi_end(*s + *pos, pos);
	if ((*s)[*pos] == '.')
		set_precision(s, pos, &format);
	if (ft_islen_mod((*s)[*pos]))
		set_length_mod(s, pos, &format);
	ret = (*get_con((*s)[*pos]))(format, ap);
	*s += *pos;
	*pos = 0;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += (int)write(1, format, i);
			format += i;
			i = 1;
			len += conversion(&format, &i, &ap);
		}
		else
			i++;
	}
	write(1, format, i);
	va_end(ap);
	return (len + i);
}
