/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:14:16 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:32:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)s;
	while (i < n)
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return (NULL);
}
