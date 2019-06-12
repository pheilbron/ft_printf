/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:28:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/11 17:14:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_con.h"
#include "libft.h"

t_vector	*g_con_string;

void	set_flags(const char **s, int *pos, t_form *format)
{
	while (ft_isflag((*s)[*pos]))
	{
		if ((*s)[*pos] == '#')
			format->alt = 1;
		else if ((*s)[*pos] == '0')
			format->zero = 1;
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
		format->pre = ft_atoi_end(*s + *pos, pos);
	else
		format->pre = 0;
}

void	set_lmod(const char **s, int *pos, t_form *format)
{
	int	start;

	start = *pos;
	format->lmod = malloc(sizeof(*(format->lmod)) * 3);
	while (ft_islmod((*s)[*pos]))
	{
		*(format->lmod + *pos - start) = (*s)[*pos];
		(*pos)++;
	}
	*(format->lmod + *pos - start) = '\0';
	*s += *pos;
	*pos = 0;
}

char	*(*get_con(char type))(t_form, va_list *)
{
	size_t	i;

	i = 0;
	while (g_contab[i].type != 0)
	{
		if (g_contab[i].type == type)
			return (g_contab[i].f);
		i++;
	}
	return (g_contab[i].f);
}

void	clean_tform(t_form form)
{
	if (form.type >= 'A' && form.type <= 'Z')
	{
		form.type += 'a' - 'A';
		form.cap = 1;
		form.lmod = (!*form.lmod ? "l": form.lmod);
	}
	if (form.zero && form.sign)
		form.zero = 0;
	if (!(form.type == 'a' || form.type == 'd' || form.type == 'e' ||
				form.type == 'f' || form.type == 'f' || form.type == 'g' ||
				form.type == 'i'))
	{
		form.blank = 0;
		form.sign = 0;
	}
	if (form.pre == -1)
	{
		if (form.type == 'f' || form.type == 'g' || form.type == 'f' ||
				form.type == 'a')
			form.pre = 6;
		else
			form.pre = 0;
	}
}

int	conversion(const char **s, int *pos, va_list *ap)
{
	t_form	format;
	int		ret;

	format_init(&format);
	if (ft_isflag((*s)[*pos]))
		set_flags(s, pos, &format);
	if (ft_isdigit((*s)[*pos]) && (*s)[*pos] != '0') 
		format.fw = ft_atoi_end(*s + *pos, pos);
	if ((*s)[*pos] == '.')
		set_precision(s, pos, &format);
	if (ft_islmod((*s)[*pos]))
		set_lmod(s, pos, &format);
	format.type = (*s)[*pos];
	clean_tform(format);
	ret = set_format_string(format, (*get_con)(format.type)(format, ap));
	*s += *pos + 1;
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
	g_con_string = ft_vect_new("", 0, 100);	
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_vect_add(g_con_string, (char *)format, i);
			format += i;
			i = 1;
			len += conversion(&format, &i, &ap);
		}
		else
			i++;
	}
	ft_vect_add(g_con_string, (char *)format, i);
	write(1, g_con_string->data, g_con_string->pos);
	va_end(ap);
	return (g_con_string->pos);
}
