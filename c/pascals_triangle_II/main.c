#include <stdio.h>
#include "function.h"
#include "../include/array.h"

int main(void)
{
	int row = 4;
	int ret_size, *ret = getRow(row, &ret_size);
	print_arr(ret, ret_size);
}
