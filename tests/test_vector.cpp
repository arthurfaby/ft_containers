/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:05:41 by afaby             #+#    #+#             */
/*   Updated: 2023/02/07 15:04:31 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <vector>
#include "vector.hpp"

template <typename T>
void	print_std_vector(std::vector< T >& s, std::ofstream &fs)
{
	for (unsigned int i = 0; i < s.size(); i++)
		fs << s[i] << " ";
	fs << std::endl;
	fs << "size : " << s.size() << std::endl;
	fs << "capacity : " << s.capacity() << std::endl;
	fs << "max_size : " << s.max_size() << std::endl;
	if (s.size() > 0)
	{
		fs << "front : " << s.front() << std::endl;
		fs << "back : " << s.back() << std::endl;
	}
}

template <typename T>
void	print_ft_vector(ft::vector< T >& s, std::ofstream &fs)
{
	for (unsigned int i = 0; i < s.size(); i++)
		fs << s[i] << " ";
	fs << std::endl;
	fs << "size : " << s.size() << std::endl;
	fs << "capacity : " << s.capacity() << std::endl;
	fs << "max_size : " << s.max_size() << std::endl;
	if (s.size() > 0)
	{
		fs << "front : " << s.front() << std::endl;
		fs << "back : " << s.back() << std::endl;
	}
}


void	test_vector_creation(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (creation) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	veq;
		std::vector<int>	v2(10, 42);
		std::vector<int>	vcpy(v2);

		veq = vcpy;
		stdfs << "veq : ";
		print_std_vector(veq, stdfs);
		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		stdfs << "vcpy : ";
		print_std_vector(vcpy, stdfs);

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (creation) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	veq;
		ft::vector<int>	v2(10, 42);
		ft::vector<int>	vcpy(v2);

		veq = vcpy;
		ftfs << "veq : ";
		print_ft_vector(veq, ftfs);
		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		ftfs << "vcpy : ";
		print_ft_vector(vcpy, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;

	}
}
/*
void	test_vector_get_allocator(std::ofstream &ftfs, std::ofstream &stdfs);
*/
void	test_vector_at(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (at) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v.at(0) = 1;
		stdfs << "v.at(0) = 1;" << std::endl;
		v.at(1) = 234;
		stdfs << "v.at(1) = 234;" << std::endl;
		v.at(2) = -123;
		stdfs << "v.at(2) = -123;" << std::endl;
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (at) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v.at(0) = 1;
		ftfs << "v.at(0) = 1;" << std::endl;
		v.at(1) = 234;
		ftfs << "v.at(1) = 234;" << std::endl;
		v.at(2) = -123;
		ftfs << "v.at(2) = -123;" << std::endl;
		ftfs << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_operator_square_brackets(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (operator[]) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v[0] = 1;
		stdfs << "v[0] = 1;" << std::endl;
		v[1] = 234;
		stdfs << "v[1] = 234;" << std::endl;
		v[2] = -123;
		stdfs << "v[2] = -123;" << std::endl;
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (operator[]) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v[0] = 1;
		ftfs << "v[0] = 1;" << std::endl;
		v[1] = 234;
		ftfs << "v[1] = 234;" << std::endl;
		v[2] = -123;
		ftfs << "v[2] = -123;" << std::endl;
		ftfs << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_front(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (front) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v.front() = 1;
		stdfs << "v.front() = 1;" << std::endl;
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (front) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v.front() = 1;
		ftfs << "v.front() = 1;" << std::endl;
		ftfs << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_back(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (back) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v.back() = 1;
		stdfs << "v.back() = 1;" << std::endl;
		stdfs << "v : ";
		print_std_vector(v, stdfs);

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (back) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v.back() = 1;
		ftfs << "v.back() = 1;" << std::endl;
		ftfs << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_data(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (data) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.data() : " << v.data() << std::endl;
		stdfs << "*v.data() : " << *v.data() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (data) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.data() : " << v.data() << std::endl;
		ftfs << "*v.data() : " << *v.data() << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_empty(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (empty) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);
		std::vector<int>	empty;

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "empty : ";
		print_std_vector(empty, stdfs);
		stdfs << "v.empty() : " << v.empty() << std::endl;
		stdfs << "empty.empty() : " << empty.empty() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (empty) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);
		ft::vector<int>	empty;

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "empty : ";
		print_ft_vector(empty, ftfs);
		ftfs << "v.empty() : " << v.empty() << std::endl;
		ftfs << "empty.empty() : " << empty.empty() << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_max_size(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (max_size) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.max_size() : " << v.max_size() << std::endl;

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (max_size) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.max_size() : " << v.max_size() << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_capacity(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (capacity) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.capacity() : " << v.capacity() << std::endl;

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
//	ftfs << BOLD << CYAN << "========== ft::vector (capacity) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.capacity() : " << v.capacity() << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_size(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (size) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);
		std::vector<int>	v2;

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		stdfs << "v.size() : " << v.size() << std::endl;
		stdfs << "v2.size() : " << v2.size() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (size) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);
		ft::vector<int>	v2;

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		ftfs << "v.size() : " << v.size() << std::endl;
		ftfs << "v2.size() : " << v2.size() << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_clear(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (clear) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.clear()";
		v.clear();
		stdfs << std::endl << "v : ";
		print_std_vector(v, stdfs);

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (clear) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.clear()";
		v.clear();
		ftfs << std::endl << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}
 
void	test_vector_assign(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (assign) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);
		std::vector<int>	v2(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.assign(9, 41);" << std::endl;
		v.assign(9, 41);
		stdfs << "v : ";
		print_std_vector(v, stdfs);

		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		stdfs << "v2.assign(9, 41);" << std::endl;
		v2.assign(11, 41);
		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (assign) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);
		ft::vector<int>	v2(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.assign(9, 41);" << std::endl;
		v.assign(9, 41);
		ftfs << "v : ";
		print_ft_vector(v, ftfs);

		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		ftfs << "v2.assign(9, 41);" << std::endl;
		v2.assign(11, 41);
		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_iterator(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (iterator) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>			v(10, 42);
		std::vector<int>::iterator	it	= v.begin();
		std::vector<int>::iterator	ite	= v.end();

		++it;
		it++;
		it--;
		--it;
		stdfs << "v : ";
		while (it != ite)
		{
			stdfs << *it << " ";
			it++;
		}
		stdfs << std::endl;

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (iterator) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>				v(10, 42);
		ft::vector<int>::iterator	it	= v.begin();
		ft::vector<int>::iterator	ite	= v.end();

		++it;
		it++;
		it--;
		--it;
		ftfs << "v : ";
		while (it != ite)
		{
			ftfs << *it << " ";
			it++;
		}
		ftfs << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_reverse_iterator(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (reverse_iterator) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>					v(10, 42);
		std::vector<int>::reverse_iterator	it	= v.rbegin();
		std::vector<int>::reverse_iterator	ite	= v.rend();

		++it;
		it++;
		it--;
		--it;
		stdfs << "v : ";
		while (it != ite)
		{
			stdfs << *it << " ";
			it++;
		}
		stdfs << std::endl;

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (reverse_iterator) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>						v(10, 42);
		ft::vector<int>::reverse_iterator	it	= v.rbegin();
		ft::vector<int>::reverse_iterator	ite	= v.rend();

		++it;
		it++;
		it--;
		--it;
		ftfs << "v : ";
		while (it != ite)
		{
			ftfs << *it << " ";
			it++;
		}
		ftfs << std::endl;

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_reserve(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (reserve) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v.reserve(1)" << std::endl;
		v.reserve(1);
		stdfs << "v.reserve(123)" << std::endl;
		v.reserve(123);
		stdfs << std::endl << "v : ";
		print_std_vector(v, stdfs);

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (reserve) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v.reserve(1)" << std::endl;
		v.reserve(1);
		ftfs << "v.reserve(123)" << std::endl;
		v.reserve(123);
		ftfs << std::endl << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_push_back(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (push_back) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v;

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v.push_back(1);
		stdfs << "v.push_back(1);" << std::endl;
		v.push_back(2);
		stdfs << "v.push_back(2);" << std::endl;
		v.push_back(3);
		stdfs << "v.push_back(3);" << std::endl;
		v.push_back(4);
		stdfs << "v.push_back(4);" << std::endl;
		v.push_back(5);
		stdfs << "v.push_back(5);" << std::endl;
		for (size_t i = 0; i < 100000; ++i)
		{
			v.push_back(i);
			stdfs << "v.push_back(" << i << ");" << std::endl;
		}
		stdfs << std::endl << "v : ";
		print_std_vector(v, stdfs);

		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (reserve) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v;

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v.push_back(1);
		ftfs << "v.push_back(1);" << std::endl;
		v.push_back(2);
		ftfs << "v.push_back(2);" << std::endl;
		v.push_back(3);
		ftfs << "v.push_back(3);" << std::endl;
		v.push_back(4);
		ftfs << "v.push_back(4);" << std::endl;
		v.push_back(5);
		ftfs << "v.push_back(5);" << std::endl;
		for (size_t i = 0; i < 100000; ++i)
		{
			v.push_back(i);
			ftfs << "v.push_back(" << i << ");" << std::endl;
		}
		ftfs << std::endl << "v : ";
		print_ft_vector(v, ftfs);

		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_pop_back(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (pop_back) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v;

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		for (size_t i = 0; i < 1000; ++i)
			v.push_back(i);
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		for (size_t i = 0; i < 1000; ++i)
			v.pop_back();
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (reserve) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v;

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		for (size_t i = 0; i < 1000; ++i)
			v.push_back(i);
		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		for (size_t i = 0; i < 1000; ++i)
			v.pop_back();
		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

void	test_vector_insert(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (insert) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>			v;
		std::vector<int>::iterator	pos;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.reserve(6);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		v.insert(v.end(), 42);
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		pos = v.begin();
		v.insert(pos, -42);
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (reserve) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>				v;
		ft::vector<int>::iterator	pos;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.reserve(6);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		v.insert(v.end(), 42);
		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		pos = v.begin();
		v.insert(pos, -42);
		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}
 
void	test_vector_swap(std::ofstream &ftfs, std::ofstream &stdfs)
{
	size_t	stdms;
	stdfs << BOLD << CYAN << "========== std::vector (swap) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		std::vector<int>	v(10, 42);
		std::vector<int>	v2(10, -42);

		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		stdfs << "v.swap(v2);" << std::endl;
		v.swap(v2);
		stdfs << "v : ";
		print_std_vector(v, stdfs);
		stdfs << "v2 : ";
		print_std_vector(v2, stdfs);
		
		clock_t	end = clock();
		stdms = end - start;
		stdfs << YELLOW << "std::vector took : " << stdms << "us." << RESET << std::endl;
	}
	//ftfs << BOLD << CYAN << "========== ft::vector (assign) =========" << RESET << std::endl;
	{
		clock_t	start = clock();

		ft::vector<int>	v(10, 42);
		ft::vector<int>	v2(10, -42);

		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		ftfs << "v.swap(v2);" << std::endl;
		v.swap(v2);
		ftfs << "v : ";
		print_ft_vector(v, ftfs);
		ftfs << "v2 : ";
		print_ft_vector(v2, ftfs);
		
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			ftfs << LIGHTRED;
		else
			ftfs << LIGHTGREEN;
		ftfs << "ft::vector took " << ftms << "us." << RESET << std::endl;
	}
}

/*
void	test_vector_insert(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_erase(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_resize(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_swap(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_comparisons(std::ofstream &ftfs, std::ofstream &stdfs);
*/
