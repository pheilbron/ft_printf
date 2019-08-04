
#include "ft_printf.h"
#include "ft_dstring.h"

void	ft_get_char_fw(t_fstring *f, int fw)
{
	int	i;

	if ((f->fw = malloc(sizeof(*f->fw) * (fw))))
	{
		i = 0;
		while (i < fw - 1)
			f->fw[i++] = ' ';
		f->fw[i] = '\0';
	}
}

int	set_char_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	len = 0;
	if (form.lmod == 'l')
		f.partial = (char *)((wchar_t)va_arg(*ap, int));
	else
		f.partial = (char *)((char)va_arg(*ap, int));
	if (form.fw > 1)
		ft_get_char_fw(&f, form.fw);
	if (!(form.flags | _LEFT_JUST) && form.fw > 1)
		len += ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if (form.flags | _LEFT_JUST && form.fw > 1)
		len += ft_dstr_add(s, f.fw, ft_strlen(f.fw));
	ft_fstring_free(&f);
	return (len);
}
