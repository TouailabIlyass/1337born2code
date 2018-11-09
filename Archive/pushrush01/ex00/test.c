#include <stdio.h>

int main(int argc, char **argv)
{
    	   printf("%d\n",argc);
	  int i;
	i = 1;
	int j;
	while(i < argc)
	{	j =0;
		while(j<9){
		printf("%c (%d,%d)",argv[i][j],i,j);
		j++;
		}
		printf("\n");
		i++;
	}
		
	return (0);
}
