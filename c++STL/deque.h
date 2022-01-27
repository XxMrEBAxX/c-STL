#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Deque_Arr;

template <typename T>
class Deque
{
	Deque_Arr<T*> blockAddressPtr;

	size_t blockSize;
public:
	Deque(size_t bSize = 5, size_t bcount = 3) : blockSize(bSize)
	{
		blockAddressPtr;

		blockSize = bSize;

		size_t halfBCount = (bcount / 2);
		size_t FrontHarfBCount = halfBCount;
		if (halfBCount % 2 != 0) FrontHarfBCount += 1;
		// 2���� Front Block�� 1���� Back Block ����
		for (size_t i = 0; i < FrontHarfBCount; i++)
		{
			T* Farr = new T[blockSize];
			blockAddressPtr.push_front(Farr);
		}
		for (size_t i = 0; i < halfBCount; i++)
		{
			T* Barr = new T[blockSize];
			blockAddressPtr.push_back(Barr);
		}

		blockAddressPtr.display();
	}
	~Deque()
	{
		while (!blockAddressPtr.empty())
		{
			delete[] blockAddressPtr.pop_back();
		}
	}
};

// ���� https://velog.io/@daeho-park/C-%EB%B0%B0%EC%97%B4%EB%A1%9C-%EA%B5%AC%ED%98%84%ED%95%9C-%EB%8D%B1Deque

template <typename T>
class Deque_Arr
{
	T* deque;
	size_t maxSize;
	size_t dataSize;
	size_t frontIndex;
	size_t rearIndex;

	//std::vector<T>::iterator���� iterator ��ü�� std::vector<T>�� ����������� �˱� ������ ������ ��.
	//���� typename�� ����Ͽ� std::vector<T>::iterator ��ü�� Ÿ���̶�� ���� �����.
	//typename std::vector<T>::iterator frontIter;
	//typename std::vector<T>::iterator backIter;
public:
	Deque_Arr(size_t size = 10) : maxSize(size), dataSize(0), frontIndex(0), rearIndex(1)
	{
		deque = new T[maxSize];
		
		for (size_t i = 0; i < maxSize; i++)
		{
			deque[i] = T();
		}

		//frontIter = deque.begin();
		//backIter = deque.begin() + 1; //������ ����
	}
	~Deque_Arr()
	{
		delete[] deque;
	}

	bool empty() const
	{
		return dataSize == 0;
	}

	bool full() const
	{
		return dataSize == maxSize;
	}

	size_t size() const
	{
		return dataSize;
	}

	T& front() const
	{
		if (empty())
		{
			std::cout << "Deque is empty" << std::endl;
		}
		int tempIndex = (frontIndex + 1) % maxSize;
		return deque[tempIndex];
	}
	
	T& back() const
	{
		if (empty())
		{
			std::cout << "Deque is empty" << std::endl;
		}
		int tempIndex = ((rearIndex - 1) + maxSize) % maxSize;
		return deque[tempIndex];
	}
	
	void push_front(const T data)
	{
		if (full())
		{
			std::cout << "Deque is full" << std::endl;
			// vector resize �� ������ ����
		}
		deque[frontIndex] = data;
		frontIndex = ((frontIndex - 1) + maxSize) % maxSize;
		dataSize++;
	}

	void push_back(const T data)
	{
		if (full())
		{
			std::cout << "Deque is full" << std::endl;
			// vector resize �� ������ ����
		}
		deque[rearIndex] = data;
		rearIndex = (rearIndex + 1) % maxSize;
		dataSize++;
	}

	T& pop_front()
	{
		T& frontData = front();// if empty, error occurred
		frontIndex = (frontIndex + 1) % maxSize;
		dataSize--;
		return frontData;
	}
	T& pop_back()
	{
		T& backData = back();// if empty, error occurred
		rearIndex = ((rearIndex - 1) + maxSize) % maxSize;
		dataSize--;
		return backData;
	}
	void display() const;
};

template<typename T> void Deque_Arr<T>::display() const
{
	std::cout << "size : " << size() << std::endl;
	std::cout << "deque List ====" << std::endl;
	if (!empty())
	{
		for (size_t i = 0; i < maxSize; i++)
		{
			std::cout << typeid(deque[i]).name() << std::endl;
		}
	}
}