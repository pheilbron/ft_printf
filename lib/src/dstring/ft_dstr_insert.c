
#include "ft_dstring.h"
#include "ft_string.h"

void	ft_dstr_(t_dstring *s, char *new_data, size_t len)
{
	if (s->cap < s->pos + len)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len ? 0 : len));
	ft_memcpy(s->buf + s->pos, new_data, len);
	s->buf[s->pos + len] = '\0';
	s->pos += len;
}
