#include "libft.h"

int	ft_matrizlen(char **to_count)
{
	int	i;

	i = 0;
	if (!to_count)
		return (0);
	while (to_count[i])
		i ++;
	return (i);
}
