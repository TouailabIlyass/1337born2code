#include <stdio.h>

union u_data
{
	int i;
	char c[1];
	float a;
};

int main(void)
{
	union u_data data;
	data.i = 42;
	printf("%lu\n", sizeof(union u_data));
	printf("%p iiii\n",&data);
	printf("%p ccc\n",(data.c));
	printf("%d ", data.c[0]);
	printf("%d ", *(data.c+1));
	printf("%d ", *(data.c+2));
	return (0);
}
