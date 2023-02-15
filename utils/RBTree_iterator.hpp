/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:16:40 by afaby             #+#    #+#             */
/*   Updated: 2023/02/15 19:58:57 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

#include "./iterator_traits.hpp"
#include "./RBTree.hpp"
#include "./bidirectional_iterator_tag.hpp"

namespace ft
{

template<
	class ValueType
>
class Node;

template<class ValueType>
class RBTree_iterator
{
public:
	typedef typename ft::iterator_traits<ValueType*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<ValueType*>::value_type		value_type;
	typedef typename ft::iterator_traits<ValueType*>::pointer			pointer;
	typedef typename ft::iterator_traits<ValueType*>::reference			reference;
	typedef ft::random_access_iterator_tag								iterator_category;
	typedef ft::Node<value_type>				node_type;
	typedef node_type*							node_pointer;


	/* Constructors */
	RBTree_iterator(void) :
		_target(NULL),
		_end(NULL),
		_root(NULL)
	{
	}

	operator RBTree_iterator< const ValueType>( void ) const
	{
		return (RBTree_iterator<const ValueType>(_target, _root, _end));
	}

	/* template<class Key2, class T2> */
	RBTree_iterator( const RBTree_iterator& other ) :
		_target(other.base()),
		_end(other._end),
		_root(other._root)
	{
	}

	RBTree_iterator(node_pointer target, node_pointer root, node_pointer end) :
		_target(target),
		_end(end),
		_root(root)
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
		_end = other._end;
		_root = other._root;
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
