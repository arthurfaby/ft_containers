/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:49:27 by afaby             #+#    #+#             */
/*   Updated: 2023/02/04 18:32:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class It>
class reverse_iterator
{


public:

	// Member types
	typedef It									iterator_type;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::value_type			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::iterator_category	iterator_category;


	// Constructions
	reverse_iterator(void) :
		_it(iterator_type())
	{
	}

	reverse_iterator(value_type* target) :
		_it(iterator_type(target))
	{
	}

	template<class It2>
	reverse_iterator(const It2& other) :
		_it(other.base())
	{
	}

	~reverse_iterator(void)
	{
	}

	
	// Assignment operator
	reverse_iterator&	operator=(const reverse_iterator& other)
	{
		this->_it = other._it;
		return (*this);
	}


	// Arithmetic operators
	difference_type	operator-(const reverse_iterator& other) const
	{
		return (other._it - this->_it);
	}

	reverse_iterator	operator+(difference_type n) const
	{
		reverse_iterator	res(this->_it.base() - n);
		return (res);
	}

	reverse_iterator	operator-(difference_type n) const
	{
		reverse_iterator	res(this->_it.base() + n);
		return (res);
	}

	reverse_iterator&	operator+=(difference_type n)
	{
		this->_it -= n;
		return (*this);
	}

	reverse_iterator&	operator-=(difference_type n)
	{
		this->_it += n;
		return (*this);
	}


	// Member access operators
	reference	operator*(void) const
	{
		return (*this->_it);
	}

	pointer	operator->(void) const
	{
		return (_it.base()); // TO VERIFY
	}

	reference	operator[](size_t pos) const
	{
		return (_it[-pos]);
	}

	
	// Increment / Decrement operators
	reverse_iterator&	operator++(void)
	{
		_it--;
		return (*this);
	}

	reverse_iterator	operator++(int)
	{
		reverse_iterator	temp;

		temp._it = _it--;
		return (temp);
	}

	reverse_iterator&	operator--(void)
	{
		_it++;
		return (*this);
	}

	reverse_iterator	operator--(int)
	{
		reverse_iterator	temp;

		temp._it = _it++;
		return (temp);
	}

	template<class It2>
	bool	operator==(const It2& other) const
	{
		return (_it.base() == other.base());
	}

	template<class It2>
	bool	operator!=(const It2& other) const
	{
		return (_it.base() != other.base());
	}

	template<class It2>
	bool	operator<(const It2& other) const
	{
		return (_it.base() > other.base());
	}

	template<class It2>
	bool	operator<=(const It2& other) const
	{
		return (_it.base() >= other.base());
	}

	template<class It2>
	bool	operator>(const It2& other) const
	{
		return (_it.base() < other.base());
	}

	template<class It2>
	bool	operator>=(const It2& other) const
	{
		return (_it.base() <= other.base());
	}


	pointer	base(void) const
	{
		return (_it.base());
	}


private:
	It	_it;

};

template<class T>
reverse_iterator<T>	operator+(typename ft::reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it)
{
	reverse_iterator<T>	res(it + n);
	return (res);
}

template<class T>
reverse_iterator<T>	operator-(typename ft::reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it)
{
	reverse_iterator<T>	res(it - n);
	return (res);
}


}
