/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:55:00 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:47:38 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"

namespace ft
{

template<class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 x, T2 y)
{
	return ( ft::pair<T1, T2>(x, y) );
}

}
