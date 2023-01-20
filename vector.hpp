/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:29:49 by afaby             #+#    #+#             */
/*   Updated: 2023/01/20 19:08:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template < class T > // template < class T, class Allocator = std::allocator<T> >
class vector
{

// Member types															 CPLUSPLUS
	// value_type				--> T
	// allocator_type			--> Alloc 																			// (default to allocator<`value_type`>)
	// reference				--> allocator_type::reference														// (for the default allocator: `value_type&`)
	// const_reference			--> allocator_type::const_reference													// (for the default allocator: `const value_type&`)
	// pointer					--> allocator_type::pointer															// (for the default allocator `value_type*`)
	// const_pointer			--> allocator_type::const_pointer													// (for the default allocator `const value_type*`)
	// iterator					--> random access iterator to `value_type`											// (convertible to `const_iterator`)
	// const_iterator			--> random access iterator to `const value_type`									// (convertible to `const_iterator`)
	// reverse_iterator			--> `reverse_iterator<iterator>`
	// const_reverse_iterator	--> `reverse_iterator<const_iterator>`
	// difference_type			--> `int`, identical to: `iterator_traits<iterator>::difference_type`				// (== ptrdiff_t)
	// size_type				--> `unsigned int ` that can represent any non-negative value of `difference_type`	// (== size_t)


// Member types															CPPREFERENCE
	// value_type				--> T
	// allocator_type 			--> Allocator
	// size_type				--> unsigned int																	// (== std::size_t)
	// difference_type			--> int																				// (== std::ptrdiff_t)
	// reference				--> value_type&
	// const_reference			--> const value_type&
	// pointer					--> Allocator::pointer
	// const_pointer			--> Allocator::const_pointer
	// iterator					--> LegacyRandomAccessIterator and LegacyContiguousIterator to value_type
	// const_iterator			--> LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type
	// reverse_iterator			--> ft::reverse_iterator<iterator>
	// const_reverse_iterator	--> ft::reverse_iterator<const_iterator>

public:
	
	// Member functions :
		// Constructors (CPPREFERENCE) :
			// vector( void );													// (1)
			// explicit vector( const allocator_type& alloc );					// (2)
			/* 
			explicit vector( size_type count,
							const value_type& value = value_type(),
							const allocator_type& alloc = allocator_type() );
			*/																	// (3)
			/* 
			template < class InputIt >
			vector( InputIt first,
					InputIt last,
					const allocator_type& alloc = allocator_type() );
			*/ 																	// (5)
			// vector( const vector& other );									// (6)


		// Constructors (CPLUSPLUS)
			// explicit vector( const allocator_type& = allocator_type() );
			/*
			explicit vector( size_type n,
								const value_tyoe& val = value_type(),
								const allocator_type& alloc = allocator_type() );
			*/
			/*
			template < class InputIt >
			vector( InputIt first,
					InputIt last,
					const allocator_type& = allocator_type() );
			*/
			// vector( const vector& c );
	

		// Destructor :
			// ~vector( void );											| both


		// Copy assignement operator
			// vector&	operator=( const vector& other );				| cppreference


		// Assign
			// void	assign( size_type count, const value_type& value );	| both
			/*
			template < class InputIt >
			void	assign( InputIt first, InputIt last );				| both
			*/


		// Get allocator
			// allocator_type			get_allocator( void ) const;	| both


		// Element access
			// reference				at( size_type pos );				| both
			// const_reference			at( size_type pos ) const;			| both

			// reference				operator[]( size_type pos );		| both
			// const_reference			operator[]( size_type pos ) const;	| both

			// reference				front( void );						| both
			// const_reference			front( void ) const;				| both

			// reference				back( void );						| both
			// const_reference			back( void ) const;					| both

			// value_type				data( void );						| both
			// const value_type*		data( void ) const;					| both


		// Iterators
			// iterator					begin( void );			| both
			// const_iterator			begin( void ) const;	| both

			// iterator					end( void );			| both
			// const_iterator			end( void ) const;		| both

			// reverse_iterator			rbegin( void );			| both
			// const_reverse_iterator	rbegin( void ) const;	| both

			// reverse_iterator			rend( void );			| both
			// const_reverse_iterator	rend( void ) const;		| both


		// Capacity
			// bool						empty( void ) const;			| both

			// size_type				size( void ) const;				| both

			// size_type				max_size( void ) const;			| both

			// void						reserve( size_type new_cap );	| both

			// size_type				capacity( void ) const;			| both


		// Modifiers
			// void						clear( void );								| both

			/*
			iterator					insert( const_iterator pos,
												const value_type& value );			| cppreference
			*/
			/*
			iterator					insert( iterator pos,
												const value_type& value );			| cplusplus
			*/
			/*
			 iterator					insert( const_iterator pos,
												size_type count,
												const value_type& value );			| cppreference
			*/
			/*
			 iterator					insert( iterator pos,
												size_type count,
												const value_type& value );			| cplusplus
			*/
			/*
			template < class InputIt >
			iterator					insert( const_iterator pos,
												InputIt first,
												InputIt last );						| cppreference
			*/
			/*
			template < class InputIt >
			iterator					insert( iterator pos,
												InputIt first,
												InputIt last );						| cplusplus
			*/

			// iterator					erase( iterator pos );						| both
			// iterator					erase( iterator first, iterator last );		| both

			// void						push_back( const value_type& value );		| both

			// void						pop_back( void );							| both

			/*
			void						resize( size_type count,
												value_type value = value_type() );	| both
			*/			

			// void						swap( vector& other );						| both


	// Non-member functions :
		// Operators overload :
			// bool		operator==( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );
			// bool		operator!=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );
			// bool		operator<( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );
			// bool		operator<=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );
			// bool		operator>( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );
			// bool		operator>=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

		// Other
			// void	swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs );

protected:

private:


};

}
