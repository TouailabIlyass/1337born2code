/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 00:09:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/22 20:52:43 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
void	dessin(int i)
{
	int k;
    int j;
	k = 0;

	while (k < 50 - i)
	{
		printf(" ");
		k++;
	}
	printf("/");
	j=1;
	while (j<i*2)
	{
		printf("*");
		j++;
	}
	printf("\\");
	printf(" %d j = %d\n",i,j-1);
}

void	sastantua(int size)
{
	int i;
	int z;
	int cpt;
	int v;
	int fl;
	int cpf;
	int s = 2;
	i = 1;
	z = 1;
	cpt = 1;
	cpf=0;
	v = 3;
	fl = 1;
	while (z < size)
	{   	
	   cpt=1;
		while (cpt < z+3)
		{
		//if(fl % 2 != 0) s = s+2;

				if(cpf == 0 && fl >1) i = i+s; 
		dessin(i);
        cpf++;
		if(cpf == v)
		{
			v++;
			cpf=0;
			fl++;
			if(fl % 2 !=0 )
			s++;
		}
		
		i++;
		cpt++;
		}
		z++;
	
	}
	


}
int main()
{

	sastantua(5);
	return 0;
}
