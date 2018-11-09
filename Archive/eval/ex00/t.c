/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 02:00:54 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/04 20:41:19 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_list t_list;
struct s_list
{
	int		value;
	char	op;
	t_list	*next;
	t_list	*prev;
};

int			ft_do_op(int nb1, int nb2, char op)
{
	if (op == '+')
		return (nb1 + nb2);
	if (op == '-')
		return (nb1 - nb2);
	if (op == '*')
		return (nb1 * nb2);
	if (op == '/')
		return (nb1 / nb2);
	if (op == '%')
		return (nb1 % nb2);
	return (0);
}

t_list		*create_element(int value, char op)
{
	t_list *element;

	element = (t_list*)malloc(sizeof(t_list));
	element->value = value;
	element->op = op;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	add_element(t_list **head, int value, char op)
{
	t_list *element;
	t_list *ptr;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
		element->prev = NULL;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = element;
	element->prev = ptr;
}

void	add_first(t_list **head, int value, char op)
{
	t_list *element;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	element->next = *head;
	*head = element;
	element->next->prev=element;
}
/*
void	add_plus(t_list **head, int value, char op, int pos)
{
	t_list ptr=*head;
	if (pos == 0)
	{

	}

}
*/
void	remove_element(t_list **head, int p)
{
	int i;
	t_list *ptr;

	i = 0;
	ptr = *head;
	while (ptr && i < p)
	{
		i++;
		ptr = ptr->next;
	}
}


void	show_list(t_list *head)
{
	while (head)
	{
		if (head->op == '?')
			printf("%d ", head->value);
		else
			printf("%c ", head->op);
		head = head->next;
	}
}

void	show_listinv(t_list *head)
{
	while(head->next)
		head= head->next;
	while (head)
	{
		if (head->op == '?')
			printf("%d ", head->value);
		else
			printf("%c ", head->op);
		head = head->prev;
	}


}

int		count_op(t_list *head)
{
	int c;

	 c = 0;
	 while (head)
	 {
		 if (head->op == '?')
			 c++;
	 }
	 return (c);
}

int 	ch_do_op(t_list *ptr, t_list **head)
{
	t_list *tmp=ptr;
	t_list *tmp2=NULL;
	t_list *dr=NULL;
	t_list *dr1=NULL;
	int value=0;
	int drapeau;
	while (tmp->op != '(')
	{
		tmp = tmp ->prev;
	}
	 drapeau = 1;
	while (drapeau)
	{
		drapeau = 0;
		tmp2=tmp;
		while (tmp2 != ptr)
		{
			if (tmp2->op == '*')
			{
				value = ft_do_op(tmp2->prev->value, tmp2->next->value, tmp2->op);
				tmp2->prev->value = value;
				dr=tmp2;
				dr1=tmp2->next;
				tmp2->prev->next = tmp2->next->next;
				tmp2->next->next->prev = tmp2->prev;
				tmp2=tmp2->prev;
				free(dr1);
				free(dr);
				///////////
				if (tmp2->prev->op == '(' && tmp2->next->op == ')')
				{printf("ttrtrttrtr\n\n\n");
					dr=tmp2->prev;
					dr1=tmp2->next;
					if (tmp2->prev->prev)
					{
						tmp2->prev->prev->next = tmp2;
						tmp2->prev = tmp2->prev->prev;
					}
					else 
					{
						tmp2->prev=NULL;
						*head=tmp2;
					}
					if (tmp2->next->next)
					{
						tmp2->next->next->prev = tmp2;
						tmp2->next= tmp2->next->next;
					}
					else
						tmp2->next=NULL;

					//free(dr1);
					//free(dr);
					return 0;
					tmp2=tmp2->prev;
				}
				///////////
				drapeau = 1;
			}
			tmp2=tmp2->next;
		}
		if (!drapeau) tmp2=tmp;
		while (tmp2 != ptr)
		{
			if (tmp2->op == '/' || tmp2->op == '%')
			{
				value = ft_do_op(tmp2->prev->value, tmp2->next->value, tmp2->op);
				tmp2->prev->value = value;
				dr=tmp2;
				dr1=tmp2->next;
				tmp2->prev->next = tmp2->next->next;
				tmp2->next->next->prev = tmp2->prev;
				tmp2=tmp2->prev;
				free(dr1);
				free(dr);

				if (tmp2->prev->op == '(' && tmp2->next->op == ')')
				{printf("ttrtrttrtr\n\n\n");
					dr=tmp2->prev;
					dr1=tmp2->next;
					if (tmp2->prev->prev)
					{
						tmp2->prev->prev->next = tmp2;
						tmp2->prev = tmp2->prev->prev;
					}
					else 
					{
						tmp2->prev=NULL;
						*head=tmp2;
					}
					if (tmp2->next->next)
					{
						tmp2->next->next->prev = tmp2;
						tmp2->next= tmp2->next->next;
					}
					else
						tmp2->next=NULL;

					//free(dr1);
					//free(dr);
					return 0;
					tmp2=tmp2->prev;
				}
				drapeau = 1;
			}
			tmp2=tmp2->next;
		}
		if (!drapeau) tmp2=tmp;
		while (tmp2 != ptr)
		{
			if (tmp2->op == '+' || tmp2->op == '-')
			{
				value = ft_do_op(tmp2->prev->value, tmp2->next->value, tmp2->op);
				tmp2->prev->value = value;
				dr=tmp2;
				dr1=tmp2->next;
				tmp2->prev->next = tmp2->next->next;
				tmp2->next->next->prev = tmp2->prev;
				tmp2=tmp2->prev;
				free(dr1);
				free(dr);

				if (tmp2->prev->op == '(' && tmp2->next->op == ')')
				{printf("ttrtrttrtr\n\n\n");
					dr=tmp2->prev;
					dr1=tmp2->next;
					if (tmp2->prev->prev)
					{
						tmp2->prev->prev->next = tmp2;
						tmp2->prev = tmp2->prev->prev;
					}
					else 
					{
						tmp2->prev=NULL;
						*head=tmp2;
					}
					if (tmp2->next->next)
					{
						tmp2->next->next->prev = tmp2;
						tmp2->next= tmp2->next->next;
					}
					else
						tmp2->next=NULL;

					//free(dr1);
					//free(dr);
					return 0;
					tmp2=tmp2->prev;
				}
				drapeau = 1;
			}
			tmp2=tmp2->next;
		}

	}

return value;
}

void	ft_calc(t_list **head)
{
	t_list *ptr = *head;
	while (ptr)
	{
		if (ptr->op == ')')
		{
			ch_do_op(ptr, head);	
		}
		ptr = ptr->next;
	}
}

int		main(int argc, char **argv)
{
	t_list *head;
	int x;
	int i;
	head = NULL;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
		//	x = argv[1][i] - '0';
			add_element(&head,atoi(&argv[1][i]), '?');
		}
		else if (argv[1][i] != ' ')
			add_element(&head, 0, argv[1][i]);
		i++;
	}
	show_list(head);
	ft_calc(&head);
	printf("\n\nafter\n\n");
	show_list(head);
	return (0);
}
