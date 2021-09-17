#include "../include/list.h"
#include "function.h"

void check(void)
{
	TwoSum *obj = twoSumCreate();
	twoSumAdd(obj, 0);
	twoSumAdd(obj, 0);
	twoSumPrint(obj);
	printf("%s\n", twoSumFind(obj, 0) ? "yes" : "no");
}

int main(void)
{
	check();
	TwoSum *obj = twoSumCreate();
	twoSumAdd(obj, 1);
	twoSumAdd(obj, 3);
	twoSumAdd(obj, 5);
	twoSumAdd(obj, 7);
	twoSumAdd(obj, 9);

	twoSumAdd(obj, 2);
	twoSumAdd(obj, 10);
	twoSumAdd(obj, 4);
	twoSumAdd(obj, 6);
	twoSumAdd(obj, 8);


	twoSumPrint(obj);
	twoSumFree(obj);
}
