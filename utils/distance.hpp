/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:05:51 by afaby             #+#    #+#             */
/*   Updated: 2023/02/04 16:08:52 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class InputIt>
std::ptrdiff_t	distance(InputIt first, InputIt last)
{
	std::ptrdiff_t res = 0;
	while (first != last)
	{
		first++;
		res++;
	}
	return (res);
}

}
