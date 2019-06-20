/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:28:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 09:53:33 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	while (ft_islmod((*s)[*pos]))
	{
		format->lmod += (*s)[*pos];
		(*pos)++;
	}
	*s += *pos;
	*pos = 0;
}

void	clean_tform(t_form *f)
{
	if (f->type >= 'A' && f->type <= 'Z')
	{
		f->type += 'a' - 'A';
		f->cap = 1;
		f->lmod = (((!f->lmod || f->lmod == ('h' + 'h') ||
				f->lmod == 'h') && f->type != 'x') ? 'l': f->lmod);
	}
	if (!(f->type == 'a' || f->type == 'd' || f->type == 'e' || f->type == 'f'
				|| f->type == 'f' || f->type == 'g' || f->type == 'i'))
	{
		f->blank = 0;
		f->sign = 0;
	}
	if (f->pre == -1)
	{
		if (f->type == 'f' || f->type == 'g' || f->type == 'f'
				|| f->type == 'a')
			f->pre = 6;
		else if (f->type != 's' && f->type != 'x' && f->type != 'o' &&
				f->type != 'i' && f->type != 'd')
			f->pre = 0;
	}
	f->zero = (f->left_just || f->pre > 0) ? 0 : f->zero;
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
	clean_tform(&format);
	ret = (*get_con)(format.type)(format, ap);
	*s += *pos + 1;
	*pos = 0;
//	printf("zero: %c, sign: %c\n", format.zero + '0', format.sign + '0');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	g_con_string = ft_vect_new("", 0, 100);	
	while (format[i])
	{
		if (format[i] != '{' && format[i] != '%')
			i++;
		else
		{
			ft_vect_add(g_con_string, (char *)format, i);
			format += i;
			i = 1;
			if (format[i - 1] == '%')
				conversion(&format, &i, &ap);
//			else if (format[i - 1] == '{')
//				set_color_format_string(&format, &i);
		}
	}
	ft_vect_add(g_con_string, (char *)format, i);
	write(1, g_con_string->data, g_con_string->pos);
	va_end(ap);
	return (ft_vect_del(g_con_string));
}
