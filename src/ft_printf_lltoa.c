/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:16:24 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:20:07 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_stdlib.h"
#include "ft_string.h"

long long	ft_llpow(int base, int exp)
{
	long long	ret;

	ret = 1;
	while (exp-- > 0)
		ret *= (long long)base;
	return (ret);
}

void	ft_lltoa(long long n, t_fstring *f)
{
	int		digit;
	int		i;

	f->sign = (n >= 0 ? '+' : '-');
	if (n == LLONG_MIN)
		f->data = ft_strdup("9223372036854775808");
	else
	{
		n *= (f->sign == '-' ? -1 : 1);
		digit = 0;
		i = 0;
		while (n / ft_llpow(10, digit) >= 10)
			digit++;
		if (!(f->data = (char *)malloc(sizeof(*(f->data)) * (digit + 2))))
			return (NULL);
		while (digit >= 0)
		{
			f->data[i++] = (n / ft_llpow(10, digit)) + '0';
			n -= (n / ft_llpow(10, digit)) * ft_llpow(10, digit);
			digit--;
		}
		f->data[i] = '\0';
	}
}
