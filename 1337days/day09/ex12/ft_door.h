/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 03:53:24 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 04:30:02 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define TRUE 1
# define FALSE 0
# define OPEN 1
# define CLOSE 0

typedef int	ft_bool;
typedef struct ft_door	ft_door;

struct	ft_door
{
	int state;
};

void	ft_putstr(char *str);
t_bool	is_door_open(t_door *door);
t_bool	open_door(t_door *door);
t_bool	close_door(t_door *door);
t_bool	is_door_close(t_door *door);

#endif
