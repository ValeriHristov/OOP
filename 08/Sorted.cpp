#include <iostream>

template<typename T>
class Sorted
{
private:
	T* arr;
	int size;

	void clear();
	void copyArr(T* arr, int n);
	void alloc(int n);

	void copySorted(const Sorted& other);
public:
	Sorted();
	Sorted(const Sorted& other);
	Sorted operator=(const Sorted& other);
	~Sorted();

	void Insert( T element);
	T operator[](int index)const;

	void Print() const;
};

template<typename T>
void Sorted<T>::clear()
{
	delete[] this->arr;
	this->size = 0;
}

template<typename T>
void Sorted<T>::copyArr(T * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		this->arr[i] = arr[i];
	}
	this->size = n;
}

template<typename T>
void Sorted<T>::alloc(int n)
{
	this->arr = new T[n];
}

template<typename T>
void Sorted<T>::copySorted(const Sorted & other)
{
	this->clear();
	this->alloc(other.size);
	this->copyArr(other.arr);
}

template<class T>
Sorted<T>::Sorted() : arr(nullptr), size(0)
{
}

template<class T>
Sorted<T>::Sorted(const Sorted & other) : arr(nullptr)
{
	this->copySorted(other);
}

template<typename T>
Sorted<T> Sorted<T>::operator=(const Sorted & other)
{
	this->copySorted(other);
}

template<typename T>
Sorted<T>::~Sorted()
{
	this->clear();
}

template<typename T>
void Sorted<T>::Insert( T element)
{
	if (this->size ==0)
	{
		this->alloc(1);
		this->arr[0] = element;
		this->size++;
		return;
	}
	T * temp = this->arr;
	this->alloc(this->size + 1);

	int i = 0;
	while (temp[i] < element && i < this->size)
	{
		this->arr[i] = temp[i];
		i++;
	}
	this->arr[i] = element;
	while (i < this->size)
	{
		this->arr[i + 1] = temp[i];
		i++;
	}
	this->size++;
	delete[] temp;

}

template<typename T>
T Sorted<T>::operator[](int index)const
{
	if (index < 0 || index >= this->size)
	{
		std::cerr << "Invalid index!\n";
		return T();
	}
	return this->arr[i];
}

template<typename T>
void Sorted<T>::Print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << "\n";
	}
}
