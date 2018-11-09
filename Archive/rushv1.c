
#include <stdio.h>
#include<stdlib.h>
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
	int si;
	int sj;
	int l;
	int c;
	l = 0;
	si=0;
	sj=0;
	
	while(l < 3)
	{
	    c =0;
	    si+=3;sj=0;
	    while(c<3)
	    {
	        sj+=3;
	        ///////
	        i=si-3;
	        while(i<si)
	        {   
	            j=sj-3;
		        while(j<sj)
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
								
								        printf("%d[%d,%d]| ",k,i,j);
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
	      ////////
	      c++;  
	    }
	    l++;
	}


	i =0;
	
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
