/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_con.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:53:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/03 15:56:09 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CON_H
# define T_CON_H

# include "ft_printf.h"

typedef struct	s_con
{
	char		type;
	int			(*f)();
}				t_con;

t_con	g_contab[] =
{
//	{'s', &s_charstring},
//	{'p', &integer},
	{'d', &di_decimal},
//	{'c', &c_char}
//	{'o', &integer},
//	{'u', &integer},
//	{'x', &integer},
	{'i', &di_decimal},
	{0, &di_decimal}
};

#endif
