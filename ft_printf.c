/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:28:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 18:44:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (format[i] != '\\' && format[i] != '%')
			i++;
		else
		{
			write(1, format, i);
			format += i;
			i = 0;
			if (format[i] == '\\')
				len += escape_char(&format, &i, &ap);
			else if (format[i] == '%')
				len += conversion(&format, &i, &ap);
		}
	}
	va_end(ap);
	return (len);
}
