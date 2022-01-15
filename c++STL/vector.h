#pragma once
// https://lazyren.github.io/devlog/vector.html

#include <cstddef>
#include <utility>

template <class T>
class CVector
{
private:
	using st = size_t;
	T* arr;
	st _size;
	st _capacity;
	static constexpr st DEFAULT_CAP = 32;

public:
	// 积己
	CVector(st cap = DEFAULT_CAP) : arr(new T[cap]), _size(0), _capacity(cap) {}
	// 汗荤 积己磊
	CVector(const CVector& v) : arr(new T[v._capacity]), _size(v._size), _capacity(v._capacity)
	{
		for (st i = 0; i < _size; i++)
		{
			arr[i] = v[i];
		}
	}
	// 捞悼 积己磊
	CVector(CVector&& v) : arr(std::move(v.arr)), _size(std::move(v._size)), _capacity(std::move(v._capacity))
	{
		v.arr = nullptr;
		v._size = 0;
		v._capacity = 0;
	}

	~CVector() { delete[] arr; }

	CVector& operator=(const CVector& other);
	CVector& operator=(CVector&& other);

	inline T* begin() const { return arr; }
	inline T* end() const { return arr + _size; }

	inline T& front() { return arr[0]; }
	const inline T& front() const { return arr[0]; }

	inline T& back() { return arr[_size - 1]; }
	const inline T& back() const { return arr[_size - 1]; }

	inline T& operator[](st idx) { return arr[idx]; }
	const inline T& operator[](st idx) const { return arr[idx]; }

	void push_back(const T& val);
	void push_back(T&& val);

	void pop_back() { _size = _size > 0 ? _size - 1 : 0; }

	void resize(st n, T val = T());
	void reserve(st n);

	void swap(CVector& other);

	inline st capacity() const { return _capacity; }
	inline st size() const { return _size; }
	inline bool empty() const { return _size == 0; }
	void clear() { _size = 0; }

	inline bool operator==(const CVector& other) const;
	inline bool operator!=(const CVector& other) const { return !(*this == other); }

	inline bool operator< (const CVector& other) const;
	inline bool operator> (const CVector& other) const { return (other < *this); }
	inline bool operator<=(const CVector& other) const { return !(*this > other); }
	inline bool operator>=(const CVector& other) const { return !(*this < other); }
};
#include "vec.inl"
