#include <iostream>
#include <stdexcept>
#include <algorithm>
#ifndef STACK_HPP
#define STACK_HPP

template <typename T> class stack
{
public:
	stack();
	~stack();
	stack(const stack&);
	stack<T>& operator=(const stack<T>& other);
	size_t count() const;
	void push(T const &);
	T pop();
	void print() const;
	T printlast() const;
	
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&);
};


template<typename T>
stack<T>::stack() 
{
	count_ = 0;
	array_size_ = 0;
	array_ = nullptr;
}

template<typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}
template<typename T>
stack<T>::stack(const stack<T>& other)
{
	array_size_ = other.array_size_;
	count_ = other.count_;
	array_=new T[count_];
	std::copy(other.array_, other.array_ + other.count_, array_);
}

template <typename T>
void stack<T>::swap(stack<T>& other)
{
	std::swap(other.array_size_, array_size_);
	std::swap(count_, other.count_);
	std::swap(other.array_, array_);
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
	if (this != &other) 
	{
		if (array_size_ != 0) 
		{
			delete[] array_;
		}
		array_size_ = other.array_size_;
		count_ = other.count_;
		array_=new T[count_];
		std::copy(other.array_, other.array_ + other.count_, array_);
	}
	return *this;
}
template<typename T>
void stack<T>::print() const
{
	if (count_ == 0) std::cout << "Stack is empty" << std::endl;
	else
	for(int i=0; i < count_ ; i++)
	std::cout<< array_[i] << ' ';
	std::cout << std::endl;
}
template<typename T>
T stack<T>::printlast()const
{
	if (count_ == 0)
		throw std::logic_error("Stack is empty");
	else return array_[count_ - 1];
}

template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template<typename T>
T stack<T>::pop() 
{
	if (array_size_ != 0) 
	{
		count_--;
		return array_[count_];
	}
	else 
		throw std::logic_error("Stack is empty");
}

template<typename T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T *ptr=new T[array_size_]();
		std::copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}
#endif 
