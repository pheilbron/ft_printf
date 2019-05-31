/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectget.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:32:46 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/29 11:54:08 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vect_add(t_vector *v, char *s, size_t len)
{
	if (v->len < v->pos + len)
		vect_extend(v, len);
	ft_memcpy(v->string + v->pos, s, len);
	v->pos += len;
}
