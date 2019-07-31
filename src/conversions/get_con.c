/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 20:36:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_conversions.h"

int		(*get_con(char type))(t_form, va_list *)
{
	size_t	i;
	t_con	contab[] = {{'a', &get_float_hex_fstring},
		{'b', &set_binary_fstring}, {'c', &set_char_fstring},
		{'d', &set_int_fstring}, {'e', &set_e_notation_fstring},
		{'f', &set_float_fstring}, {'g', &set_choose_float_fstring},
		{'i', &set_int_fstring}, {'k', &set_date_fstring},
		{'m', &get_error_code}, {'n', &set_chars_written},
		{'o', &set_octal_fstring}, {'p', &get_pointer_partial},
		{'r', &set_non_print_fstring}, {'s', &set_string_fstring},
		{'u', &set_unsigned_fstring}, {'x', &set_hex_fstring},
		{'%', &set_mod_fstring}, {0, &set_int_fstring}};

	i = 0;
	while (contab[i].type != 0)
	{
		if (contab[i].type == type)
			return (contab[i].f);
		i++;
	}
	return (contab[i].f);
}
