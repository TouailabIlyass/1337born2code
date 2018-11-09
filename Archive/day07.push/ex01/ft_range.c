/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:14:14 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:14:16 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int i;

	if (min >= max)
		return (NULL);
	range = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		*(range + i) = min;
		i++;
		min++;
	}
	return (range);
}
