/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:39:22 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/26 17:32:38 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		second;
	char	*x;
	char	*y;

	if (hour >= 12)
		x = "P.M.";
	else
		y = "A.M.";
	if (hour + 1 >= 12 && hour != 23)
		y = "P.M.";
	else if (hour + 1 < 12 || hour == 23)
		y = "A.M.";
	if (hour >= 12)
		hour -= 12;
	if (hour == 0)
		hour = 12;
	second = hour + 1;
	if (hour + 1 > 12)
		second = 1;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%.2d.00 %s AND %.2d.00 %s\n", hour, x, second, y);
}
