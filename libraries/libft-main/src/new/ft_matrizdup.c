#include "libft.h"

char	**ft_matrizdup(char **to_dup)
{
	int		i;
	char	**duplicated;

	if (!to_dup)
		return (NULL);
	duplicated = ft_calloc(sizeof(char *), ft_matrizlen(to_dup) + 1);
	if (!duplicated)
		return (NULL);
	i = 0;
	while (to_dup[i])
	{
		duplicated[i] = ft_strdup(to_dup[i]);
		i ++;
	}
	duplicated[i] = NULL;
	return (duplicated);
}
