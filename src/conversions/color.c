/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:59:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/20 10:16:55 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "color_tab.h"

extern	t_vector	*g_con_string;

int	set_color_format_string(const char **s, int *pos)
{
	int	i;

	i = 0;
	while (g_color_tab[i].name && ft_memcmp(*s + 1, g_color_tab[i].name, 4) != 0)
		i++;
	if (g_color_tab[i].name)
	{
		(*s) += 5;
		return (ft_vect_add(g_con_string, g_color_tab[i].escape_code, 8));
	}
	(*pos)++;
	//return (ft_vect_add(g_con_string, (char *)s, 1));
	return (0);
}
