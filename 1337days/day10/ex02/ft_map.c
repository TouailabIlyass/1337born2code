/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:05:47 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:51:18 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	array = (int*)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		*(array + i) = (*f)(*(tab + i));
		i++;
	}
	return (array);
}
