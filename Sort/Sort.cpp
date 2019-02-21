#include "MySort.h"
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

void PrintArr(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

template<typename T>
bool cmp(const T& lvalue, const T& rvalue)
{
	return lvalue > rvalue;
}

int main()
{
	int arr[10] = { 0,2,1,4,3,5,6,9,8,7 };
	PrintArr(arr, 10);
	QuickSort(arr, 10, greater<int>());
	PrintArr(arr, 10);
	
	return 0;
}