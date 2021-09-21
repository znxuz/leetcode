// https://leetcode.com/problems/climbing-stairs/

int climbStairsRec(int n)
{
	if (n == 1 || n == 2)
		return n;
	return climbStairsRec(n - 1) + climbStairsRec(n - 2);
}

int climbStairs(int n)
{
	int ways[46];
	int i;
	for (i = 1; i <= n; i++) {
		if (i == 1 || i == 2)
			ways[i] = i;
		else
			ways[i] = ways[i - 1] + ways[i - 2];
	}

	return ways[n];
}
