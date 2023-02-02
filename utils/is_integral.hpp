/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:16:17 by afaby             #+#    #+#             */
/*   Updated: 2023/02/02 16:49:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "integral_constant.hpp"

namespace ft
{

template<typename T>
struct is_integral : public integral_constant<T, false> {};

template<>
struct is_integral<bool> : public integral_constant<bool, true> {};

template<>
struct is_integral<char> : public integral_constant<bool, true> {};

template<>
struct is_integral<wchar_t> : public integral_constant<bool, true> {};

template<>
struct is_integral<signed char> : public integral_constant<bool, true> {};

template<>
struct is_integral<short int> : public integral_constant<bool, true> {};

template<>
struct is_integral<int> : public integral_constant<bool, true> {};

template<>
struct is_integral<long int> : public integral_constant<bool, true> {};

template<>
struct is_integral<long long int> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned char> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned short int> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned int> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long int> : public integral_constant<bool, true> {};

template<>
struct is_integral<unsigned long long int> : public integral_constant<bool, true> {};

}
