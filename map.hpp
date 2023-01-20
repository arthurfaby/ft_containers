/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:11:14 by afaby             #+#    #+#             */
/*   Updated: 2023/01/20 19:32:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template < class Key, class T > 
/*
template <
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T>>
>
*/
class map
{

// Member types											CPPREFERENCE
	// key_type					--> Key
	// mapped_type				--> t
	// value_type				--> ft::pair<const Key, T>
	// size_type				--> unsigned int	(== size_t)
	// difference_type			--> int	(== ptrdiff_t)
	// key_compare				--> Compare
	// allocator_type			--> Allocator
	// reference				--> value_type&
	// const_reference			--> const value_type&
	// pointer					--> Allocator::pointer
	// const_pointer			--> Allocator::const_pointer
	// iterator					--> LegacyBidirectionalIterator to value_type
	// const_iterator			--> LegacyBidirectionalIterator to const value_type
	// reverse_iterator			--> ft::reverse_iterator<iterator>
	// const_reverse_iterator	--> ft::reverse_oter<const_iterator>

// Member types											CPLUSPLUS
	// key_type					--> Key
	// mapped_type				--> T
	// value_type				--> ft::pair<const key_type, mapped_type>
	// key_compare				--> Compare																					// (defaults to: std::less<key_type>)
	// value_compare			--> Nested function class to compare elements												// (see std::map::value_comp doc)
	// allocator_type			--> Alloc																					// (default to std::allocator<value_type>)
	// reference				--> allocator_type::reference																// (for the default allocator: value_type&)
	// const_reference			--> allocator_type::const_reference															// (for the default allocator: const value_type&)
	// pointer					--> allocator_type::pointer																	// (for the default allocator: value_type*)
	// const_pointer			--> allocator_type::const_pointer															// (for the default allocator: const value_type*)
	// iterator					--> a bidirectional iterator to value_type													// (convertible to const_iterator)
	// const_iterator			--> a bidirectional to const value_type
	// reverse_iterator			--> ft::reverse_iterator<iterator>
	// const_reverse_iterator	--> ft::reverse_iterator<const_iterator>
	// difference				--> a signed intergral type, identical to: ft::iterator_traits<iterator>::difference_type	// (== ptrdiff_t)
	// size_type				--> an unsigned integral type that can represent any non-negative value of difference_type	// (== size_t)


public:

protected:

private:

}

}
