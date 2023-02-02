/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:51 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:46:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class T1, class T2>
struct pair
{
public:

	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	pair(void) :
		first(first_type()),
		second(second_type())
	{
	}

	pair(const T1& x, const T2& y) :
		first(x),
		second(y)
	{
	}

	template<class U1, class U2>
	pair(const pair<U1, U2>& p) :
		first(p.first),
		second(p.second)
	{
	}

	pair&	operator=(const pair& other)
	{
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}

};

template<class T1, class T2>
bool	operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return ( (lhs.first == rhs.first) && (lhs.second == rhs.second) );
}

template<class T1, class T2>
bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return ( !(lhs == rhs) );
}

template<class T1, class T2>
bool	operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	else if (rhs.first < lhs.first)
		return (false);
	else if (lhs.second < rhs.second)
		return (true);
	return (false);
}

template<class T1, class T2>
bool	operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return ( !(rhs < lhs) );
}

template<class T1, class T2>
bool	operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (rhs < lhs);
}

template<class T1, class T2>
bool	operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return ( !(lhs < rhs) );
}

}
