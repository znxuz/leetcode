unsigned int table[90] = { // only need space till max ASCII value (X = 88)
	['I'] = 1,
	['V'] = 5,
	['X'] = 10,
	['L'] = 50,
	['C'] = 100,
	['D'] = 500,
	['M'] = 1000
};

int romanToInt(char *str)
{
	int res = 0;
	char next;
	while (*str) {
		next = *(str + 1);
		if (table[*str] < table[next])
			res -= table[*str];
		else
			res += table[*str];
		str++;
	}
	
	return res;
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", romanToInt("IV"));
	printf("%d\n", romanToInt("MCMXCIV"));
}
