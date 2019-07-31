/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:30:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 19:55:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_data_flags(const char **s, int *pos, t_form *format)
{
	while (is_data_flag((*s)[*pos]))
	{
		if ((*s)[*pos] == '#')
			format->flags |= _ALT;
		else if ((*s)[*pos] == '0')
			format->flags |= _ZERO;
		else if ((*s)[*pos] == '-')
			format->flags |= _LEFT_JUST;
		else if ((*s)[*pos] == '+')
			format->flags |= _SIGN;
		else if ((*s)[*pos] == ' ')
			format->flags = _BLANK;
		(*pos)++;
	}
}

void	set_data_precision(const char **s, int *pos, t_form *format)
{
	(*pos)++;
	if (ft_isdigit((*s)[*pos]))
		format->pre = ft_atoi_end(*s + *pos, pos);
	else
		format->pre = 0;
}

void	set_data_lmod(const char **s, int *pos, t_form *format)
{
	while (is_data_lmod((*s)[*pos]))
	{
		format->lmod += (*s)[*pos];
		(*pos)++;
	}
	*s += *pos;
	*pos = 0;
}

void	clean_tform(t_form *f)
{
	if (f->type >= 'A' && f->type <= 'Z')
	{
		f->type += 'a' - 'A';
		f->cap = 1;
		f->lmod = (((!f->lmod || f->lmod == ('h' + 'h') ||
				f->lmod == 'h') && f->type != 'x') ? 'l': f->lmod);
	}
	if (!(f->type == 'a' || f->type == 'd' || f->type == 'e' || f->type == 'f'
				|| f->type == 'f' || f->type == 'g' || f->type == 'i'))
	{
		f->blank = 0;
		f->sign = 0;
	}
	if (f->pre == -1)
	{
		if (f->type == 'f' || f->type == 'g' || f->type == 'f'
				|| f->type == 'a')
			f->pre = 6;
		else if (f->type != 's' && f->type != 'x' && f->type != 'o' &&
				f->type != 'i' && f->type != 'd')
			f->pre = 0;
	}
	f->zero = (f->left_just || f->pre > 0) ? 0 : f->zero;
}
