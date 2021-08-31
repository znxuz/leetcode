// TODO what is this algorithm

int ft_sqrt(int x)
{
	int low = 0;
	int high = x;
	int mid;
	
	if (x < 0)
		return 0;
	if (x <= 1)
		return x;
	while (high - low > 1) {
		mid = low + (high - low) / 2;
		if (mid > x / mid)
			high = mid;
		else if (mid <= x / mid)
			low = mid;
	}
	return low;
}
