/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:15:22 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 00:18:55 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct sudoku sudoku;

struct sudoku {
	int value;
	int next;
	char is_const;
};

sudoku *create_posibilite(int value)
{
	sudoku *element = (sudoku*)malloc(sizeof(sudoku));
	element->value = value;
	element->next = NULL:
	element->is_const = 'n';
	return (element);
}

void	add_posibilite(sudoku **head, int value)
{
	sudoku *elem = create_posibilite(value);
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	sudoku *tmp = *head;
	*head = elem;
	elem->next = tmp;
}

void	supp_posibilite(sudoku **head, int value)
{
	sudoku *tmp = *head;
	if (tmp->value == value)
	{
		*head->next = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next->next && tmp->next->value !=value)
		tmp = tmp->next;
	if (tmp->next->value == value)
	{
		sudoku *dp = tmp->next;
		tmp->next = tmp->next->next;
		free(dp);
	}
}


int is_in_square(sudoku **t,int row, int col, int value)
{
	int i,j;
	i =0;j=0;
	while (i< 3)
	{
		while( j< 3)
		{
			if (t[i+(row - row % 3)][j+(col - col % 3)].value == value)
				return (1);
			j++;	
		}
		i++;
	}
	return (0);
}

int is_in_row(sudoku **t, int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[i][col].value == value)
			return (1);
		i++;
	}
	return (0);
}

int is_in_col(sudoku **t, int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[row][i].value == value)
			return (1);
		i++;
	}
	return (0);
}

void	affichage(sudoku **t)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < 9 )
	{
		
	}
}

int main(int argc, char **argv)
{
	sudoku Sudoku[9][9]={{{3,'y'},{0,'n'},{6,'y'},{5,'y'},{0,'n'},{8,'y'},{4,'y'},{0,'n'},{0,'n'}},
				{{5,'y'},{2,'y'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'}},
				{{0,'n'},{8,'y'},{7,'y'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{3,'y'},{1,'y'}},
				{{0,'n'},{0,'n'},{3,'y'},{0,'n'},{1,'y'},{0,'n'},{0,'n'},{8,'y'},{0,'n'}},
				{{9,'y'},{0,'n'},{0,'n'},{8,'y'},{6,'y'},{3,'y'},{0,'n'},{0,'n'},{5,'y'}},
				{{0,'n'},{5,'y'},{0,'n'},{0,'n'},{9,'y'},{0,'n'},{6,'y'},{0,'n'},{0,'n'}},
				{{1,'y'},{3,'y'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{2,'y'},{5,'y'},{0,'n'}},
				{{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{0,'n'},{7,'y'},{4,'y'}},
				{{0,'n'},{0,'n'},{5,'y'},{2,'y'},{0,'n'},{6,'y'},{3,'y'},{0,'n'},{0,'n'}}};

	
	return 0;
}
