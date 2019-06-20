/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_con.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:10:41 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:24:14 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*get_unsigned_con(t_form form, unsigned long long value)
{
	if (form.type == 'b')
		return (ft_ulltoa_base(value, 2, form.cap));
	if (form.type == 'o')
		return (ft_ulltoa_base(value, 8, form.cap));
	if (form.type == 'x')
		return (ft_ulltoa_base(value, 16, form.cap));
	if (form.type == 'u')
		return (ft_ulltoa_base(value, 10, form.cap));
	return (ft_ulltoa_base(value, 10, form.cap));
}
