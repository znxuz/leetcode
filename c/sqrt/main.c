// https://leetcode.com/problems/sqrtx/

#include <math.h>

int mySqrt(int x)
{
	int base;

	if (x < 0)
		return (0);
	base = 0;
	do {
		if (base * base == x)
			return base;
	} while (++base < 46341 && base * base <= x);

	return --base;
}

int ft_sqrt(int nb)
{
	int base;

	if (nb < 0)
		return (0);
	base = 0;
	while (base < 46341 && base * base <= nb)
	{
		if (base * base == nb)
			return (base);
		base++;
	}
	return --base;
}

#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 100; i++)
		printf("i: %d, sqrt(i): %d\n", i, ft_sqrt(i));
}
