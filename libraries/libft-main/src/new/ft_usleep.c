#include "libft.h"

void	ft_usleep(size_t time)
{
	size_t	start;

	time = time / 1000;
	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(500);
}
