#ifndef _INSERTION_SORT_HPP
#define _INSERTION_SORT_HPP_

#include <unistd.h>
#include <functional>
#include <algorithm>
#include <iostream>

template<typename T, typename >
void InsertionSort(T* arr, size_t size, bool cmp(const T& lvalue, const T& rvalue))
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (cmp(*(arr + i), *(arr + j)))
			{
				T tmp = *(arr + i);
				for (int h = i; h > j; --h)
				{
					*(arr + h) = *(arr + h - 1);
				}
				*(arr + j) = tmp;
				break;
			}
		}
	}
}

template<typename T, typename _CmpFunc>
void InsertionSort(T* arr, size_t size, _CmpFunc cmp)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (cmp(*(arr + i), *(arr + j)))
			{
				T tmp = *(arr + i);
				for (int h = i; h > j; --h)
				{
					*(arr + h) = *(arr + h - 1);
				}
				*(arr + j) = tmp;
				break;
			}
		}
	}
}

template<typename T>
void InsertionSort(T* arr, size_t size)
{
	InsertionSort(arr, size, std::less<T>());
}

template<typename T, typename _CmpFunc>
void ShellSort(T* arr, size_t size, _CmpFunc cmp)
{
	int gap = size / 2;
	while (gap > 0)
	{
		for (int i = gap; i < size; ++i)
		{
			for (int j = i; j >= 0; j -= gap)
			{
				if (cmp(*(arr + i), *(arr + j)))
				{
					T tmp = *(arr + i);
					*(arr + i) = *(arr + j);
					*(arr + j) = tmp;
				}
			}
		}
		gap /= 2;
	}
}

template<typename T>
void ShellSort(T* arr, size_t size)
{
	ShellSort(arr, size, std::less<T>());
}
#endif // !_INSERTION_SORT_HPP
