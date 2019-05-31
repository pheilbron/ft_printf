/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:44:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/05/29 11:57:31 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vect_extend(t_vector *v, size_t len)
{
	t_vector	*temp;

	temp = vect_new(v->string, v->pos);
	vect_del(v);
	v = vect_new(temp->string,
			(temp->len > len ? temp->len * 2 : (temp->len * 2) + len));
	vect_del(temp);
}
