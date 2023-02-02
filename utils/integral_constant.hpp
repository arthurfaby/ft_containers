/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:42:51 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:49:10 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class T, bool v>
struct integral_constant
{
public:
	typedef T					value_type;
	typedef integral_constant	type;

	static const bool	value = v;

	operator	value_type()
	{
		return value;
	}
};

}
