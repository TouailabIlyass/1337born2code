/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 02:42:40 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 03:23:02 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define FT_PERSO_H
# define SAVE_THE_WORLD 1337
# include <string.h>

typedef struct t_perso	t_perso;

struct	t_perso	{
	char	*name;
	float	life;
	int		age;
	char	*profession;
};

#endif
