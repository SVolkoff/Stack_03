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
	stack(const stack &)basic;
	stack<T> & operator=( stack<T> const & other) noexcept;
	
	size_t count() const noexcept;
	void push(T const &) basic;
	void pop() strong; 
	T top() const strong;
	void print() const noexcept;
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
stack<T>::stack(const stack<T>& other) basic 
{
	array_size_ = other.array_size_;
	count_ = other.count_;
	array_ = new T[count_];
	std::copy(other.array_, other.array_ + other.count_, array_);
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
void stack<T>::pop() strong
{
	if (isempty())
	{
		throw std::logic_error( "Stack is empty!");
	}

	count_--;
}
template <typename T>
T stack<T>::top() const strong 
{
	if (isempty())
	{
		throw std::logic_error( "Stack is empty!");
	}

	return array_[count_ - 1];
}


template<typename T>
void stack<T>::push(T const & value) basic 
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T *ptr = new T[array_size_]();
		std::copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}

#endif 
