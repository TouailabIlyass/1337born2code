#include <stdio.h>
#include "ft_string.h"
#include "ft_putstr.h"

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%d", ft_strlen(argv[1]));
	printf("%d",false);
	return (0);
}
