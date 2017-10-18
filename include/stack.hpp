#include <iostream>
#include <stdexcept>
#include <algorithm>
#ifndef STACK_HPP
#define STACK_HPP

template <typename T> class stack
{
public:
	stack();
	~stack() noexcept;
	stack(const stack &); //strong
	stack<T> & operator=( stack<T> const & other) noexcept;
	size_t count() const noexcept;
	void push(T const &); //strong
	void pop(); //strong
	T top() const; //strong
	void print() const noexcept;
	bool isempty() const noexcept;

private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&) noexcept;
};


template<typename T>
stack<T>::stack() 
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
	size_t ar_size = other.array_size_;
	size_t count_tmp = other.count_;
	array_ = new T[count_tmp];
	std::copy(other.array_, other.array_ + other.count_, array_);
	array_size=ar_size;
	count_=count_tmp;
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
stack<T>& stack<T>::operator= (stack<T> const & other) noexcept
{
	if (&other != this)
	{
		stack tmp(other);
		swap(tmp);
	}
	return *this;
}

template<typename T>
void stack<T>::print() const noexcept
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
		throw std::logic_error( "Stack is empty!");
	}

	count_--;
}
template <typename T>
T stack<T>::top() const
{
	if (isempty())
	{
		throw std::logic_error( "Stack is empty!");
	}

	return array_[count_ - 1];
}


template<typename T>
void stack<T>::push(T const & value) //strong
{
	
	if (array_size_ == count_)
	{
		size_t ar_size;
		if (array_size_ == 0)
		ar_size = 1;
		else
		ar_size = array_size_ * 2;
		T *ptr = new T[ar_size];
		std::copy(array_, array_ + count_, ptr);
		array_size_ = ar_size;
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}

#endif 
