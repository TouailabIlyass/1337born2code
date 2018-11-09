/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 00:09:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/22 04:47:47 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	sastantua(int size)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 1;
	while (i < size)
	{
		
		 j = 1;
		 while (j <= i + 3)
		 {
			 k = size*size-j;
			 while (k >= 0)
			 {
			 write(1," ",1);
			 k--; 
			 }
			 write(1,"/",1);
			if(i > 0)
			{	k = 1;
				while (k <= (i + 1)*2)
				{
					write(1,"*",1);
					k++;
				}

			}
			k = 1;
			 while (k < (2*j) )
			 {
			 write(1,"*",1);
			k++;
			 }
			 write(1,"\\\n",2);
			 j++;

			// write(1,"\n",1);
		 }
		 i++;
	}

}
int main()
{

	sastantua(5);
	return 0;
}
