// https://leetcode.com/problems/search-insert-position/

static int bi_search_index(int *nums, int begin, int end, int target)
{
	if (end - begin <= 1) {
		if (*(nums + begin) == target)
			return begin;
		if (*(nums + end) == target)
			return end;
		return target > *(nums + begin)
			? target < *(nums + end) ? end : end + 1
			: begin - 1 < 0 ? 0 : begin - 1;
	}

	int mid = (begin + end) / 2;
	if (*(nums + mid) < target)
		return bi_search_index(nums, mid, end, target);
	if (*(nums + mid) > target)
		return bi_search_index(nums, begin, mid, target);
	else
		return mid;
}

int searchInsert(int* nums, int nums_size, int target)
{
	return bi_search_index(nums, 0, nums_size - 1, target);
}
