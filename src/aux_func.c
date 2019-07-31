/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:18:55 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 20:12:10 by pheilbro         ###   ########.fr       */
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
	format->lmod = 0;
	format->type = 0;
	format->cap = 0;
}

int	is_data_lmod(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z');
}

int	is_data_conversion(char c)
{
	return ((c >= 'a' && c <= 'g') || (c >= 'A' && c<= 'G') || c == 'i' ||
			c == 'k' || (c >= 'm' && c <= 'p') || c == 'O' || c == 'r' ||
			c == 's' || c == 'S' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == '%');
}

int	is_data_flag(char c)
{
	return (c == '0' || c == '#' || c == '-' || c == '+' || c == ' ');
}

int	is_con_indicator(char c)
{
	return (c == '%' || c == '{');
}
