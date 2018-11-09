/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:26:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 21:47:46 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;
struct	s_list
{
	int		value;
	char	op;
	t_list	*next;
	t_list	*prev;
};

#endif
