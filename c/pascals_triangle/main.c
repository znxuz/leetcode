#include <stdio.h>
#include "function.h"
#include "../include/array.h"

static void print_triangle(int **triangle, int row, int *col_sizes)
{
	// for (int i = 0; i < row; i++) {
		// for (int j = 0; j <= i; j++)
			// printf("%d ", *(*(triangle + i) + j));
		// printf("\n");
	// }

	// this shit was nasty to code && usable only if row <= 5
	for (int i = 0; i < row * 2; i++)
		printf("%d", i);
	printf("\n");
	for (int i = 0; i < row; i++) {
		int col_index = 0;
		for (int j = 0; j < row * 2; j++) {
			if (i % 2 == 0 && j >= row - i) {
				if (j % 2 != 0 && col_index <= i)
					printf("%d", *(*(triangle + i) + col_index++));
				else
					printf(" ");
			} else if (i % 2 != 0 && j >= row - i) {
				if (j % 2 == 0 && col_index <= i)
					printf("%d", *(*(triangle + i) + col_index++));
				else
					printf(" ");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

static void free_triangle(int **triangle, int return_size)
{
	for (int i = 0; i < return_size; i++)
		free(triangle[i]);
	free(triangle);
}

int main(void)
{
	int row = 5, return_size, *return_col_size;
	int **triangle = generate(row, &return_size, &return_col_size);
	print_triangle(triangle, return_size, return_col_size);
	free_triangle(triangle, return_size);
}
