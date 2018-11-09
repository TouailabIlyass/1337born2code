/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arbre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:17:30 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:36:48 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arbre.h"
#include "sudoku.h"
t_arbre	*create_arbre(t_sudoku *l)
{
	t_arbre	*element;

	element = (t_arbre*)malloc(sizeof(t_arbre));
	element->debut = l;
	element->next = NULL;
	return (element);
}

void	add_arbre(t_arbre **head, t_sudoku *l)
{
	t_arbre *tmp;
	t_arbre *elem;

	tmp = *head;
	elem = create_arbre(l);
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	*head = elem;
	elem->next = tmp;
}

void	supprimer_arbre(t_arbre *a, int value)
{
	while (a)
	{
		supp_posibilite(&(a->debut), value);
		a = a->next;
	}
}
