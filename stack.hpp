/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:31:09 by afaby             #+#    #+#             */
/*   Updated: 2023/01/20 14:40:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template < class T > // template < class T, class Container = ft::vector<T> >
class stack
{

// Members types															| cppreference
	// container_type --> Container											| cppreference
	// value_type --> Container::value_type									| cppreference
	// size_type --> Container::size_type									| cppreference
	// reference --> Container::reference									| cppreference
	// const_reference --> Container::const_reference						| cppreference

// Members types															| cplusplus
	// value_type --> T // (Type of the elements)							| cplusplus
	// container_type --> Container // (Type of the underlying container)	| cplusplus
	// size_type --> unsigned int // (== size_t)							| cplusplus
	

public:
	// Constructors :
		// explicit stack( const Container& cont = Container() );			| both
		// stack( const stack& other );										| only cppreference

	// Destructor :
		// ~stack( void );													| both

	// Members functions :
		// Element access
		// top
			// reference		top( void );								| cppreference
			// const_reference	top( void ) const;							| cppreference
			
			// value_type&			top( void );							| cplusplus
			// const value_type&	top( void ) const;						| cplusplus

		// Capacity
		// empty
			// bool				empty( void ) const;						| both
		// size
			// size_type		size( void ) const;							| both

		// Modifiers
		// push
			// void				push ( const value_type& value );			| both
		// pop
			// void				pop( void );								| both

	// Operator overloads :
		// stack& operator=( const stack& other );
		// bool operator==( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);
		// bool operator!=( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);
		// bool operator<( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);
		// bool operator<=( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);
		// bool operator>( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);
		// bool operator>=( const ft::stack<T, container>& lhs, const ft::stack<T, Container>& rhs);

protected:
	// Member objects
		// Container	c;

private:

};

}
