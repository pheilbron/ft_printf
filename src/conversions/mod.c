
#include "ft_printf.h"
#include "ft_dstring.h"

int	set_mod_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int		ret;
	va_list	empty;

	ret = 0;
	va_copy(empty, *ap);
	ret = form.fw;
//	if (!form.left_just && form.fw - 1 > 0)
//		ret += adjust_field_width(form.fw - 1, " ");
//	ret += ft_vect_add(g_con_string, "%", 1);
//	if (form.left_just && form.fw - 1 > 0)
//		ret += adjust_field_width(form.fw - 1, " ");
	return (ret);
}
