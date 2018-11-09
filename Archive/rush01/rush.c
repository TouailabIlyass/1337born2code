/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:15:22 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 02:18:23 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
int is_in_square(int t[9][9],int row, int col, int value)
{
	int i,j;
	i =0;
	while (i< 3)
	{	j =0;
		while( j< 3)
		{
			if (t[i+row][j+col] == value)
				return (1);
			j++;	
		}
		i++;
	}
	return (0);
}

int is_in_row(int t[9][9], int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[i][col] == value)
			return (1);
		i++;
	}
	return (0);
}

int is_in_col(int t[9][9], int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[row][i] == value)
			return (1);
		i++;
	}
	return (0);
}
void	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	affichage(int t[9][9])
{
	int i;
	int j;
	i = 0;
	while (i < 9 )
	{
	j = 0;
		while (j< 9)
		{
			printf("%d | ",t[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void posi(int t[9][9])
{
	int i,j;
	int k;
	int s;
	int z;
	i =0;
	s =0;
	z  = 0;
	while(s<3)
	{//debu
	   i =0;
	   z+=3;
		while(i<3)
		{ j= 0;
			while(j<z)
			{	
				if(t[i][j] == 0)
				{	k = 1;
					while( k<= 9)
					{
						if(!is_in_square(t,i-i%3,j-j%3,k))
						{
							if(!is_in_row(t,i,j,k))
							{
								if(!is_in_col(t,i,j,k))
								{
								
									printf("%d | ",k);
								}
							}
						}
					k++;
					}
					printf("\n");
				}
				j++;
			
			}
			i++;
		}
		s++;

///////fin
	}
	
}


int main(int argc, char **argv)
{
	int Sudoku[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	//affichage(Sudoku);
	posi(Sudoku);

	return 0;
}
