#ifndef _QUICK_SORT_HPP_
#define _QUICK_SORT_HPP_

template<typename T, typename _CmpFunc>
int partion(T *arr, size_t left, size_t right, _CmpFunc cmp)
{
	int div = (left + right) / 2;
	for (int i = left, j = right; i < j;)
	{
		while (arr[i] < arr[div])
			++i;
		while (arr[j] > arr[div])
			--j;

		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}

	return div;
}

template<typename T, typename _CmpFunc>
void QuickSortCall(T *arr, size_t left, size_t right, _CmpFunc cmp)
{
	if (left + 1 < right)
	{
		cout << left << " " << right << endl;
		int div = partion(arr, left, right, cmp);
		QuickSortCall(arr, left, div, cmp);
		QuickSortCall(arr, div, right, cmp);
	}
}

template<typename T, typename _CmpFunc>
void QuickSort(T* arr, size_t size, _CmpFunc cmp)
{
	QuickSortCall(arr, 0, size - 1, cmp);
}

#endif // !_QUICKSORT_HPP_
