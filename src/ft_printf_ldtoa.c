/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:21:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 16:11:22 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

void		is_float_dne(long double n, t_fstring *f, t_form form)
{
	if (n == NAN)
	{
		if (form.flags | _CAP)
			f->data = ft_strdup("NAN");
		else
			f->data = ft_strdup("nan");
	}
	else if (n == NEG_INF)
	{
		if (form.flags | _CAP)
			f->data = ft_strdup("-INF");
		else
			f->data = ft_strdup("-inf");
	}
	else if (n == INF)
	{
		if (form.flags | _CAP)
			f->data = ft_stdup("INF");
		else
			f->data = ft_stdup("inf");
	}
	f->alt = NULL;
	f->pre = -1;
}

void		ft_printf_ldround(f, form)
{
	int	i;

	i = form.pre - 1;
	f->alt[i]++;
	while (i >= 0 && f->alt[i] >= '5')
	{
		if (f->alt[i] == '9' + 1)
			f->alt[i] = '0';
		i++;
		f->alt[i]++;
	}
}

