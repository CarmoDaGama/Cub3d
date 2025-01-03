
#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(to_find);
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], to_find, len))
			return (&str[i]);
		i ++;
	}
	return (NULL);
}
