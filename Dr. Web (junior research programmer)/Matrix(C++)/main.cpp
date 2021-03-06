#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t Partition(vector<int>& arr, size_t left, size_t right)
{
	int temp = arr[right];
	int i = left - 1;

	for (int j = left; j < right; ++j)
		if (arr[j] >= temp)
		{
			++i;
			swap(arr[j], arr[i]);
		}
	
	swap(arr[right], arr[i + 1]);

	return i + 1;
}

void QuickSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		size_t q = Partition(arr, left, right);
		QuickSort(arr, left, q - 1);
		QuickSort(arr, q + 1, right);
	}
}

vector<int> generate(vector<int>& matrix, size_t m, size_t n)
{
	vector<int> temp(matrix);
	vector<int> column(m, 0);
	
	for (size_t count = 0; count < n; ++count)
	{
		for (size_t index = 0; index < m; ++index)
			column[index] = temp[index * n + count];

		QuickSort(column, 0, m - 1);

		for (size_t index = 0; index < m; ++index)
			temp[index * n + count] = column[index];
	}

	size_t offSet = 0;

	for (size_t count = 0; count < m; ++count)
	{
		QuickSort(temp, 0 + offSet, n - 1 + offSet);
		offSet += n;
	}

	return std::move(temp);
}

int main()
{
	int m, n;
	vector<int> matrix;

	cin >> m >> n;
	matrix.assign(m * n, 0);

	for (int& cell : matrix)
		cin >> cell;

	auto _matrix = generate(matrix, m, n);
	
	return 0;
}