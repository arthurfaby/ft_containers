/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:29:37 by afaby             #+#    #+#             */
/*   Updated: 2023/02/22 10:43:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <functional>
#include <algorithm>
#include <cstddef>
#include <iostream>

#include "./make_pair.hpp"
#include "./pair.hpp"
#include "./RBTree_iterator.hpp"
#include "../vector.hpp"

#define RED_PRINT	"\e[91m"


namespace ft
{

enum Color {BLACK_COLOR, RED_COLOR};

template<class ValueType>
class Node
{
public:

	typedef	ValueType					pair;
	typedef typename pair::first_type	Key;
	typedef typename pair::second_type	T;

	Node(void) :
		_pair(ft::make_pair<Key, T>(Key(), T())),
		_parent(NULL),
		_left(NULL),
		_right(NULL),
		_color(RED_COLOR)
	{
	}

	Node(pair pair) :
		_pair(pair),
		_parent(NULL),
		_left(NULL),
		_right(NULL),
		_color(RED_COLOR)
	{
	}

	template<class ValueType2>
	Node(const Node<ValueType2>& other) :
		_pair(other._pair),
		_parent(other._parent),
		_left(other._left),
		_right(other._right),
		_color(other._color)
	{
	}

	template<class ValueType2>
	Node&	operator=(const Node<ValueType2>& other)
	{
		_pair = other._pair;
		_parent = other._parent;
		_left = other._left;
		_right = other._right;
		_color = other._color;
		return (*this);
	}

	~Node( void )
	{
	}

	void	setPair(pair pair)
	{
		_pair = pair;
	}

	void	setLeft(Node *left)
	{
		_left = left;
	}

	void	setRight(Node *right)
	{
		_right = right;
	}

	void	setParent(Node *parent)
	{
		_parent = parent;
	}

	void	setColor(Color color)
	{
		_color = color;
	}

	void	changeColor( void )
	{
		if (_color == BLACK_COLOR)
			_color = RED_COLOR;
		else
			_color = BLACK_COLOR;
	}

	bool	isRightChild( void ) const
	{
		if (this->getParent() == NULL)
			return (false);
		if (this->getParent()->getLeft() == this)
			return (false);
		return (true);
	}

	bool	isLeftChild( void ) const
	{
		if (this->getParent() == NULL)
			return (false);
		if (this->getParent()->getRight() == this)
			return (false);
		return (true);
	}

	bool	isRed( void ) const
	{
		return (this->getColor() == RED_COLOR);
	}

	bool	isBlack( void ) const
	{
		return (this->getColor() == BLACK_COLOR);
	}

	Node*	getGrandParent( void ) const
	{
		if (this->getParent())
			return (this->getParent()->getParent());
		return (NULL);
	}

	Node*	getUncle( void ) const
	{
		if (this->getGrandParent())
		{
			if (this->getParent()->isRightChild())
				return (this->getGrandParent()->getLeft());
			return (this->getGrandParent()->getRight());
		}
		return (NULL);
	}

	const Key&	getKey( void ) const
	{
		return (_pair.first);
	}

	const T&	getValue( void ) const
	{
		return (_pair.second);
	}

	pair&	getReelPair( void )
	{
		return (_pair);
	}

	pair	getPair( void ) const
	{
		return (_pair);
	}

	Node*	getParent( void ) const
	{
		return (_parent);
	}

	Node*	getLeft( void ) const
	{
		return (_left);
	}

	Node*	getRight( void ) const
	{
		return (_right);
	}

	Color	getColor( void ) const
	{
		return (_color);
	}

	bool	operator==(const Node& other)
	{
		if (_pair != other._pair)
			return (false);
		if (_parent != other._parent)
			return (false);
		if (_left != other._left)
			return (false);
		if (_right != other._right)
			return (false);
		return (true);
	}

	Node	*getBottomLeft(Node *node) const
	{
		if (!node)
			return (NULL);
		if (node->getLeft())
			return (getBottomLeft(node->getLeft()));
		return (node);
	}

	Node	*getBottomRight(Node *node) const
	{
		if (!node)
			return (NULL);
		if (node->getRight())
			return (getBottomRight(node->getRight()));
		return (node);
	}

private:
	pair	_pair;
	Node	*_parent;
	Node	*_left;
	Node	*_right;
	Color	_color;
	
};


template<
	class Key,
	class T,
	class Compare,
	class ValueComp,
	class Allocator = std::allocator< ft::pair< const Key, T > >
>
class RBTree
{
public:

	typedef ft::pair<const Key, T>									value_type;
	typedef Node< value_type >										node_type;
	typedef typename Allocator::template rebind<node_type>::other	allocator_type;
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef Compare													compare_type;
	typedef ft::RBTree_iterator<value_type>							iterator;
	typedef ft::RBTree_iterator<const value_type>					const_iterator;
	typedef size_t													size_type;
	typedef ValueComp												value_compare;



	RBTree( void ) :
		_root(NULL),
		_end(NULL),
		_alloc(allocator_type()),
		_compare_function(compare_type()),
		_value_comp(value_compare(_compare_function))
	{
		_end = _alloc.allocate(1);
		_alloc.construct(_end, node_type());
	}

	~RBTree( void )
	{
		delete_subtree(_root);
		_root = NULL;
		if (_end)
		{
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		}
		_end = NULL;
	}

	RBTree( const RBTree& other ) :
		_value_comp(other._compare_function)
	{
		if (!other._root)
			_root = NULL;
		else
			_root = this->clone(NULL, other._root);
		_end = _alloc.allocate(1);
		if (!other._end)
			_alloc.construct(_end, node_type());
		else
			_alloc.construct(_end, node_type(*other._end));
		_alloc = other._alloc;
		_compare_function = other._compare_function;
	}

	RBTree&	operator=(const RBTree& other)
	{
		if (this == &other)
			return (*this);
		if (_end)
		{
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		}
		if (_root)
		{
			delete_subtree(_root);
			_root = NULL;
		}
		if (!other._root)
			_root = NULL;
		else
			_root = this->clone(NULL, other._root);
		_end = _alloc.allocate(1);
		if (!other._end)
			_alloc.construct(_end, node_type());
		else
			_alloc.construct(_end, node_type(*other._end));
		_alloc = other._alloc;
		_compare_function = other._compare_function;
		_value_comp	= other._value_comp;
		return (*this);
	}

	node_type*	clone(node_type *parent, node_type* node)
	{
		if (!node)
			return (NULL);
		node_type	*new_node = _alloc.allocate(1);
		_alloc.construct(new_node, node_type(*node));
		new_node->setParent(parent);
		new_node->setLeft(this->clone(new_node, node->getLeft()));
		new_node->setRight(this->clone(new_node, node->getRight()));
		return (new_node);
	}

	void	swap(RBTree& other)
	{
		std::swap(_root, other._root);
		std::swap(_end, other._end);
		std::swap(_alloc, other._alloc);
		std::swap(_compare_function, other._compare_function);
		std::swap(_value_comp, other._value_comp);
	}

	size_type	size( void ) const
	{
		return (size_recursive(_root));
	}

	node_type*	getBottomRight( void ) const
	{
		node_type	*tmp = _root;

		while (tmp)
		{
			if (tmp->getRight() && tmp->getRight() != _end)
				tmp = tmp->getRight();
			else
				break;
		}
		return (tmp);
	}

	node_type*	getBottomLeft( void ) const
	{
		node_type	*tmp = _root;

		while (tmp)
		{
			if (tmp->getLeft())
				tmp = tmp->getLeft();
			else
				break;
		}
		return (tmp);
	}

	void	remove(const key_type& key)
	{
		this->remove_private(key);
		this->check_end_modif();
	}

	iterator	begin( void )
	{
		node_type *node;

		if (!_root)
			return (end());
		node = this->getBottomLeft(_root);
		return (iterator(node, _end));
	}

	const_iterator	begin( void ) const
	{
		node_type *node;

		if (!_root)
			return (end());
		node = this->getBottomLeft(_root);
		return (const_iterator(node, _end));
	}

	iterator	end( void )
	{
		return (iterator(_end, _end));
	}

	const_iterator	end( void ) const
	{
		return (const_iterator(_end, _end));
	}

	node_type*	find(const key_type &key) const
	{
		node_type	*res;

		res = find_recursive(_root, key);
		if (!res)
			return (_end);
		return (res);
	}

	void	insert(const value_type& pair)
	{
		this->insert(pair, &_root);
	}

	void	insert(const value_type& pair, node_type **top)
	{
		node_type	*tmp;

		if (this->find(pair.first) != _end)
			return ;
		node_type	*new_node = _alloc.allocate(1);
		_alloc.construct(new_node, node_type(pair));
		if (*top == NULL)
		{
			*top = new_node;
			(*top)->setColor(BLACK_COLOR);
			this->check_end_modif();
			return ;
		}
		tmp = *top;
		while (tmp)
		{
			if (_value_comp(tmp->getPair(), pair) == 0)
			{
				if (!tmp->getLeft())
				{
					tmp->setLeft(new_node);
					new_node->setParent(tmp);
					repair_tree_insert(new_node);
					this->check_end_modif();
					return ;
				}
				else
					tmp = tmp->getLeft();
			}
			else
			{
				if (!tmp->getRight())
				{
					tmp->setRight(new_node);
					new_node->setParent(tmp);
					repair_tree_insert(new_node);
					this->check_end_modif();
					return ;
				}
				else
					tmp = tmp->getRight();
			}
		}
		_root->setColor(BLACK_COLOR);
		this->check_end_modif();
	}

	void	show( void ) const
	{
		std::cout << "##################################################" << std::endl;
		if (_root)
			print2DUtil(_root, 0);
		else
			std::cerr << std::endl << "Can't show empty tree." << std::endl;
		std::cout << std::endl;
		std::cout << "##################################################" << std::endl;
	}

	node_type	*getBottomLeft(node_type *node) const
	{
		if (!node)
			return (NULL);
		if (node->getLeft())
			return (getBottomLeft(node->getLeft()));
		return (node);
	}

	node_type	*getBottomRight(node_type *node) const
	{
		if (!node)
			return (NULL);
		if (node->getRight())
			return (getBottomRight(node->getRight()));
		return (node);
	}

	bool	empty( void ) const
	{
		return ( this->size() == 0 );
	}

	void	clear( void )
	{
		/* delete_subtree(_root); */
		/* _root = NULL; */
		while (_root)
			this->remove(_root->getKey());
	}

	void	erase( iterator pos )
	{
		this->remove(pos->first);
		this->check_end_modif();
	}

	node_type	*getEnd( void ) const
	{
		return (_end);
	}

	node_type	*getRoot( void ) const
	{
		return (_root);
	}

