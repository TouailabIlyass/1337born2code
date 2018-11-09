/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitesspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:43:46 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/03 16:35:13 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		nbr_mots(char *str)
{
	int i;
	int count;
	int calc;

	count = 0;
	i = 0;
	calc = 1;
	while (str[i])
	{
		if (!is_space(str[i]) && calc == 1)
		{
			count++;
			calc = 0;
		}
		else if (is_space(str[i]))
				calc = 1;
		i++;
	}
	return (count);
}

char	*get_word(char **str)
{
	int i;
	char *word;
	int j;

	i = 0;
	while(str[0][i] && !is_space(str[0][i]))
	{
		i++;
	}
	word = (char *)malloc(sizeof(char) * i + 1);
	j = 0;
	while (j <= i)
	{
		word[j] = str[0][j];
		j++;
	}
	word[j] = '\0';
	*str =  *str +i;
	return word;
}

char	**ft_split_whitespaces(char *str)
{
	char **array;
	int nbm=nbr_mots(str);
	int i;

	array = (char**)malloc(sizeof(char*) * nbm+1);
	array[nbm] = NULL;
	i = 0;
	while (*str)
	{
		if (!is_space(*str))
		{	
			array[i] = get_word(&str);
			i++;
		}
		if (*str ==  '\0')
			break ;
		str++;
	}
	return (array);
}

int		main(int argc, char **argv)
{
	printf("%d\n",nbr_mots(argv[1]));
	char **array = ft_split_whitespaces(argv[1]);
	while (*array)
	{
		printf("%s\n",*array);
		array++;
	}

	return (0);
}
