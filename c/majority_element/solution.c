// https://leetcode.com/problems/majority-element/

static void merge(int *arr, int left, int mid, int right)
{
	int sorted[right - left + 1];
	int index = 0;
	int l = left;
	int r = mid + 1;

	while (l <= mid && r <= right) {
		if (*(arr + l) <= *(arr + r))
			*(sorted + index++) = *(arr + l++);
		else
			*(sorted + index++) = *(arr + r++);
	}
	while (l <= mid)
		*(sorted + index++) = *(arr + l++);
	while (r <= right)
		*(sorted + index++) = *(arr + r++);

	for (int i = 0; i < index; i++, left++)
		*(arr + left) = *(sorted + i);
}

void merge_sort(int *arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int majorityElement(int *nums, int nums_size)
{
	merge_sort(nums, 0, nums_size - 1);
	return *(nums + nums_size / 2);
}
