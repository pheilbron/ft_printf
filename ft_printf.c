/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:28:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/16 19:46:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char **s, int *len, va_list *ap)
{
	int	*
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
			i = 0;
			i++;
			len += conversion(&format, &i, &ap);
		}
		else
			i++;
	}
	write(1, format, i);
	va_end(ap);
	return (len + i);
}
