/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:03:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 19:41:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list		ap;
	int			i;
	t_dstring	*s;

	va_start(ap, format);
	i = 0;
	s = ft_dstr_init((s = NULL));
	while (format[i])
	{
		if (is_con_indicator(format[i]))
		{
			ft_dstr_add(s, (char *)format, i);
			format += i;
			i = 1;
			(*convert((char *)format, i))(s, &format, &i, &ap);
		}
		else
			i++;
	}
	ft_dstr_add(s, (char *)format, i);
	ft_memcpy(str, s->buf, s->pos);
	va_end(ap);
	return (ft_dstr_free(s));
}
