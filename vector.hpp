/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:29:49 by afaby             #+#    #+#             */
/*   Updated: 2023/02/21 10:36:43 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iterator>
#include <cstring>
#include <sstream>
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/random_access_iterator.hpp"
#include "utils/distance.hpp"
#include "utils/reverse_iterator.hpp"



#include <iostream>




namespace ft
{

template < class T, class Allocator = std::allocator<T> >
class vector
{

public:
	// Member types

		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef size_t									size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef	value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ft::random_access_iterator<T*>			iterator;
		typedef ft::random_access_iterator<const T*>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	// Member functions :
			explicit vector( const allocator_type& alloc = allocator_type() ) :
				_data(NULL),
				_capacity(0),
				_size(0),
				_alloc(alloc)
			{
			}

			explicit vector( size_type count,
							const value_type& value = value_type(),
							const allocator_type& alloc = allocator_type() ) :
				_data(NULL),
				_capacity(count),
				_size(count),
				_alloc(alloc)
			{
				if (_capacity > max_size())
					throw std::length_error("cannot create std::vector larger than max_size()");
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_data + i, value);
			}
			
			 
			template < class InputIt >
			vector( InputIt first,
					InputIt last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) :
				_alloc(alloc)
			{
				size_t	size = ft::distance(first, last);

				_size = size;
				_capacity = size;
				if (_capacity > max_size())
					throw std::length_error("cannot create std::vector larger than max_size()");
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i, ++first)
					_alloc.construct(_data + i, *first);
			}

			vector( const vector& other ) :
				_data(NULL),
				_capacity(other._size),
				_size(other._size),
				_alloc(other._alloc)
			{
				if (_capacity > max_size())
					throw std::length_error("cannot copy std::vector larger than max_size()");
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_data + i, other[i]);
			}

		// Destructor :
			~vector( void )
			{
				this->clear();
				if (_data)
					_alloc.deallocate(_data, _capacity);
			}


		// Copy assignement operator
			vector&	operator=( const vector& other )
			{
				if (this == &other)
					return (*this);
				if (_data)
				{
					this->clear();
					_alloc.deallocate(_data, _capacity);
				}
				_capacity = other._size;
				_size = other._size;
				_alloc = other._alloc;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_data + i, other[i]);
				return (*this);
			}


		// Assign
			void	assign( size_type count, const value_type& value)
			{
				this->clear();
				_size = count;
				if (count > _capacity)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = count;
					_data = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; ++i)
						_alloc.construct(_data + i, value);
				}
				else
				{
					for (size_t i = 0; i < _size; ++ i)
						_alloc.construct(_data + i, value);
				}
			}

			template < class InputIt >
			void	assign( InputIt first, InputIt last,
							typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				size_t	size;

				size = ft::distance(first, last);
				this->clear();
				if (size > _capacity)
					this->reserve(size);
				while (first != last)
					this->push_back(*first++);
			} 


		// Get allocator
			allocator_type			get_allocator( void ) const
			{
				return (_alloc);
			}


		// Element access
			reference				at( size_type pos )
			{
				if (pos >= _size)
				{
					std::ostringstream	stream;

					stream << "vector::_M_range_check: __n (which is " << pos;
					stream << ") >= this->size() (which is " << _size << ")";
					throw (std::out_of_range(stream.str()));
				}
				return (_data[pos]);
			}

			const_reference			at( size_type pos ) const
			{
				if (pos >= _size)
				{
					std::ostringstream	stream;

					stream << "vector::_M_range_check: __n (which is " << pos;
					stream << ") >= this->size() (which is " << _size << ")";
					throw (std::out_of_range(stream.str()));
				}
				return (_data[pos]);
			}

			reference				operator[]( size_type pos )
			{
				return (_data[pos]);
			}

			const_reference			operator[]( size_type pos ) const
			{
				return (_data[pos]);
			}

			reference				front( void )
			{
				return (_data[0]);
			}

			const_reference			front( void ) const
			{
				return (_data[0]);
			}

			reference				back( void )
			{
				return (_data[_size - 1]);
			}

			const_reference			back( void ) const
			{
				return (_data[_size - 1]);
			}

			value_type*				data( void )
			{
				return (_data);
			}
			
			const value_type*		data( void ) const
			{
				return (_data);
			}


		// Iterators
			iterator					begin( void )
			{
				iterator	it(_data);

				return (it);
			}
			const_iterator			begin( void ) const
			{
				const_iterator	cit(_data);

				return (cit);
			}

			iterator					end( void )
			{
				iterator	ite(_data + _size);

				return (ite);
			}
			const_iterator			end( void ) const
			{
				const_iterator	cite(_data + _size);

				return (cite);
			}

			reverse_iterator			rbegin( void )
			{
				reverse_iterator	rit(this->end());

				return (rit);
			}

			const_reverse_iterator		rbegin( void ) const
			{
				const_reverse_iterator	crit(this->end());

				return (crit);				
			}

			reverse_iterator			rend( void )
			{
				reverse_iterator	rite(this->begin());

				return (rite);
			}
			const_reverse_iterator		rend( void ) const
			{
				const_reverse_iterator	crite(this->begin());

				return (crite);
			}

		// Capacity
			bool					empty( void ) const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type				size( void ) const
			{
				return (_size);
			}

			size_type				max_size( void ) const
			{
				return (_alloc.max_size());
			}

			void						reserve( size_type new_cap )
			{
				pointer		res;
				size_type	save_size(_size);

				if (new_cap <= _capacity)
					return ;
				if (new_cap >= max_size())
					throw std::length_error("vector::reserve");
				res = _alloc.allocate(new_cap);
				for (size_t i = 0; i < _size; ++i)
					_alloc.construct(res + i, _data[i]);
				this->clear();
				if (_data)
					_alloc.deallocate(_data, _capacity);
				_size = save_size;
				_data = res;
				_capacity = new_cap;
			}

			size_type				capacity( void ) const
			{
				return (_capacity);
			}


		// Modifiers
			void						clear( void )
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_data + i);
				_size = 0;
			}

			iterator					insert( const_iterator pos,
												const value_type& value )
			{
				if  (pos == this->end())
				{
					this->push_back(value);
					return (this->end() - 1);
				}
				return (this->choose_insert(pos, 1, value, value_type()));
			}

			void						insert( const_iterator pos,
												size_type count,
												const value_type& value )
			{
				this->choose_insert(pos, count, value, value_type());
			}

			template < class InputIt >
			iterator					insert( const_iterator pos,
												InputIt first,
												InputIt last,
												typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				return (this->choose_insert(pos, first, last, value_type()));
			}

			iterator					erase( iterator pos )
			{
				return (this->erase(pos, pos + 1));
			}

			iterator					erase( iterator first, iterator last )
			{
				return (this->choose_erase(first, last, value_type()));
			}

			void						push_back( const value_type& value )
			{
				if (_size == _capacity)
					this->check_and_reserve();
				_alloc.construct(_data + _size, value);
				++_size;
			}

			void						pop_back( void )
			{
				if (_size == 0)
					return ;
				--_size;
				_alloc.destroy(_data + _size);
			}

			void						resize( size_type count,
												value_type value = value_type() )
			{
				while (count > _capacity)
					this->check_and_reserve();
				if (_size > count)
				{
					while (_size != count)
					{
						--_size;
						_alloc.destroy(_data + _size);
					}
				}
				else if (_size < count)
				{
					for (; _size < count; ++_size)
						_alloc.construct(_data + _size, value);
				}
			}

			void						swap( vector& other )
			{
				std::swap(this->_size, other._size);
				std::swap(this->_capacity, other._capacity);
				std::swap(this->_alloc, other._alloc);
				std::swap(this->_data, other._data);
			}

protected:

private:
	value_type		*_data;
	size_type		_capacity;
	size_type		_size;
	allocator_type	_alloc;


	void	check_and_reserve(void)
	{
		if (_capacity == 0)
			this->reserve(1);
		else
			this->reserve(_capacity * 2);
	}

	template<class Check>
	iterator	choose_erase(	iterator first,
								iterator last,
								const Check&,
								typename ft::enable_if<ft::is_integral<Check>::value>::type* = 0)
	{
		int	dis = ft::distance(first, last);
		int	index_first = first - this->begin();

		std::memmove(_data + index_first, _data + index_first + dis, sizeof(value_type) * (_size - index_first - dis));
		_size -= dis;
		return (this->begin() + index_first);
	}

	template<class Check>
	iterator	choose_erase(	iterator first,
								iterator last,
								const Check&,
								typename ft::enable_if<!ft::is_integral<Check>::value>::type* = 0)
	{
		int	index_first = first - this->begin();
		int	dis			= ft::distance(first, last);

		for (size_t i = index_first; i < _size - dis; ++i)
			_data[i] = _data[i + dis];
		while (dis)
		{
			_size--;
			_alloc.destroy(_data + _size);
			dis--;
		}
		return (first);
	}

	template<class Check>
	iterator					choose_insert(	const_iterator pos,
												size_type count,
												const value_type& value,
												const Check&,
												typename ft::enable_if<ft::is_integral<Check>::value>::type* = 0)
	{
		int			index_pos;


		index_pos = pos - this->begin();
		while (_size + count > _capacity)
			this->check_and_reserve();
		std::memmove(_data + index_pos + count, _data + index_pos, sizeof(value_type) * (_size - index_pos));
		_size += count;
		while (count)
			_alloc.construct(_data + index_pos + --count, value);
		return (this->begin() + index_pos);
	}

	template<class Check>
	iterator					choose_insert(	const_iterator pos,
												size_type count,
												const value_type& value,
												const Check&,
												typename ft::enable_if<!ft::is_integral<Check>::value>::type* = 0)
	{
		int			index_pos;
	

		index_pos = pos - this->begin();
		while (_size + count > _capacity)
			this->check_and_reserve();

		for (size_t i = 0; i < count; ++i)
			_alloc.construct(_data + _size + i, value_type());
		_size += count;
		for (size_t i = _size - 1; i > index_pos + count - 1; --i)
			_data[i] = _data[i - count];
		for (size_t i = 0; i < count; ++i)
			_data[i + index_pos] = value;
		return (this->begin() + index_pos);
	}

	template<class InputIt, class Check>
	iterator					choose_insert(	const_iterator	pos,
												InputIt first,
												InputIt last,
												const Check&,
												typename ft::enable_if<ft::is_integral<Check>::value>::type* = 0,
												typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
	{
		int			index_pos;
		size_t		count = ft::distance(first, last);

		index_pos = pos - this->begin();
		while (_size + count > _capacity)
			this->check_and_reserve();
		std::memmove(_data + index_pos + count, _data + index_pos, sizeof(value_type) * (_size - index_pos));
		_size += count;
		while (count)
			_alloc.construct(_data + index_pos + --count, *(--last));
		return (this->begin() + index_pos);
	}
												
	template<class InputIt, class Check>
	iterator					choose_insert(	const_iterator	pos,
												InputIt first,
												InputIt last,
												const Check&,
												typename ft::enable_if<!ft::is_integral<Check>::value>::type* = 0,
												typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
	{
		int			index_pos;
		size_t		count = ft::distance(first, last);

		index_pos = pos - this->begin();
		while (_size + count > _capacity)
			this->check_and_reserve();

		for (size_t i = 0; i < count; ++i)
			_alloc.construct(_data + _size + i, value_type());
		_size += count;
		for (size_t i = _size - 1; i > index_pos + count - 1; --i)
			_data[i] = _data[i - count];
		for (size_t i = 0; i < count; ++i, ++first)
			_data[i + index_pos] = *first;

		return (this->begin() + index_pos);
	}

};

template <class T, class Allocator >
bool	operator==(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); ++i)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template <class T, class Allocator >
bool	operator!=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Allocator >
bool	operator<(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Allocator >
bool	operator<=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Allocator >
bool	operator>(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Allocator >
bool	operator>=(const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template<class T, class Allocator>
void	swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs)
{
	lhs.swap(rhs);
}



}


#endif
