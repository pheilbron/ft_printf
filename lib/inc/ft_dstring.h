/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:34:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 18:36:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTRING_H
# define FT_DSTRING_H

# include <stdlib.h>

# define DSTRING_INIT_SIZE 8

typedef	struct	s_dstring
{
	char	*buf;
	size_t	cap;
	size_t	pos;
}				t_dstring;

t_dstring		*ft_dstr_init(t_dstring *s);
t_dstring		*ft_dstr_new(char *new_data, size_t len, size_t cap);
size_t			ft_dstr_add(t_dstring *s, char *data, size_t len);
size_t			ft_dstr_add_nc(t_dstring *s, char c, size_t len, size_t pos);
size_t			ft_dstr_insert(t_dstring *s, char *data, size_t len, size_t pos);
size_t			ft_dstr_insert_nc(t_dstring *s, char c, size_t len, size_t pos);
t_dstring		*ft_dstr_resize(t_dstring *s, size_t len);
void			ft_dstr_del(t_dstring *s, size_t index);
size_t			ft_dstr_free(t_dstring *s);

#endif
