/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_RBTree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:28:48 by afaby             #+#    #+#             */
/*   Updated: 2023/02/20 10:26:17 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

template<class It>
class reverse_RBTree_iterator
{

public:
	
	/* Member types */
	typedef It											iterator_type;
	typedef typename iterator_type::difference_type		difference_type;
	typedef typename iterator_type::value_type			value_type;
	typedef typename iterator_type::pointer				pointer;
	typedef typename iterator_type::reference			reference;
	typedef typename iterator_type::iterator_category	iterator_category;
	typedef typename iterator_type::node_type			node_type;
	typedef typename iterator_type::node_pointer		node_pointer;


	/* Constructions */
	reverse_RBTree_iterator(void) :
		_it(iterator_type())
	{
	}

	reverse_RBTree_iterator(node_pointer target, node_pointer end) :
		_it(iterator_type(target, end))
	{
	}

	reverse_RBTree_iterator( const iterator_type& other ) :
		_it(other)
	{
		
	}

	template<class It2>
	reverse_RBTree_iterator( const reverse_RBTree_iterator<It2>& other ) :
		_it(other.base())
	{
	}

	~reverse_RBTree_iterator(void)
	{
	}


	/* Assignment operator */
	reverse_RBTree_iterator&	operator=( const reverse_RBTree_iterator& other )
	{
		this->_it = other._it;
		return (*this);
	}


	/* Member access operator */
	reference	operator*(void) const
	{
		iterator_type	tmp = _it;

		--tmp;
		return (*tmp);
	}

	pointer	operator->(void) const
	{
		return (&(operator*()));
	}

	iterator_type	base(void) const
	{
		return (_it);
	}


	/* Increment / Decrement operators */
	reverse_RBTree_iterator&	operator++(void)
	{
		_it--;
		return (*this);
	}

	reverse_RBTree_iterator	operator++(int)
	{
		reverse_RBTree_iterator	tmp;

		tmp._it = _it--;
		return (tmp);
	}

	reverse_RBTree_iterator&	operator--(void)
	{
		_it++;
		return (*this);
	}

	reverse_RBTree_iterator	operator--(int)
	{
		reverse_RBTree_iterator	tmp;

		tmp._it	= _it++;
		return (tmp);
	}


	/* Comparisons operators */
	template<class It2>
	bool	operator==(const reverse_RBTree_iterator<It2>& other) const
	{
		return (_it == other.base());
	}

	template<class It2>
	bool	operator!=(const reverse_RBTree_iterator<It2>& other) const
	{
		return (_it != other.base());
	}

protected:
	iterator_type	_it;

};

}
