#include "vector.h"
template<class T>
inline CVector<T>& CVector<T>::operator=(const CVector& other)
{
	if (this != &other)
	{
		if (_capacity < other._capacity)
		{
			delete[] arr;
			_capacity = other._capacity;
			arr = new T[_capacity];
		}
		_size = other._size;
		for (st i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<class T>
inline CVector<T>& CVector<T>::operator=(CVector&& other)
{
	std::swap(arr, other.arr);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
	other._size = 0;
	return *this;
}

template<class T>
inline void CVector<T>::push_back(const T& val)
{
	if (_size >= _capacity)
	{
		if (_capacity < DEFAULT_CAP)
			_capacity = DEFAULT_CAP;
		else
			_capacity *= 2;
		T* t_arr = new T[_capacity];
		for (st i = 0; i < _size; i++)
			t_arr[i] = arr[i];
		delete[] arr;
	}
	arr[_size++] = val;
}

template<class T>
inline void CVector<T>::push_back(T&& val)
{
	if (_size >= _capacity)
	{
		if(_capacity < DEFAULT_CAP)
			_capacity = DEFAULT_CAP;
		else
			_capacity *= 2;
		T* t_arr = new T[_capacity];
		for (st i = 0; i < _size; i++)
			t_arr[i] = arr[i];
		delete[] arr;
		arr = t_arr;
	}
	arr[_size++] = std::move(val);
}

template<class T>
inline void CVector<T>::resize(st n, T val)
{
	T* t_arr = new T[n];
	_size = _size < n ? _size : n;
	_capacity = n;
	for (st i = 0; i < _size; i++)
		t_arr[i] = arr[i];
	for (st i = _size; i < _capacity; i++)
		t_arr[i] = val;
	delete[] arr;
	arr = t_arr;
	_size = n;
}

template<class T>
inline void CVector<T>::reserve(st n)
{
	if (n <= _capacity)
		return;
	T* t_arr = new T[n];
	for (st i = 0; i < _size; i++)
		t_arr[i] = arr[i];
	delete[] arr;
	arr = t_arr;
	_capacity = n;
}

template<class T>
inline void CVector<T>::swap(CVector& other)
{
	std::swap(arr, other.arr);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
}

template<class T>
inline bool CVector<T>::operator==(const CVector& other) const
{
	if (_size != other._size)
		return false;
	bool test = true;
	for (st i = 0; i < _size; i++)
	{
		if (arr[i] != other[i])
		{
			test = false;
			break;
		}
	}
	return test;
}

template<class T>
inline bool CVector<T>::operator<(const CVector& other) const
{
	bool is_all_same = true;
	st min_size = _size < other._size ? _size : other._size;
	st idx = 0;
	for (; idx < min_size; idx++)
	{
		if (arr[idx] != other[idx])
		{
			is_all_same = false;
			break;
		}
	}

	if (is_all_same)
	{
		if (_size < other._size)
			return true;
	}
	else
	{
		if (arr[idx] < other[idx])
			return true;
	}
	return false;

	return false;
}

