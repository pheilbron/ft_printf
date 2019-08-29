
#include "ft_printf.h"
#include "ft_dstring.h"

int	set_float_hex_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int i;
	va_list empty;

	i = form.fw + s->pos;
	va_copy(empty, *ap);
	return (i);
}

int	set_e_notation_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int i;
	va_list empty;

	i = form.fw + s->pos;
	va_copy(empty, *ap);
	return (i);
}

int	set_choose_float_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int i;
	va_list empty;

	i = form.fw + s->pos;
	va_copy(empty, *ap);
	return (i);
}

int	set_date_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int i;
	va_list empty;

	i = form.fw + s->pos;
	va_copy(empty, *ap);
	return (i);
}

int	set_error_code_fstring(t_dstring *s, t_form form, va_list *ap)
{
	int i;
	va_list empty;

	i = form.fw + s->pos;
	va_copy(empty, *ap);
	return (i);
}
