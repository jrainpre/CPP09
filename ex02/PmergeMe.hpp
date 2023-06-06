#include <algorithm>
#include <iostream>
#include <deque>
#include <string>
#include <vector>

template <typename T>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &rhs);
		void push(int const &val);
		void fj_sort(int start, int end);
		void print();
	private:
		void insert_sort(int start, int end);
		void merge_sort(int start, int end);
		T _data;
};

template <typename T>
PmergeMe<T>::PmergeMe()
{
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
	}
	return *this;
}

template <typename T>
void PmergeMe<T>::push(int const &val)
{
	_data.push_back(val);
}

template <typename T>
void PmergeMe<T>::insert_sort(int start, int end)
{
	int act;
	for (int i = start + 1; i <= end; i++)
	{
		act = _data[i];
		int j = i - 1;
		while (j >= start && _data[j] > act)
		{
			_data[j + 1] = _data[j];
			j--;
		}
		_data[j + 1] = act;
	}
}

template <typename T>
void PmergeMe<T>::merge_sort(int start, int end)
{
	
	if (end - start < 2)
		return;
	T left;
	T right;
	int i;
	int middle = start + (end - start) / 2;
	for (i = start; i <= middle; i++)
		left.push_back(_data[i]);
	for (i = middle + 1; i <= end; i++)
		right.push_back(_data[i]);
	int k = start;
	int left_i = 0;
	int right_i = 0;
	int left_size = left.size();
	int right_size = right.size();
	while (left_size > left_i && right_size > right_i)
	{
		if (left[left_i] <= right[right_i])
		{
			_data[k++] = left[left_i];
			left_i++;
		}
		else
		{
			_data[k++] = right[right_i];
			right_i++;
		}
	}
	while (left_size > left_i)
	{
		_data[k++] = left[left_i];
		left_i++;
	}
	while (right_size > right_i)
	{
		_data[k++] = right[right_i];
		right_i++;
	}
}

template <typename T>
void PmergeMe<T>::fj_sort(int start, int end)
{
	if (start >= end)
		return;
	if (end - start <= 10)
	{
		insert_sort(start, end);
		return;
	}
	int middle = start + (end - start) / 2;
	fj_sort(start, middle);
	fj_sort(middle + 1, end);
	merge_sort(start, end);
}

template <typename T>
void PmergeMe<T>::print()
{
	for (size_t i = 0; i < _data.size(); i++)
		std::cout << " " << _data[i];
}