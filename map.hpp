/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:11:14 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 11:27:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./utils/pair.hpp"
#include "./utils/RBTree.hpp"
#include "./utils/enable_if.hpp"
#include "./utils/is_integral.hpp"
#include "./utils/lexicographical_compare.hpp"
#include "./utils/reverse_RBTree_iterator.hpp"
#include "./utils/equal.hpp"

#include <algorithm>
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
	typedef ft::RBTree_iterator<value_type>				iterator;
	typedef ft::RBTree_iterator<const value_type>		const_iterator;
	typedef ft::reverse_RBTree_iterator<iterator>		reverse_iterator;
	typedef ft::reverse_RBTree_iterator<const_iterator>	const_reverse_iterator;


		/* Member classes */
		class value_compare
		{
		public:
			
			/* Member types */
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			/* Constructor */
			value_compare(Compare c) :
				comp(c)
			{
			}

			bool	operator()( const value_type& lhs, const value_type& rhs ) const
			{
				return (comp(lhs.first, rhs.first));
			}

		protected:
			Compare comp;
		};




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

			map( const map& other ) :
				_compare_function(other._compare_function),
				_alloc(other._alloc),
				_tree(other._tree)
			{
			}

		// Destructor :
			~map( void )
			{
			}

		// Copy assignement operator
			map&					operator=( const map& other )
			{
				_compare_function = other._compare_function;
				_alloc = other._alloc;
				_tree = other._tree;
				return (*this);
			}

		// Get allocator
			allocator_type		get_alocator( void ) const
			{
				return (_alloc);
			}

		// Element access
			mapped_type&			at( const key_type& key )
			{
				node_type	*node = _tree.find(key);
				if (node == _tree.getEnd())
					throw std::out_of_range("map::at");
				return (node->getReelPair().second);
			}
			const mapped_type&	at( const key_type& key ) const
			{
				node_type	*node = _tree.find(key);
				if (node == _tree.getEnd())
					throw std::out_of_range("map::at");
				return (node->getReelPair().second);
			}

			mapped_type&			operator[]( const key_type& key )
			{
				node_type	*node = _tree.find(key);
				if (node == _tree.getEnd())
				{
					_tree.insert(ft::make_pair<const key_type, mapped_type>(key, mapped_type()));
					node = _tree.find(key);
				}
				return (node->getReelPair().second);
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

			reverse_iterator			rbegin( void )
			{
				reverse_iterator	rit(this->end());

				return (rit);
			}

			const_reverse_iterator	rbegin( void ) const
			{
				const_reverse_iterator	crit(this->end());

				return (crit);
			}

			reverse_iterator			rend( void )
			{
				reverse_iterator	rite(this->begin());

				return (rite);
			}

			const_reverse_iterator	rend( void ) const
			{
				const_reverse_iterator	crite(this->begin());

				return (crite);
			}

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

			void	show(void)
			{
				_tree.show();
			}

		// Modifiers :
			void						clear( void )
			{
				_tree.clear();
			}

			ft::pair<iterator, bool>	insert( const value_type& value )
			{
				bool	res(true);
				if (this->find(value.first) != this->end())
					res = false;
				else
					_tree.insert(value);
				return (ft::make_pair<iterator, bool>(iterator(_tree.find(value.first), _tree.getEnd()), res));
			}

			iterator					insert( iterator pos, const value_type& value )
			{
				iterator	save = this->find(value.first);
				if (save != end())
					return (save);
				node_type	*node;
				if (pos == end())
					node = _tree.getBottomRight();
				else
					node = _tree.find(pos->first);
				if (pos == begin())
				{
					if (pos != end() && !value_comp()(*pos, value))
						_tree.insert(value, &node);
					else
						_tree.insert(value);
				}
				else if (pos == end())
				{
					if (pos != begin() && value_comp()(*(--pos), value))
						_tree.insert(value, &node);
					else
						_tree.insert(value);
				}
				else
					_tree.insert(value);
				return (this->find(value.first));
			}
			
			template <class InputIt>
			void						insert( InputIt first, InputIt last)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}
			

			void					erase( iterator pos )
			{
				_tree.erase(pos);
			}

			void					erase( iterator first, iterator last )
			{
				iterator	save = first;
				while (first != last)
				{
					++save;
					this->erase(first);
					first = save;
				}
			}

			size_type				erase( const key_type& key )
			{
				node_type	*node = _tree.find(key);
				if (node != _tree.getEnd())
				{
					_tree.erase(iterator(node, _tree.getEnd()));
					return (1);
				}
				return (0);
			}

			void						swap( map& other )
			{
				std::swap(_compare_function, other._compare_function);
				std::swap(_alloc, other._alloc);
				_tree.swap(other._tree);
			}

		// Lookup
			size_type								count( const key_type& key ) const
			{
				return (_tree.find(key) != _tree.getEnd());
			}

			iterator									find( const key_type& key )
			{
				node_type	*node = _tree.find(key);
				if (node == _tree.getEnd())
					return (this->end());
				return (iterator(node, _tree.getEnd()));
			}
			
			const_iterator							find( const key_type& key ) const
			{
				node_type	*node = _tree.find(key);
				if (node == _tree.getEnd())
					return (this->end());
				return (const_iterator(node, _tree.getEnd()));
			}

			ft::pair<iterator, iterator>				equal_range( const key_type& key )
			{
				return (ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}
			ft::pair<const_iterator, const_iterator>	equal_range( const key_type& key ) const
			{
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
			}

			iterator									lower_bound( const key_type& key )
			{
				iterator	it = this->find(key);
				if (it != end())
					return (it);
				it = begin();
				for (; it != end(); ++it)
					if (_compare_function(it->first, key) == false)
						return (it); 
				return (it);
			}

			const_iterator							lower_bound( const key_type& key ) const
			{
				const_iterator	it = this->find(key);
				if (it != end())
					return (it);
				it = begin();
				for (; it != end(); ++it)
					if (_compare_function(it->first, key) == false)
						return (it); 
				return (it);
			}

			iterator									upper_bound( const key_type& key )
			{
				iterator it = this->find(key);
				if (it != end())
					return (++it);
				it = begin();
				for (; it != end(); ++it)
					if (_compare_function(key, it->first))
						return (it);
				return (it);
			}

			const_iterator							upper_bound( const key_type& key ) const
			{
				const_iterator it = this->find(key);
				if (it != end())
					return (++it);
				it = begin();
				for (; it != end(); ++it)
					if (_compare_function(key, it->first))
						return (it);
				return (it);
			}

		// Observers
			key_compare				key_comp( void ) const
			{
				return (_compare_function);
			}

			ft::map<Key, T, Compare, Allocator>::value_compare	value_comp( void ) const
			{
				return (value_compare(_compare_function));
			}

protected:

private:

	typedef	typename ft::RBTree<const key_type, mapped_type, key_compare, value_compare, allocator_type>::node_type	node_type;


	key_compare		_compare_function;
	allocator_type	_alloc;
	

	RBTree<const key_type, mapped_type, key_compare, value_compare, allocator_type> _tree;

};

// Non member functions
	// Overload operators

		template < class Key, class T, class Compare, class Alloc >
		bool	operator==( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template < class Key, class T, class Compare, class Alloc >
		bool	operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			return (!(lhs == rhs));
		}

		template < class Key, class T, class Compare, class Alloc >
		bool	operator<( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template < class Key, class T, class Compare, class Alloc >
		bool	operator<=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			return (!(rhs < lhs));
		}

		template < class Key, class T, class Compare, class Alloc >
		bool	operator>( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			return (rhs < lhs);
		}

		template < class Key, class T, class Compare, class Alloc >
		bool	operator>=( const ft::map<Key, T, Compare, Alloc>& lhs,
							const ft::map<Key, T, Compare, Alloc>& rhs )
		{
			return (!(lhs < rhs));
		}

	// Swap
		template < class Key, class T, class Compare, class Alloc >
		void	swap( ft::map<Key, T, Compare, Alloc>& lhs,
						ft::map<Key, T, Compare, Alloc>& rhs )
		{
			lhs.swap(rhs);
		}



};
