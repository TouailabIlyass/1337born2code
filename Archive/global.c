#include <stdio.h>

void	ft_sort(void *array, int length, int(*cmp)(void*, void*), void(*swap)(void*, void*))
{
	int i;
	int is_sorted;

	is_sorted = 1;
	while (is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*cmp)((array + i), (array + i + 4)) > 0)
			{
				(*swap)((array + i), (array + i + 4));
				is_sorted = 0;
			}
			i++;
		}
		length--;
	}
}

void	ft_swap(void *arg1, void *arg2)
{
	int z;
	int *a;
	int *b;

	a = (int*)arg1;
	b = (int*)arg2;
	z = *a;
	printf("swap: %d %d\n", *a, *b);
	*a = *b;
	*b = z;
}


int		ft_cmp(void *arg1, void *arg2)
{
	int *a;
	int *b;

	a = (int*)arg1;
	b = (int*)arg2;
	printf("cmp: %d %d\n\n", *a, *b);
	if (*a > *b)
		return (1);
	else if (*a < *b)
		return (-1);
	else
		return (0);
}

int main(void)
{
	int		a = 42;
	void	*g_ptr = &a;
	int		*i_ptr;
	i_ptr = (int*)g_ptr;
	printf("%d", *i_ptr);
	return (0);
	int tab[] = {9, 8, 7, 6, 4, 3, 2, 1};
	int *t2 = &tab[0];
	int size = 8;
	ft_sort(t2, size, &ft_cmp, &ft_swap);
	int i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
