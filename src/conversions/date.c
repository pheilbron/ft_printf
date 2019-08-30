/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:09:33 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 18:51:42 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	set_date_fstring(t_dstring *s, t_form form, va_list *ap)
{
	va_list		empty;
	time_t		raw_time;
	struct tm	*t;
	const char	month[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct", "Nov", "Dec"};
	const char	day[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

	va_copy(empty, *ap);
	va_end(empty);
	form.flags = 0;
	time(&raw_time);
	t = localtime(&raw_time);
	return (ft_dstr_fadd(s, "%s %s %c%c:%c%c:%c%c %d", month[t->tm_mon],
			day[t->tm_wday], (t->tm_hour / 10) + '0', (t->tm_hour % 10) + '0',
			(t->tm_min / 10) + '0', (t->tm_min % 10) + '0',
			(t->tm_sec / 10) + '0', (t->tm_sec % 10) + '0', t->tm_year + 1900));
}
