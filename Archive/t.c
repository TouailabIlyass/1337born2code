/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:13:07 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/06 17:13:16 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void
pchar(char c) {
	write(1, &c, 1);
}

static void
puthex(unsigned char c) {
	char base[16] = "0123456789abcdef";
	pchar(base[c / 16]);
	pchar(base[c % 16]);
}

static int
isprintable(int c) {
	/* Printable Object */
	return (c >= ' ' && c<= '~');
}

static void
print(unsigned char c) {
	/* Define FallBack Char */
	pchar(isprintable(c) ? c
			: '.');
}

static void
printline(unsigned char *str,
		  size_t start,
		  size_t max) {
	/* Memory Cursor */
	size_t i = start - 1;
	/* Hex Block Print */
	while (++i < (start + 16) && i < max) {
		puthex(str[i]);
		if (i % 2) {
			pchar(' ');
		}
	}
	/* Handle Formating */
	while (i < (start + 16)) {
		pchar(' ');
		pchar(' ');
		if (i % 2) {
			pchar(' ');
		}
		i++;
	}
	/* To start of memory block */
	i = start - 1;
	/* Reprint Block in raw */
	while (++i < (start + 16) && i < max) {
		print(str[i]);
	}
	pchar('\n');
}

void
print_memory(const void *addr, size_t size) {
	/* Cast Memory to usc */
	unsigned char *cast = (unsigned char*)addr;
	/* Memory Iterator*/
	size_t i = 0;
	/* Compute to the length */
	while (i < size) {
		printline(cast, i, size);
		/* Iterate over hex base*/
		i += 16;
	}
}

int
main(void)
{
	int tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};
	print_memory(tab, sizeof(tab));
	return (0);
}
