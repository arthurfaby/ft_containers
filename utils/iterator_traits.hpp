/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:04 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:49:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class Iter>
struct iterator_traits
{
public:
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
public:
	typedef std::ptrdiff_t						difference_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
public:
	typedef std::ptrdiff_t						difference_type;
	typedef T									value_type;
	typedef const T*							pointer;
	typedef const T&							reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

}
