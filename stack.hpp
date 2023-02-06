/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:31:09 by afaby             #+#    #+#             */
/*   Updated: 2023/02/06 13:42:42 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{

template < class T, class Container = ft::vector< T > >
class stack
{

public:
	// Member types
	typedef	Container							container_type;
	typedef	typename Container::value_type		value_type;
	typedef	typename Container::size_type		size_type;
	typedef	typename Container::reference		reference;
	typedef	typename Container::const_reference	const_reference;

	// Constructors :
	explicit stack( const container_type& cont = container_type() ) : c(cont)
	{
	}

	stack( const stack& other) : c(other.c)
	{
	}

	// Copy assignement operator
	stack& operator=( const stack& other )
	{
		c = other.c;
		return *this;
	}

	// Destructor :
	~stack( void )
	{
	}

	// Members functions :
		// Element access
			// top
			reference		top( void )
			{
				return (c.back());
			}

			const_reference	top( void ) const
			{
				return (c.back());
			}

		// Capacity
			// empty
			bool				empty( void ) const
			{
				return (c.begin() == c.end());
			}

			// size
			size_type		size( void ) const
			{
				return (c.size());
			}

		// Modifiers
			// push
			void				push ( const value_type& value )
			{
				c.push_back(value);
			}

			// pop
			void				pop( void )
			{
				c.pop_back();
			}

	// Operator overloads :
		friend bool	operator==( const stack& lhs, const stack& rhs)
		{
			return (lhs.c == rhs.c);
		}

		friend bool	operator<( const stack& lhs, const stack& rhs)
		{
			return (lhs.c < rhs.c);
		}

protected:
	container_type	c;

private:

};

template < class T, class Container >
bool	operator!=( const ft::stack< T, Container >& lhs, const ft::stack< T, Container >& rhs )
{
	return (!(lhs == rhs));
}
template < class T, class Container >
bool	operator>( const ft::stack< T, Container >& lhs, const ft::stack< T, Container >& rhs )
{
	return (rhs < lhs);
}
template < class T, class Container >
bool	operator>=( const ft::stack< T, Container >& lhs, const ft::stack< T, Container >& rhs )
{
	return (!(lhs < rhs));
}
template < class T, class Container >
bool	operator<=( const ft::stack< T, Container >& lhs, const ft::stack< T, Container >& rhs )
{
	return (!(rhs < lhs));
}

}


#endif
