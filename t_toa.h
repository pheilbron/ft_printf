/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_toa.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:58:50 by pheilbro          #+#    #+#             */
/*   Updated: 2019/06/06 17:00:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef T_TOA_H
# define T_TOA_H

typedef struct	s_toa
{
	char		*type;
	char		*(*f)();
}				t_toa;

t_toa	g_dtoa[] =
{
//	{"hh", &sctoa},
	{"h", &stoa},
//	{"l", &ltoa},
//	{"ll", &lltoa},
//	{"j", &maxtoa},
//	{"z", &sizettoa},
	{0, &ft_itoa}
};

//t_toa	g_itooa[] =
//{
////	{"hh", &sctoa},
////	{"h", &stoa},
////	{"l", &ltoa},
////	{"ll", &lltoa},
////	{"j", &maxtoa},
////	{"z", &sizettoa},
//	{0, &itooa}
//};
//
//t_toa	g_itoxa[] =
//{
////	{"hh", &sctoa},
////	{"h", &stoa},
////	{"l", &ltoa},
////	{"ll", &lltoa},
////	{"j", &maxtoa},
////	{"z", &sizettoa},
//	{0, &itoxa}
//};

#endif
