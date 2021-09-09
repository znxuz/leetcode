// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// TODO Kadane's algorithm
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-%3A)-(In-case-if-interviewer-twists-the-input)

int maxProfit(int *prices, int prices_size)
{
	int min_val = 2147483647;
	int max_profit = 0;
	for (int i = 0; i < prices_size; i++) {
		if (*(prices + i) < min_val)
			min_val = *(prices + i);
		else
			max_profit = *(prices + i) - min_val > max_profit ?
				*(prices + i) - min_val : max_profit;
	}

	return max_profit;
}
