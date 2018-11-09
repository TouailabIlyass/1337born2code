/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:21:39 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 21:38:02 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	afficher(t_list *debut)
{
while (debut)
	{
		printf("%d ",*((int*)debut->data));
		debut = debut->next;
	}
	printf("\n");
}

void	ft_list_push_back(t_list **, void *);
void	ft_list_push_front(t_list **, void *);
int ft_list_size(t_list *);
t_list	*ft_list_last(t_list *);
void	ft_list_reverse(t_list ** );

int main(int argc , char **argv)
{

	t_list *debut=NULL;
	t_list *ptr;
	int x=8;
	debut=ft_create_elem(&x);
	int y= 9;
	ft_list_push_back(&debut,&y);
	int z = 1;
	ft_list_push_back(&debut,&z);
	int a = 5;
	ft_list_push_back(&debut,&a);
	afficher(debut);
	int a1 = 2;
	ft_list_push_front(&debut,&a1);
	afficher(debut);
	printf("%d list size\n",ft_list_size(debut));
	ptr= ft_list_last(debut);
	printf("%d last\n",*((int*)ptr->data));
	ft_list_reverse(&debut);
	afficher(debut);
	return (0);
}	
