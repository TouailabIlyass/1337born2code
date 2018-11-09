/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:14:38 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:14:39 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*(str + count))
		count++;
	return (count);
}

char	*ft_str_alloc(int argc, char **argv)
{
	int		i;
	char	*str;
	int		size;

	i = 1;
	size = argc - 1;
	while (i < argc)
	{
		size += ft_strlen(argv[i]);
		i++;
	}
	str = (char*)malloc(sizeof(char) * size);
	return (str);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = ft_str_alloc(argc, argv);
	if (str == NULL)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			*(str + k) = argv[i][j];
			j++;
			k++;
		}
		*(str + k) = '\n';
		k++;
		i++;
	}
	*(str + k - 1) = '\0';
	return (str);
}
