/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectget.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:32:46 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/28 18:40:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vect_insert(t_vector *v, char *s, size_t len, size_t pos)
{
	if (v->len < v->pos + len)
		vect_extend(v, len);
	ft_memmove(v->string + pos + len, v->string + pos, v->pos - pos);
	ft_memcpy(v->string + pos, s, len);
	v->pos += len;
}
