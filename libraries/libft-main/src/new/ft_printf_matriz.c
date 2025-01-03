#include "libft.h"

void	ft_printf_matriz(char **to_print)
{
	int	i;

	i = 0;
	if (!to_print)
		return ;
	while (to_print[i])
	{
		write(1, "Element ->", 10);
		write(1, to_print[i], ft_strlen(to_print[i]));
		write(1, "\n", 1);
		i ++;
	}
}
