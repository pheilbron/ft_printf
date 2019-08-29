/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:14:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:02:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_dstring.h"

int	set_color_fstring(t_dstring *s, const char **f_string, int *pos)
{
	int				i;
	const t_color	color_tab[] = {{"{blk}", "\x1b[38;5;0]"},
		{"{red}", "\x1b[38;5;1]"}, {"{grn}", "\x1b[38;5;2]"},
		{"{yel}", "\x1b[38;5;3]"}, {"{blu}", "\x1b[38;5;4]"},
		{"{mag}", "\x1b[38;5;5]"}, {"{cyn}", "\x1b[38;5;6]"},
		{"{whi}", "\x1b[38;5;7]"}, {"{eoc}", "\x1b[38;5;0]"},
		{NULL, NULL}};

	i = 0;
	while (i < 9 && ft_memcmp(*f_string, color_tab[i].type, 5) != 0)
		i++;
	if (i < 9)
	{
		(*f_string) += 5;
		return (ft_dstr_add(s, color_tab[i].escape_code, 8));
	}
	(*pos)++;
	return (0);
}
