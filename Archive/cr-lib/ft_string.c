#include "ft_string.h"
#include "ft_putstr.h"
int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*(str + count))
		count++;
	ft_putstr(str);
	return (count);
}
