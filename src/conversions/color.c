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

int	set_color_format_string(const char **s, int *pos)
{
	int		i;
	char	(*color_tab)[];
	
	i = 0;
	color_tab[] = {{"{blk}", "\x1b[38;5;0]"}, {"{red}", "\x1b[38;5;1]"},
		{"{grn}", "\x1b[38;5;2]"}, {"{yel}", "\x1b[38;5;3]"},
		{"{blu}", "\x1b[38;5;4]"}, {"{mag}", "\x1b[38;5;5]"},
		{"{cyn}", "\x1b[38;5;6]"}, {"{whi}", "\x1b[38;5;7]"},
		{"{eoc}", "\x1b[38;5;0]"}, {NULL, "\x1b[38;5;0]"}};
	while (color_tab[i].name && ft_memcmp(*s + 1, color_tab[i].name, 4) != 0)
		i++;
	if (color_tab[i].name)
	{
		(*s) += 5;
		return (ft_vect_add(g_con_string, g_color_tab[i].escape_code, 8));
	}
	(*pos)++;
	//return (ft_vect_add(g_con_string, (char *)s, 1));
	return (0);
}
