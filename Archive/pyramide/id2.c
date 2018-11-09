/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 00:09:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/22 17:03:50 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
void	sastantua(int size)
{
	int i;
	int j;
	int k;
	int v=0;
	int n=size*size;
	i = 1;
	j = 1;
	while ( i <=50)
	{
		k=0;
		while(k<50-i)
		{
		printf(" ");
		k++;
		}
		j=1;
		while(j<i*2)
		{
			printf("*");
			j++;	
		}
		printf(" %d j = %d\n",i,j-1);
		


		i++;
	}


}
int main()
{

	sastantua(5);
	return 0;
}
