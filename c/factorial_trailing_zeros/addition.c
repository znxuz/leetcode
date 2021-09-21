// count pairs of 2 and 5
// because the count of 2 is always more than 5
// only need to count ocurrences of 5
// and break down squares of 5
int trailingZeroes_solution(int n)
{
	int five = 0;
	for (int i = 0; i <= n; i += 5) {
		int current = i;
		while (current && current % 5 == 0) {
			five++;
			current /= 5;
		}
	}

	return five;
}
