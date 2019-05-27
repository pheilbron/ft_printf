/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:16:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/20 13:00:43 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar('-');
		temp = (long)n * -1;
	}
	if (temp >= 10)
		ft_putnbr(temp / 10);
	ft_putchar((temp % 10) + '0');
}

//void	ft_putnbr(int n)
//{
//	if (n < 0)
//	{
//		ft_putchar('-');
//		ft_putchar(((n % 10) * -1) + '0');
//		ft_putnb((n / 10) * -1);
//	}
//	if (n >= 10)
//		ft_putnbr(n / 10);
//	ft_putchar((n % 10) + '0');
//}
