// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

static int max(int x, int y)
{
	return x > y ? x : y;
}

int max_profit_kadene(int *prices, int prices_size)
{
	int max_current, max_sofar;
	max_current = max_sofar = 0;
	for (int i = 1; i < prices_size; i++) {
		max_current += *(prices + i) - *(prices + i - 1);
		max_current = max(max_current, 0);
		max_sofar = max(max_current, max_sofar);
	}
	return max_sofar;
}

int maxProfit(int *prices, int prices_size)
{
	int min_val = *prices;
	int max_profit = 0;
	for (int i = 1; i < prices_size; i++) {
		if (*(prices + i) < min_val)
			min_val = *(prices + i);
		else
			max_profit = *(prices + i) - min_val > max_profit ?
				*(prices + i) - min_val : max_profit;
	}

	return max_profit;
}
