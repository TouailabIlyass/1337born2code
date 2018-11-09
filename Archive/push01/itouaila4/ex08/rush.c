/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:15:22 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/28 19:15:16 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct sudoku sudoku;

struct sudoku {
	char value;
	char is_const;
};

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

	int i,j;
	while (i<9)
	{
		while(j<9)
		{

		}
	}
	return 0;
}
