/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:27:37 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/03 15:30:28 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_vector	*g_con_string;

int		adjust_field_width(size_t fw_len, char *pad, size_t start)
{
	int	i;

	i = 0;
	while (g_con_string->pos - start < fw_len)
	{
		ft_vect_add(g_con_string, pad, 1);
		i++;
	}
	return (i);
}

int		adjust_integer_precision(size_t precision_len, size_t start)
{
	int	i;
	
	i = 0;
	while (g_con_string->pos - start < precision_len)
	{
		ft_vect_add(g_con_string, "0", 1);
		i++;
	}
	return (i);
}
