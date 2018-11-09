/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 03:40:34 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 04:13:54 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"
#include <unistd.h>

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

ft_bool		close_door(ft_door *door)
{
	ft_putstr("Door closing...");
	door->state = CLOSE;
	return (TRUE);
}

ft_bool		is_door_open(ft_door door)
{
	ft_putstr("Door is open ?");
	return (door->state = OPEN);
}

ft_bool		is_door_close(ft_door *door)
{
	ft_putstr("Door is close ?");
	return (door->state = CLOSE);
}
