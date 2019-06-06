/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:27:37 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/06 15:44:27 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_vector	*g_con_string;

int		adjust_field_width(int	fw_len, char *pad)
{
	int	i;
	size_t	start;
	
	i = 0;
	start = g_con_string->pos;
	while (fw_len > 0 && g_con_string->pos - start < (size_t)fw_len)
	{
		ft_vect_add(g_con_string, pad, 1);
		i++;
	}
	return (i);
}

int		adjust_integer_precision(int pre_len)
{
	int	i;
	size_t	start;
	
	i = 0;
	start = g_con_string->pos;
	while (pre_len > 0 && g_con_string->pos - start < (size_t)pre_len)
	{
		ft_vect_add(g_con_string, "0", 1);
		i++;
	}
	return (i);
}
