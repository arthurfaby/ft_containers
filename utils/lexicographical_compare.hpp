/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:34:02 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:49:22 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<class InputIt1, class InputIt2>
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
{
	while (first1 != last1 && first2 != last2)
	{
		if (*first1 < *first2)
			return (true);
		if (*first1 > *first2)
			return (false);
		first1++;
		first2++;
	}
	return ((first1 == last1) && (first2 != last2));
}

template<class InputIt1, class InputIt2, class Compare>
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare	comp)
{
	while (first1 != last1 && first2 != last2)
	{
		if (comp(*first1, *first2))
			return (true);
		if (!comp(*first1, *first2))
			return (false);
		first1++;
		first2++;
	}
	return ((first1 == last1) && (first2 != last2));
}

}
