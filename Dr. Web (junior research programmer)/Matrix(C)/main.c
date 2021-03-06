#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t Partition(int* arr, size_t left, size_t right)
{
	int temp = arr[right];
	int i = left - 1;

	for (int j = left; j < right; ++j)
		if (arr[j] >= temp)
		{
			int tmp = arr[j];
			
			++i;
			arr[j] = arr[i];
			arr[i] = tmp;
		}

	arr[right] = arr[i + 1];
	arr[i + 1] = temp;

	return i + 1;
}

void QuickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		size_t q = Partition(arr, left, right);
		QuickSort(arr, left, q - 1);
		QuickSort(arr, q + 1, right);
	}
}

int** generate(const int** matrix, size_t m, size_t n)
{
	int** result = (int**)malloc(m * sizeof(int*));
	int* columns = (int*)malloc(m * sizeof(int));

	for (int line = 0; line < m; ++line)
	{
		result[line] = (int*)malloc(n * sizeof(int));

		for (int column = 0; column < n; ++column)
			result[line][column] = matrix[line][column];
	}

	for (int column = 0; column < n; ++column)
	{		
		for (int index = 0; index < m; ++index)
			columns[index] = result[index][column];

		QuickSort(columns, 0, m - 1);

		for (int index = 0; index < m; ++index)
			result[index][column] = columns[index];
	}

	free(columns);

	for (int line = 0; line < m; ++line)	
		QuickSort(result[line], 0, n - 1);

	return result;
}

void main(void)
{
	size_t m;
	size_t n;

	scanf_s("%i%i", &m, &n);

	int** matrix = (int**)malloc(m * sizeof(int*));
	
	for (int i = 0; i < m; ++i)
		matrix[i] = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf_s("%i", &matrix[i][j]);


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf_s("%i ", matrix[i][j]);

		printf_s("\n");
	}

	int** result = generate(matrix, m, n);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf_s("%i ", result[i][j]);

		printf_s("\n");
	}
}