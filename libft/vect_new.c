/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:22:46 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/29 11:55:09 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vect_new(char *s, size_t len)
{
	t_vector	*v;

	if (!(v = malloc(sizeof(*v))))
		return (NULL);
	if (s)
	{
		if (!(v->string = ft_memalloc(sizeof(*s) * len)))
			return (NULL);
		ft_memcpy(v->string, s, len);
		v->len = len;
		v->pos = len;
	}
	return (v);
}
