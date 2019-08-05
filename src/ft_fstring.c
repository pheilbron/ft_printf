#include "ft_printf.h"

void	ft_fstring_init(t_fstring *f)
{
	f->head = 0;
	f->sign = 0;
	f->alt = NULL;
	f->pre_i = 0;
	f->pre = 0;
	f->partial = NULL;
	f->fw = 0;
}

void	ft_fstring_free(t_fstring *f)
{
	if (f->alt)
		free(f->alt);
	if (f->partial)
		free(f->partial);
	free(f);
}
