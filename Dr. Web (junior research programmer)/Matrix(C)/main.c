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

//time: O(n * m * (log(m) + log(n) ) )
//mem: O(n + m)
int** generate(const int** matrix, size_t m, size_t n)
{
	int** result = (int**)malloc(m * sizeof(int*));
	int* tempArr = (int*)malloc(m * sizeof(int));

	for (int line = 0; line < m; ++line)
		result[line] = (int*)malloc(n * sizeof(int));

	for (int line = 0; line < m; ++line)
		for (int column = 0; column < n; ++column)					
			result[line][column] = matrix[line][column];				
	
	for (int column = 0; column < n; ++column)
	{		
		for (int index = 0; index < m; ++index)
			tempArr[index] = result[index][column];

		QuickSort(tempArr, 0, m - 1);

		for (int index = 0; index < m; ++index)
			result[index][column] = tempArr[index];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf_s("%i ", result[i][j]);

		printf_s("\n");
	}

	free(tempArr);

	for (int line = 0; line < m; ++line)	
		QuickSort(result[line], 0, n - 1);
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf_s("%i ", result[i][j]);

		printf_s("\n");
	}

	return result;
}


void main(void)
{
	size_t m;
	size_t n;

	scanf_s("%i%i", &m, &n);

	//int* matrix = (int)malloc(m * n * sizeof(int));
	//
	////fill matrix with random nums from 0 to 99
	//for (int i = 0; i < m; ++i)
	//	for (int j = 0; j < n; ++j)
	//		matrix[i * j + j] = rand() % 100;

	//second way but not as effective as first
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
}