/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:29:49 by afaby             #+#    #+#             */
/*   Updated: 2023/01/30 18:27:49 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include <cstring>

namespace ft
{

template < class T, class Allocator = std::allocator<T> >
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
	// iterator					--> LegacyRandomAccessIterator and LegacyContiguousIterator to value_type
	// const_iterator			--> LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type
	// reverse_iterator			--> ft::reverse_iterator<iterator>
	// const_reverse_iterator	--> ft::reverse_iterator<const_iterator>


public:
	// Member types

		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef size_t											size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef	value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename std::vector<T>::iterator				iterator;
		typedef typename std::vector<T>::const_iterator			const_iterator;
		typedef typename std::vector<T>::reverse_iterator		reverse_iterator;
		typedef typename std::vector<T>::const_reverse_iterator	const_reverse_iterator;
	
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
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_data + i, value);
			}
			
			/* 
			template < class InputIt >
			vector( InputIt first,
					InputIt last,
					const allocator_type& alloc = allocator_type() );
			*/ 																	// (5)
			vector( const vector& other ) :
				_data(NULL),
				_capacity(other._capacity),
				_size(other._size),
				_alloc(other._alloc)
			{
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
				_capacity = other._capacity;
				_size = other._size;
				_alloc = other._alloc;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(_data + i, other[i]);
				return (*this);
			}


		// Assign
			void	assign( size_type count, const value_type& value )
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

			/*
			template < class InputIt >
			void	assign( InputIt first, InputIt last )
			{
				size_t	size;

				size = std::distance(first, last); // ft::distance
				this->clear();
				if (size > _capacity)
					this->reserve(size);
				while (first != last)
					this->push_back(*first++);
			} 
			*/


		// Get allocator
			allocator_type			get_allocator( void ) const
			{
				return (_alloc);
			}


		// Element access
			reference				at( size_type pos )
			{
				return (_data[pos]);
			}

			const_reference			at( size_type pos ) const
			{
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
					return (this->begin());
				}

				iterator	res;
				int			index_pos;

				index_pos = pos - this->begin();
				if (_size == _capacity)
				{
					if(_size == 0)
						this->reserve(1);
					else
						this->reserve(_capacity * 2);
				}
				res = this->begin();
				std::cout << "index_pos : " << index_pos << std::endl;
				std::cout << "_data : " << _data << std::endl;
				std::cout << "_size : " << _size << std::endl;
				std::memmove(_data + index_pos + 1, _data + index_pos, _size - index_pos);
				_alloc.construct(_data + index_pos, value);
				res += index_pos;
				_size++;
				return (res);
			}
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

			void						push_back( const value_type& value )
			{
				if (_size == _capacity)
				{
					if (_size == 0)
						this->reserve(1);
					else
						this->reserve(_capacity * 2);
				}
				_data[_size] = value;
				++_size;
			}

			void						pop_back( void )
			{
				// Protect segfautl
				--_size;
				_alloc.destroy(_data + _size);
			}

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
	value_type		*_data;
	size_type		_capacity;
	size_type		_size;
	allocator_type	_alloc;


};

}
