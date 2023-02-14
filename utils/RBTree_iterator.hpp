/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:16:40 by afaby             #+#    #+#             */
/*   Updated: 2023/02/14 09:57:23 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

#include "./bidirectional_iterator_tag.hpp"

namespace ft
{

template<
	class ValueType
>
class Node;

template<class Key, class T>
class RBTree_iterator
{
public:
	typedef std::ptrdiff_t						difference_type;
	typedef ft::pair<const Key, T>				value_type;
	typedef ft::Node<value_type>				node_type;
	typedef node_type*							node_pointer;
	typedef value_type*							pointer;	
	typedef value_type&							reference;
	typedef ft::bidirectional_iterator_tag		iterator_category;


	/* Constructors */
	RBTree_iterator(void) :
		_target(NULL),
		_root(NULL),
		_end(NULL)
	{
	}

	operator RBTree_iterator< const Key, const T>( void ) const
	{
		return (RBTree_iterator<const Key, const T>(_target, _root, _end));
	}

	RBTree_iterator( const RBTree_iterator& other ) :
		_target(other.base()),
		_root(other._root),
		_end(other._end)
	{
	}

	RBTree_iterator(node_pointer target, node_pointer root, node_pointer end) :
		_target(target),
		_root(root),
		_end(end)
	{
	}

	/* Destructor */
	~RBTree_iterator(void)
	{
	}


	/* Assignment operator */
	RBTree_iterator&	operator=(const RBTree_iterator& other)
	{
		_target = other.base();
		_root = other._root;
		_end = other._end;
		return (*this);
	}	


	/* Member access operators */
	reference	operator*(void) const
	{
		return (_target->getReelPair());
	}

	pointer	operator->(void) const
	{
		return (&(operator*()));
	}

	node_pointer	base(void) const
	{
		return (_target);
	}

	/* Increment / Decrement operator */
	RBTree_iterator	operator++(int)
	{
		node_pointer	new_target(_target);
		RBTree_iterator	tmp = *this;

		this->operator++();
		return (tmp);
	}

	RBTree_iterator&	operator++(void)
	{
		node_pointer	new_target(_target);

		if (_target == _end)
			return (this->operator--());
		if (_target == _target->getBottomRight(_root))
			new_target = _end;
		else if (_target->getRight())
			new_target = _target->getBottomLeft(_target->getRight());
		else
		{
			new_target = _target->getParent();
			while (new_target && _target->isRightChild())
			{
				new_target = new_target->getParent();
				_target = _target->getParent();
			}
		}
		_target = new_target;
		return (*this);
	}
	
	RBTree_iterator	operator--(int)
	{
		node_pointer	new_target(_target);
		RBTree_iterator	tmp = *this;

		this->operator--();
		return (tmp);
	}

	RBTree_iterator&	operator--(void)
	{
		node_pointer	new_target(_target);

		if (_target == _target->getBottomLeft(_root))
			new_target = _end;
		else if (_target == _end)
			new_target = _target->getBottomRight(_root);
		else if (_target->getLeft())
			new_target = _target->getBottomRight(_target->getLeft());
		else
		{
			new_target = _target->getParent();
			while (new_target && _target->isLeftChild())
			{
				new_target = new_target->getParent();
				_target = _target->getParent();
			}
		}
		_target = new_target;
		return (*this);
	}

	/* Comparisons operator */
	template<class It>
	bool	operator==(const It& other) const
	{
		return (_target == other.base());
	}

	template<class It>
	bool	operator!=(const It& other) const
	{
		return (_target != other.base());
	}
	

private:
	node_pointer	_target;
	node_pointer	_end;
	node_pointer	_root;

};


}

#endif
