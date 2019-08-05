
#include "ft_printf.h"
#include "ft_printf_conversions.h"

int		(*convert_data(char type))(t_dstring *, t_form, va_list *)
{
	size_t	i;
	t_con	contab[];
	
	i = 0;
	contab = {{'a', &get_float_hex_fstring},
		{'b', &set_unsigned_fstring}, {'c', &set_char_fstring},
		{'d', &set_int_fstring}, {'e', &set_e_notation_fstring},
		{'f', &set_float_fstring}, {'g', &set_choose_float_fstring},
		{'i', &set_int_fstring}, {'k', &set_date_fstring},
		{'m', &set_error_code_fstring}, {'n', &set_chars_written_fstring},
		{'o', &set_unsigned_fstring}, {'p', &set_pointer_fstring},
		{'r', &set_non_print_fstring}, {'s', &set_string_fstring},
		{'u', &set_unsigned_fstring}, {'x', &set_unsigned_fstring},
		{'%', &set_mod_fstring}, {0, &set_int_fstring}};
	while (contab[i].type != 0)
	{
		if (contab[i].type == type)
			return (contab[i].f);
		i++;
	}
	return (contab[i].f);
}
