/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:53:22 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:48:52 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
}

}
