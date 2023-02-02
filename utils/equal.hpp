/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:11:03 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:49:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class InputIt1, class InputIt2>
bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

}
