/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:36:23 by afaby             #+#    #+#             */
/*   Updated: 2023/02/15 19:30:15 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include "random_access_iterator_tag.hpp"
#include "iterator_traits.hpp"

namespace ft
{

template<class T>
class random_access_iterator
{

public:

	// Member types
	typedef typename ft::iterator_traits<T>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T>::value_type			value_type;
	typedef typename ft::iterator_traits<T>::pointer			pointer;
	typedef typename ft::iterator_traits<T>::reference			reference;
	typedef ft::random_access_iterator_tag						iterator_category;

	// Constructions
	random_access_iterator(void) :
		_target(NULL)
	{
	}

	random_access_iterator(pointer target) :
		_target(target)
	{
	}

	template<class It>
	random_access_iterator(const random_access_iterator<It>& other) :
		_target(other.base())
	{
	}

	~random_access_iterator(void)
	{
	}

	// Assignement operator
	random_access_iterator&	operator=(const random_access_iterator& other)
	{
		this->_target = other._target;
		return (*this);
	}

	// Arithemtic operators


	random_access_iterator operator+(difference_type n) const	
	{
		random_access_iterator	res(this->_target + n);
		return (res);
	}

	random_access_iterator operator-(difference_type n) const
	{
		random_access_iterator	res(this->_target - n);
		return (res);
	}

	random_access_iterator& operator+=(difference_type n)
	{
		this->_target += n;
		return (*this);
	}

	random_access_iterator& operator-=(difference_type n)
	{
		this->_target -= n;
		return (*this);
	}

	// Member access operators
	reference	operator*(void) const
	{
		return (*this->_target);
	}

	pointer	operator->(void) const
	{
		return (this->_target);
	}

	reference	operator[](size_t pos) const
	{
		return (_target[pos]);
	}

	pointer	base(void) const
	{
		return (_target);
	}

 	// Increment / Decrement operators
	random_access_iterator&	operator++(void)
	{
		++_target;
		return (*this);
	}

	random_access_iterator	operator++(int)
	{
		random_access_iterator temp;

		temp._target = _target++;
		return (temp);
	}

	random_access_iterator&	operator--(void)
	{
		--_target;
		return (*this);
	}

	random_access_iterator	operator--(int)
	{
		random_access_iterator temp;

		temp._target = _target--;
		return (temp);
	}

	// Comparisons operators
	template<class It>
	bool	operator==(const It& other) const
	{
		return (_target == other.base());
	}

	template<class It>
	bool	operator!=(const It& other) const
	{
		return (_target != other.base());
	}

	template<class It>
	bool	operator<(const It& other) const
	{
		return (_target < other.base());
	}
	
	template<class It>
	bool	operator>(const It& other) const
	{
		return (_target > other.base());
	}

	template<class It>
	bool	operator<=(const It& other) const
	{
		return (_target <= other.base());
	}
	
	template<class It>
	bool	operator>=(const It& other) const
	{
		return (_target >= other.base());
	}




private:
	pointer	_target;

};


// Not friend comparisons operators

/* template<class T> */
/* bool	operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) */
/* { */
/* 	return (!(lhs == rhs)); */
/* } */

/* template<class T> */
/* bool	operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) */
/* { */
/* 	return (rhs > lhs); */
/* } */

/* template<class T> */
/* bool	operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) */
/* { */
/* 	return (!(rhs < lhs)); */
/* } */

/* template<class T> */
/* bool	operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) */
/* { */
/* 	return (!(lhs < rhs)); */
/* } */

template<class T>
random_access_iterator<T> operator+(std::ptrdiff_t n, const random_access_iterator<T>& it)
{
	random_access_iterator<T>	res(it.base() + n);
	return (res);
}


template<class T>
random_access_iterator<T> operator-(std::ptrdiff_t n, const random_access_iterator<T>& it)
{
	random_access_iterator<T>	res(it.base() - n);
	return (res);
}

template <class It, class It2>
std::ptrdiff_t	operator-(const random_access_iterator<It>& lhs, const random_access_iterator<It2>& rhs)
{
	return (lhs.base() - rhs.base());
}

}
