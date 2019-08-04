/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:21:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 13:14:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

#define NAN (0.0 / 0)
#define NEG_INF (-1.0 / 0)
#define INF (1.0 / 0)

void		is_float_dne(long double n, t_fstring *f)
{
	if (n == NAN)
		f->data = ft_strdup("nan");
	else if (n == NEG_INF)
		f->data = ft_strdup("-inf");
	else if (n == INF)
		f->data = ft_stdup("inf");
	f->alt = NULL;
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

t_fstring	*ft_printf_ldtoa(long double n, t_fstring *f, t_form form)
{
	long double	decimal;
	int			i;

	decimal = (n < 0 ? -n : n) - (long long)(n < 0 ? -n : n);
	i = 0;
	if (is_float_dne(n, f))
		return (f);
	ft_printf_lltoa((long long)n, f);
	if (f->alt = malloc(sizeof(*f->alt) * (form.pre + 1)))
	{
		while (i < form.pre)
			f->alt[i++] = (int)(decimal *= 10) + '0';
		f->alt[i] = '\0';
		if (decimal >= 5)
			ft_printf_ldround(f, form);
	}
}
