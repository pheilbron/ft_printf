/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:18:55 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/11 18:58:48 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_init(t_form *format)
{
	format->alt = 0;
	format->zero = 0;
	format->left_just = 0;
	format->blank = 0;
	format->sign = 0;
	format->fw = 0;
	format->pre = -1;
	format->lmod = (char *)0;
	format->type = 0;
	format->cap = 0;
}

int	ft_islmod(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z');
}

int	ft_isconversion(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int	ft_isflag(char c)
{
	return (c == '0' || c == '#' || c == '-' || c == '+' || c == ' ');
}

long double	ft_negpow(int base, int exp)
{
	long double	ret;

	ret = 1;
	while (exp-- > 0)
		ret /= base;
	return (ret);
}

int	digit_at(long double n, int i)
{
	long double	ret;

	if (i < 0)
	{
		ret = n - (long long)n;
		while (i < 0)
		{
			ret *= 10;
			ret = ret - (long long)ret;
			i++;
		}
	}
	else
		ret = (long long)n % ft_pow(10, i);
	return ((int)ret);
}

long double	round(long double n, int precision)
{
	int	i;

	i = precision + 2;
	while (--i > 0 && digit_at(n, (i * -1)) >= 5)
		n += digit_at(n, i) * ft_negpow(10, i);
	
	return (n);
}
