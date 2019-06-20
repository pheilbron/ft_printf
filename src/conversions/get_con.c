/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:16:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_con.h"
#include "libft.h"

int		(*get_con(char type))(t_form, va_list *)
{
	size_t	i;

	i = 0;
	while (g_contab[i].type != 0)
	{
		if (g_contab[i].type == type)
			return (g_contab[i].f);
		i++;
	}
	return (g_contab[i].f);
}