private:
	node_type		*_root;
	node_type		*_end;
	allocator_type	_alloc;
	compare_type	_compare_function;
	value_compare	_value_comp;

	size_type	size_recursive( node_type *node ) const
	{
		if (!node)
			return (0);
		return (1 + size_recursive(node->getLeft()) + size_recursive(node->getRight()));
	}

	void	delete_subtree(node_type *node)
	{
		if (!node)
			return ;
		if (node->getLeft())
			delete_subtree(node->getLeft());
		if (node->getRight())
			delete_subtree(node->getRight());
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	void	remove_private(const key_type& key)
	{
		node_type	*z;
		node_type	*x;
		node_type	*y;
		Color		y_original_color;

		z = find_recursive(_root, key);
		if (!z)
			return ;
		y = z;
		y_original_color = y->getColor();
		if (z->getLeft() == NULL)
		{
			x = z->getRight();
			transplant(z, z->getRight());
		}
		else if (z->getRight() == NULL)
		{
			x = z->getLeft();
			transplant(z, z->getLeft());
		}
		else
		{
			y = getBottomLeft(z->getRight());
			y_original_color = y->getColor();
			x = y->getRight();
			if (y->getParent() == z && x)
				x->setParent(y);
			else
			{
				transplant(y, y->getRight());
				y->setRight(z->getRight());
				if (y->getRight())
					y->getRight()->setParent(y);
			}
			transplant(z, y);
			y->setLeft(z->getLeft());
			if (y->getLeft())
				y->getLeft()->setParent(y);
			y->setColor(z->getColor());
		}
		_alloc.destroy(z);
		_alloc.deallocate(z, 1);
		z = NULL;
		if (y_original_color == BLACK_COLOR)
			repair_tree_delete(x);
		this->check_end_modif();
	}

	void	transplant(node_type *u, node_type *v)
	{
		if (u->getParent() == NULL)
			_root = v;
		else if (u->isLeftChild())
			u->getParent()->setLeft(v);
		else
			u->getParent()->setRight(v);
		if (v)
			v->setParent(u->getParent());
	}

	node_type	*find_recursive(node_type *node, const key_type& key) const
	{
		if (!node || node->getKey() == key)
			return (node);
		if (_compare_function(node->getKey(), key) == 0)
			return (find_recursive(node->getLeft(), key));
		return (find_recursive(node->getRight(), key));
	}	

	void	rotateLeft(node_type* node)
	{
		node_type	*second;

		second = node->getRight();
		if (second)
			node->setRight(second->getLeft());
		if (second && second->getLeft())
			second->getLeft()->setParent(node);
		if (second)
			second->setParent(node->getParent());
		if (node->getParent() == NULL)
			_root = second;
		else if (node == node->getParent()->getLeft())
			node->getParent()->setLeft(second);
		else
			node->getParent()->setRight(second);
		if (second)
			second->setLeft(node);
		node->setParent(second);
	}

	void	rotateRight(node_type* node)
	{
		node_type	*second;

		second = node->getLeft();
		node->setLeft(second->getRight());
		if (second->getRight())
			second->getRight()->setParent(node);
		second->setParent(node->getParent());
		if (node->getParent() == NULL)
			_root = second;
		else if (node == node->getParent()->getRight())
			node->getParent()->setRight(second);
		else
			node->getParent()->setLeft(second);
		second->setRight(node);
		node->setParent(second);
	}

	void	LLRotation(node_type* node)
	{
		node_type	*grand_parent = node->getGrandParent();
		node_type	*parent = node->getParent();
		Color		tmp;

		if (!node || !parent || !grand_parent)
			return ;
		rotateRight(grand_parent);
		tmp = grand_parent->getColor();
		grand_parent->setColor(parent->getColor());
		parent->setColor(tmp);
	}

	void	RRRotation(node_type *node)
	{
		node_type	*grand_parent = node->getGrandParent();
		node_type	*parent = node->getParent();
		Color		tmp;

		if (!node || !parent || !grand_parent)
			return ;
		rotateLeft(grand_parent);
		tmp = grand_parent->getColor();
		grand_parent->setColor(parent->getColor());
		parent->setColor(tmp);	
	}

	void	repair_tree_delete(node_type *x)
	{
		node_type	*s;

		if (!x)
			return ;
		while (x != _root && x && x->isBlack())
		{
			if (x->isLeftChild())
			{
				s = x->getParent()->getRight();
				if (s && s->isRed())
				{
					s->setColor(BLACK_COLOR);
					if (x->getLeft())
						x->getLeft()->setColor(RED_COLOR);
					rotateLeft(x->getParent());
					x = x->getParent()->getRight();
				}
				if (s && s->getLeft() && s->getLeft()->isBlack() && s->getRight()->isBlack())
				{
					s->setColor(RED_COLOR);
					x = x->getParent();
				}
				else
				{
					if (s && s->getRight() && s->getRight()->isBlack())
					{
						if (s->getLeft())
							s->getLeft()->setColor(BLACK_COLOR);
						s->setColor(RED_COLOR);
						rotateRight(s);
						s = x->getParent()->getRight();
					}
					if (x->getParent())
					{
						if (s)
							s->setColor(x->getParent()->getColor());
						x->getParent()->setColor(BLACK_COLOR);
					}
					if (s && s->getRight())
						s->getRight()->setColor(BLACK_COLOR);
					rotateLeft(x->getParent());
					x = _root;
				}

			}
			else
			{
				s= x->getParent()->getLeft();
				if (s->isRed())
				{
					s->setColor(BLACK_COLOR);
					x->getParent()->setColor(RED_COLOR);
					rotateLeft(x->getParent());
					if (x->getParent())
						s = x->getParent()->getLeft();
				}
				if (s->getLeft()->isBlack() && s->getRight()->isBlack())
				{
					s->setColor(RED_COLOR);
					x = x->getParent();
				}
				else
				{
					if (s->getLeft()->isBlack())
					{
						s->getRight()->setColor(BLACK_COLOR);
						s->setColor(RED_COLOR);
						rotateLeft(s);
						if (x->getParent())
							s = x->getParent()->getLeft();
					}
					if (x->getParent())
					{
						s->setColor(x->getParent()->getColor());
						x->getParent()->setColor(BLACK_COLOR);
					}
					s->getLeft()->setColor(BLACK_COLOR);
					x = _root;
				}
			}
		}
		if (x)
			x->setColor(BLACK_COLOR);
		this->check_end_modif();
	}

	void	repair_tree_insert(node_type *node)
	{
		if (!node)
			return ;

		node_type	*uncle = node->getUncle();
		node_type	*grand_parent = node->getGrandParent();
		node_type	*parent = node->getParent();

		if (!parent)
			return ;
		if (parent->isRed())
		{
			if (uncle && uncle->isRed())
			{
				uncle->setColor(BLACK_COLOR);
				parent->setColor(BLACK_COLOR);
				if (grand_parent)
					grand_parent->setColor(RED_COLOR);
				repair_tree_insert(grand_parent);
			}
			else
			{
				if (node->isLeftChild() && parent->isLeftChild())
				{
					LLRotation(node);
					repair_tree_insert(parent);
				}
				else if (node->isRightChild() && parent->isLeftChild())
				{
					rotateLeft(parent);
					LLRotation(parent);
					repair_tree_insert(parent);
				}
				else if (node->isRightChild() && parent->isRightChild())
				{
					RRRotation(node);
					repair_tree_insert(parent);
				}
				else
				{
					rotateRight(parent);
					RRRotation(parent);
					repair_tree_insert(parent);
				}

			}
		}
		_root->setColor(BLACK_COLOR);
		this->check_end_modif();
	}

	void	check_end_modif( void )
	{
		if (_end)
			_end->setParent(_root);
		return ;
	}


	#define COUNT 20

	void	print2DUtil(node_type* root, int space) const
	{
		if (root == NULL)
			return ;

		space += COUNT;
		print2DUtil(root->getRight(), space);
		std::cout << std::endl;
		for (int i = COUNT; i < space; i++)
			std::cout << " ";
		if (root->getColor() == RED_COLOR)
			std::cout << RED_PRINT;
		std::cout << root->getPair().first << "\e[0m" <<  " (" << root << ", " << root->getParent() << ", " << root->getLeft() << ", " << root->getRight () << ")" << std::endl;
		print2DUtil(root->getLeft(), space);
	}
};

}

#endif
