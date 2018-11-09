/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:25:58 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:07:34 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_sudoku	*create_posibilite(int value, int i, int j)
{
	t_sudoku *element;

	element = (t_sudoku*)malloc(sizeof(t_sudoku));
	element->value = value;
	element->next = NULL;
	element->is_const = 'n';
	element->i = i;
	element->j = j;
	return (element);
}

void	add_posibilite(t_sudoku **head, int value, int i, int j)
{
	t_sudoku *elem;
	t_sudoku *tmp;

	elem = create_posibilite(value, i, j);
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	tmp = *head;
	*head = elem;
	elem->next = tmp;
}

void	supp_posibilite(t_sudoku **head, int value)
{
	t_sudoku *tmp;

	tmp = *head;
	if (*head == NULL || (tmp->value != value && !tmp->next))
	{
		return ;
	}
	if (tmp->value == value)
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next->next && tmp->next->value != value)
	{
		tmp = tmp->next;
	}
	if (tmp->next->value == value)
	{
		t_sudoku *dp;

		dp = tmp->next;
		tmp->next = tmp->next->next;
		free(dp);
	}
}

void	vider_list(t_sudoku **l)
{
	t_sudoku *tmp;

	if ((*l) == NULL)
	{
		free(l);
		return ;
	}
	tmp = *l;
	while (l)
	{
		tmp = *l;
		*l = (*l)->next;
		free(tmp);
	}
}

int	count_list(t_sudoku *l)
{
	int c;

	c = 0;
	while (l)
	{
		c++;
		l = l->next;
	}
	return (c);
}

