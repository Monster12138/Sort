#ifndef _INSERTION_SORT_HPP
#define _INSERTION_SORT_HPP_

template<typename T>
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

template<typename T, typename _Ptr>
void InsertionSort(T* arr, size_t size, _Ptr cmp)
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
	InsertionSort(arr, size, less<T>());
}
#endif // !_INSERTION_SORT_HPP
