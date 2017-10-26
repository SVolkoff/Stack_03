#include <iostream>
#include <stdexcept>
#include <algorithm>
#ifndef STACK_HPP
#define STACK_HPP
template <typename T> class stack
{
public:
	stack() noexcept;
	~stack() noexcept;
	stack(const stack &); /*strong*/
	stack<T> & operator=(stack<T> const & other); /*strong*/
	size_t count() const noexcept;
	void push(T const &); /*strong*/
	void pop(); /*strong*/
	T top() const; /*strong*/
	void print() const; /*strong*/
	bool isempty() const noexcept;

private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&) noexcept;
};


template<typename T>
stack<T>::stack() noexcept
{
	count_ = 0;
	array_size_ = 0;
	array_ = nullptr;
}

template<typename T>
stack<T>::~stack() noexcept
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}
template<typename T>
stack<T>::stack(const stack<T>& other)
{
	try
	{
		size_t tmpsize = other.array_size_;
		size_t tmpcount = other.count_;
		T* tmparray_ = new T[tmpsize];
		std::copy(other.array_, other.array_ + other.array_size_, tmparray_);
		array_size_ = tmpsize;
		count_ = tmpcount;
		array_ = new T[array_size_];
		std::copy(tmparray_, tmparray_ + tmpsize, array_);
	}
	catch (std::bad_alloc)
	{
		 std::cout<< "Allocation failure " << std::endl;
	}
	catch (std::exception &err)
	{
		 std::cerr << err.what() << std::endl;
	}
}

template <typename T>
bool stack<T>::isempty() const noexcept
{
	return (count_ == 0);
}


template <typename T>
void stack<T>::swap(stack<T> & other) noexcept
{
	std::swap(other.array_size_, array_size_);
	std::swap(count_, other.count_);
	std::swap(other.array_, array_);
}

template<typename T>
stack<T>& stack<T>::operator= (stack<T> const & other) 
{
	if (&other != this)
	{
		stack(other).swap(*this);
	}
	return *this;
}

template<typename T>
void stack<T>::print() const
{
	if (isempty()) std::cout << "Stack is empty" << std::endl;
	else
		for (int i = 0; i < count_; i++)
			std::cout << array_[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
size_t stack<T>::count() const noexcept
{
	return count_;
}

template <typename T>
void stack<T>::pop()
{
	if (isempty())
	{
		throw std::logic_error("Stack is empty!");
	}

	count_--;
}
template <typename T>
T stack<T>::top() const
{
	if (isempty())
	{
		throw std::logic_error("Stack is empty!");
	}

	return array_[count_ - 1];
}
template<typename T>
void stack<T>::push(T const & value)
{

	if (array_size_ == count_)
	{
		size_t ar_size;
		if (isempty())
			ar_size = 1;
		else
			ar_size = array_size_ * 2;
		try
		{
			T *ptr = new T[ar_size];
			std::copy(array_, array_ + count_, ptr);
			array_size_ = ar_size;
			delete[] array_;
			array_ = ptr;
		}
		catch (std::bad_alloc)
		{
			std::cout << "Allocation failure " << std::endl;
		}
		catch (std::exception &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	array_[count_] = value;
	count_++;
}

#endif 
