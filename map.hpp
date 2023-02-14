/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:11:14 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 09:42:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./utils/pair.hpp"
#include "./utils/RBTree.hpp"

#include <cstddef>

namespace ft
{

template <
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> >
>

class map
{
// Member classes
	// value_compare


public:

	typedef Key											key_type;
	typedef T											mapped_type;
	typedef ft::pair<const Key, T>						value_type;
	typedef size_t										size_type;
	typedef	std::ptrdiff_t								difference_type;
	typedef Compare										key_compare;
	typedef Allocator									allocator_type;
	typedef value_type&									reference;
	typedef const value_type&							const_reference;
	typedef typename Allocator::pointer					pointer;
	typedef typename Allocator::const_pointer			const_pointer;
	typedef ft::RBTree_iterator<const Key, T>			iterator;
	typedef ft::RBTree_iterator<const Key, const T>		const_iterator;
	/* typedef typename ft::RBTree<const Key, T, Compare, Allocator>::iterator				iterator; */
	/* typedef typename ft::RBTree<const Key, const T, Compare, Allocator>::const_iterator	const_iterator; */

	// ITERATORS
	// Member functions

		// Constructors :
			map( void )
			{
			}
			
			 explicit map( const key_compare& comp,
							const allocator_type& alloc = allocator_type() ) :
				_compare_function(comp),
				_alloc(alloc)
			{

			}

			template < class InputIt >
			map( InputIt first,
					InputIt last,
					const key_compare& key_cmp = key_compare(),
					const allocator_type& alloc = allocator_type() ) :
				_compare_function(key_cmp),
				_alloc(alloc)
			{
				while (first != last)
				{
					this->insert(ft::make_pair(first->first, first->second));
					first++;
				}
			}

			// map( const map& other );

		// Destructor :
			~map( void )
			{
			}

		// Copy assignement operator
			// map&					operator=( const map& other );

		// Get allocator
			allocator_type		get_alocator( void ) const
			{
				return (_alloc);
			}

		// Element access
			mapped_type&			at( const key_type& key )
			{
				node_type	*node = _tree.find(key);
				if (!node)
					throw std::out_of_range("map::at");
				return (node->getValue());
			}
			const mapped_type&	at( const key_type& key ) const
			{
				node_type	*node = _tree.find(key);
				if (!node)
					throw std::out_of_range("map::at");
				return (node->getValue());
			}

			mapped_type&			operator[]( const mapped_type& key )
			{
				node_type	*node = _tree.find(key);
				if (!node)
					throw std::out_of_range("map::operator[]");
				return (node->getValue());
			}

		// Iterators :
			iterator				begin( void )
			{
				return (_tree.begin());
			}

			const_iterator			begin( void ) const
			{
				return (_tree.begin());
			}

			iterator					end( void )
			{
				return (_tree.end());
			}

			const_iterator			end( void ) const
			{
				return (_tree.end());
			}

			// reverse_iterator			rbegin( void );
			// const_reverse_iterator	rbegin( void ) const;

			// reverse_iterator			rend( void );
			// const_reverse_iterator	rend( void ) const;

		// Capacity :
			bool		empty( void ) const
			{
				return (_tree.empty());
			}

			size_type	size( void ) const
			{
				return (_tree.size());
			}

			size_type	max_size( void ) const
			{
				return (_alloc.max_size());
			}

		// Modifiers :
			void						clear( void )
			{
				_tree.clear();
			}

			ft::pair<iterator, bool>	insert( const value_type& value )
			{
				_tree.insert(value);
				return (ft::make_pair<iterator, bool>(iterator(), true));
			}

			// iterator					insert( iterator pos, const value_type& value );
			/*
			template <class InputIt>
			void						insert( InputIt first, InputIt last );
			*/

			void						erase( iterator pos )
			{
				_tree.erase(pos);
			}

			void						erase( iterator first, iterator last )
			{
				while (first != last)
				{
					_tree.erase(first);
					first++;
				}
			}

			//size_type				erase( const key_type& key );

			void						swap( map& other )
			{
				std::swap(_compare_function, other._compare_function);
				std::swap(_alloc, other._alloc);
				std::swap(_tree, other._tree);
			}

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

	typedef	typename ft::RBTree<const key_type, mapped_type, key_compare, allocator_type>::node_type	node_type;


	key_compare		_compare_function;
	allocator_type	_alloc;
	

	RBTree<const key_type, mapped_type, key_compare, allocator_type> _tree;

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
