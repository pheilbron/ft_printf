#include <stdio.h>
#include <wchar.h>
#include <inttypes.h>
#include <unistd.h>
#include <limits.h>
#include "libft/includes/libft.h"

int	main(void)
{
	t_vector *v;

	v = ft_vect_new("hi", 2, 10);
	ft_vect_add(v, " hi2", 4);
	ft_vect_add(v, " hi3", 4);
	ft_vect_add(v, " hi4", 4);
	ft_vect_add(v, " hi5", 4);
	ft_vect_add(v, "                 hi6", 20);
	printf("%s\n%zu\n%zu\n", v->data, v->pos, v->size);

//	printf("\x1b[38;5;0m%s\n", "asdf");
//	printf("\x1b[38;5;1m%s\n", "asdf");
//	printf("\x1b[38;5;2m%s\n", "asdf");
//	printf("\x1b[38;5;3m%s\n", "asdf");
//	printf("\x1b[38;5;4m%s\n", "asdf");
//	printf("\x1b[38;5;5m%s\n", "asdf");
//	printf("\x1b[38;5;6m%s\n", "asdf");
//	printf("\x1b[38;5;7m%s\n", "asdf");
//	printf("\x1b[38;5;8m%s\n", "asdf");
//	printf("\x1b[38;5;9m%s\n", "asdf");
//	printf("\x1b[38;5;10m%s\n", "asdf");
//	printf("\x1b[38;5;11m%s\n", "asdf");
//	printf("\x1b[38;5;12m%s\n", "asdf");
//	printf("\x1b[38;5;13m%s\n", "asdf");
//	printf("\x1b[38;5;14m%s\n", "asdf");
//	printf("\x1b[38;5;15m%s\n", "asdf");
	return (0);
}
