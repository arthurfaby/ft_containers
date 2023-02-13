/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:16:40 by afaby             #+#    #+#             */
/*   Updated: 2023/02/13 10:02:59 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

#include "./RBTree.hpp"
#include "./bidirectional_iterator_tag.hpp"

namespace ft
{

template<
	class Key,
	class T,
	class Compare,
	class Allocator
>
class Node;

template<
	class Key,
	class T,
	class Compare,
	class Allocator
>
class RBTree;

template<class Key, class T, class Compare, class Allocator>
class RBTree_iterator
{
public:
	typedef std::ptrdiff_t														difference_type;
	typedef typename ft::RBTree<const Key, T, Compare, Allocator>::node_type	node_type;
	typedef typename ft::RBTree<const Key, T, Compare, Allocator>::value_type	value_type;
	typedef node_type*															node_pointer;
	typedef value_type*															pointer;	
	typedef value_type&															reference;
	typedef ft::bidirectional_iterator_tag										iterator_category;


	/* Constructors */
	RBTree_iterator(void) :
		_target(NULL)
	{
	}

	/* template<class Key2, class T2, class Compare2, class Allocator2> */
	/* RBTree_iterator(const RBTree_iterator<Key2, T2, Compare2, Allocator2>& other) : */
	/* 	_target(other.base()) */
	/* { */
	/* } */

	operator RBTree_iterator< const Key, const T, Compare, Allocator>( void ) const
	{
		return (RBTree_iterator<const Key, const T, Compare, Allocator>(_target));
	}

	RBTree_iterator( const RBTree_iterator& other ) :
		_target(other.base())
	{
	}

	RBTree_iterator(node_pointer target) :
		_target(target)
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

		if (_target == _target->getTree()->getEnd())
			return (this->operator--(1));
		if (_target == _target->getBottomRight(_target->getTree()->getRoot()))
			new_target = _target->getTree()->getEnd();
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
		return (tmp);
	}

	RBTree_iterator&	operator++(void)
	{
		node_pointer	new_target(_target);

		if (_target == _target->getTree()->getEnd())
			return (this->operator--());
		if (_target == _target->getBottomRight(_target->getTree()->getRoot()))
			new_target = _target->getTree()->getEnd();
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

		if (_target == _target->getTree()->getBottomLeft(_target->getTree()->getRoot()))
			new_target = _target->getTree()->getEnd();
		else if (_target == _target->getTree()->getEnd())
			new_target = _target->getBottomRight(_target->getTree()->getRoot());
		else if (_target->getLeft())
			new_target = _target->getBottomRight(_target->getLeft());
		{
			new_target = _target->getParent();
			while (new_target && _target->isLeftChild())
			{
				new_target = new_target->getParent();
				_target = _target->getParent();
			}
		}
		_target = new_target;
		return (tmp);
	}

	RBTree_iterator&	operator--(void)
	{
		node_pointer	new_target(_target);

		if (_target == _target->getTree()->getBottomLeft(_target->getTree()->getRoot()))
			new_target = _target->getTree()->getEnd();
		else if (_target == _target->getTree()->getEnd())
			new_target = _target->getBottomRight(_target->getTree()->getRoot());
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

};


}

#endif
