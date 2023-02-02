/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:11:14 by afaby             #+#    #+#             */
/*   Updated: 2023/01/21 11:55:37 by afaby            ###   ########.fr       */
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
	// mapped_type				--> T
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


// Member classes
	// value_compare

public:
	// Member functions

		// Constructors :
			// map( void );
			/*
			 explicit map( const key_compare& comp,
							const allocator_type& alloc = allocator_type() );
			*/
			/*
			template < class InputIt >
			map( InputIt first,
					InputIt last,
					const key_compare& = key_compare(),
					const allocator_type& alloc = allocator_type() );
			*/
			// map( const map& other );

		// Destructor :
			// ~map( void );

		// Copy assignement operator
			// map&					operator=( const map& other );

		// Get allocator
			// allocator_type		get_alocator( void ) const;

		// Element access
			// mapped_type&			at( const key_type& key );
			// const mapped_type&	at( const key_type& key ) const;

			// mapped_type&			operator[]( const mapped_type& key );

		// Iterators :
			// iterator					begin( void );
			// const_iterator			begin( void ) const;

			// iterator					end( void );
			// const_iterator			end( void ) const;

			// reverse_iterator			rbegin( void );
			// const_reverse_iterator	rbegin( void ) const;

			// reverse_iterator			rend( void );
			// const_reverse_iterator	rend( void ) const;

		// Capacity :
			// bool			empty( void ) const;

			// size_type	size( void ) const;

			// size_type	max_size( void ) const;

		// Modifiers :
			// void						clear( void );

			// ft::pair<iterator, bool>	insert( const value_type& value );
			// iterator					insert( iterator pos, const value_type& value );
			/*
			template <class InputIt>
			void						insert( InputIt first, InputIt last );
			*/

			// void						erase( iterator pos );
			// void						erase( iterator first, iterator last );
			// size_type				erase( const key_type& key );

			// void						swap( map& other );

		// Lookup
			// size_type								count( const key_type& key ) const;

			// iterator									find( const key_type& key );
			// const_iterator							find( const key_type& key ) const;

			// ft::pair<iterator, iterator>				equal_range( const key_type& key );
			// ft::pair<const_iterator, const_iterator>	equal_range( const key_type& key ) const;

			// iterator									lower_bound(const key_type& key );
			// const_iterator							lower_bound(const key_type& key ) const;

			// iterator									upper_bound( const key_type& key );
			// const_iterator							upper_bound( const key_type& key ) const;

		// Observers
			// key_compare				key_comp( void ) const;

			// ft::map::value_compare	value_comp( void ) const;

protected:

private:

};

// Non member functions
	// Overload operators
		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator==( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator<( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator<=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator>( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

		/*
		template < class Key, class T, class Compare, class Alloc >
		boold	operator>=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs );
		*/

	// Swap
		/*
		template < class Key, class T, class Compare, class Alloc >
		void	swap( ft::map<Key, T, Compare, Alloc>& lhs,
						ft::map<Key, T, Compare, Alloc>& rhs );
		*/



};
