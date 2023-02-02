/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:14:50 by afaby             #+#    #+#             */
/*   Updated: 2023/01/23 12:23:10 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include <stack>
#include "stack.hpp"

/*
void	test_stack_creation(void)
{
	std::cout << BOLD << CYAN << "========== std::stack ==========" << RESET << std::endl;
	{
		std::stack<int>			si;
		std::stack<std::string>	ss;
	}
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== ft::stack ==========" << RESET << std::endl;
	{
		ft::stack<int>			si;
		ft::stack<std::string>	ss;
	}
}
*/


template <typename T>
void	print_std_stack(std::stack< T >& s)
{
	std::vector<T>	v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	typename std::vector<T>::reverse_iterator	it = v.rbegin();
	typename std::vector<T>::reverse_iterator	ite = v.rend();
	while (it != ite)
	{
		std::cout << *it << " ";
		s.push(*it);
		++it;
	}
	std::cout << std::endl;
	
}

template <typename T>
void	print_ft_stack(ft::stack< T >& s)
{
	std::vector<T>	v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	typename std::vector<T>::reverse_iterator	it = v.rbegin();
	typename std::vector<T>::reverse_iterator	ite = v.rend();
	while (it != ite)
	{
		std::cout << *it << " ";
		s.push(*it);
		++it;
	}
	std::cout << std::endl;
	
}

void	test_stack_creation(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (creation) =========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>										si;
		std::stack<std::string>								ss;
	//	std::stack< int, std::deque<int> >					scnti(std::deque<int>);
	//	std::stack< std::string, std::deque<std::string> >	scnsi(std::deque<std::string>);
		
		si.push(1);
		si.push(2);
	//	scnti.push(1);
	//	scnti.push(2);
		ss.push("1");
		ss.push("2");
	//	scnts.push("1");
	//	scnts.push("2");

		std::stack<int>			scpyi(si);
		std::stack<std::string>	scpys(ss);
		std::stack<int>			seqi;
		std::stack<std::string>	seqs;

		seqi = scpyi;
		seqs = ss;	
		std::cout << "Default constructor stack(int) : ";
		print_std_stack(si);
	//	std::cout << "Constructor with container in param(int) :";
	//	print_std_stack(scnti);
		std::cout << "Copy constructor stack(int) : ";
		print_std_stack(scpyi);
		std::cout << "Operator= stack(int) : ";
		print_std_stack(seqi);
		std::cout << "Default constructor stack(std::string) : ";
		print_std_stack(ss);
	//	std::cout << "Constructor with container in param(std::string) :";
	//	print_std_stack(scnts);
		std::cout << "Copy constructor stack(std::string) : ";
		print_std_stack(scpys);
		std::cout << "Operator= stack(std::string) : ";
		print_std_stack(seqs);
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;
		
	}
	std::cout << BOLD << CYAN << "========== ft::stack (creation )==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;
		
		si.push(1);
		si.push(2);
		ss.push("1");
		ss.push("2");

		ft::stack<int>			scpyi(si);
		ft::stack<std::string>	scpys(ss);
		ft::stack<int>			seqi;
		ft::stack<std::string>	seqs;

		seqi = scpyi;
		seqs = ss;	
		std::cout << "Default constructor stack(int) : ";
		print_ft_stack(si);
		std::cout << "Copy constructor stack(int) : ";
		print_ft_stack(scpyi);
		std::cout << "Operator= stack(int) : ";
		print_ft_stack(seqi);
		std::cout << "Default constructor stack(std::string) : ";
		print_ft_stack(ss);
		std::cout << "Copy constructor stack(std::string) : ";
		print_ft_stack(scpys);
		std::cout << "Operator= stack(std::string) : ";
		print_ft_stack(seqs);
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_top(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (top method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si;
		std::stack<std::string>	ss;

		//std::cout << "(int) stack.top() : " << si.top();
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.top() {1, 2, 3} : " << si.top() << std::endl;
		//std::cout << "(std::string) stack.top() : " << ss.top();
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.top() {\"1\", \"2\", \"3\"} : " << ss.top() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;
	}
	std::cout << BOLD << CYAN << "========== ft::stack (top method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;

		//std::cout << "(int) stack.top() : " << si.top();
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.top() {1, 2, 3} : " << si.top() << std::endl;

		//std::cout << "(std::string) stack.top() : " << ss.top();
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.top() {\"1\", \"2\", \"3\"} : " << ss.top() << std::endl;
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_empty(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (empty method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si;
		std::stack<std::string>	ss;

		std::cout << "(int) stack.empty() {} : " << si.empty() << std::endl;
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.empty() {1, 2, 3} : " << si.empty() << std::endl;
		std::cout << "(std::string) stack.empty() {} : " << ss.empty() << std::endl;
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.empty() {\"1\", \"2\", \"3\"} : " << ss.empty() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;

	}
	std::cout << BOLD << CYAN << "========== ft::stack (empty method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;

		std::cout << "(int) stack.empty() {} : " << si.empty() << std::endl;
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.empty() {1, 2, 3} : " << si.empty() << std::endl;

		std::cout << "(std::string) stack.empty() {} : " << ss.empty() << std::endl;
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.empty() {\"1\", \"2\", \"3\"} : " << ss.empty() << std::endl;
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_size(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (size method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si;
		std::stack<std::string>	ss;

		std::cout << "(int) stack.size() {} : " << si.size() << std::endl;
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.size() {1, 2, 3} : " << si.size() << std::endl;
		std::cout << "(std::string) stack.size() {} : " << ss.size() << std::endl;
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.size() {\"1\", \"2\", \"3\"} : " << ss.size() << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;

	}
	std::cout << BOLD << CYAN << "========== ft::stack (size method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;

		std::cout << "(int) stack.size() {} : " << si.size() << std::endl;
		si.push(1);
		si.push(2);
		si.push(3);
		std::cout << "(int) stack.size() {1, 2, 3} : " << si.size() << std::endl;
		std::cout << "(std::string) stack.size() {} : " << ss.size() << std::endl;
		ss.push("1");
		ss.push("2");
		ss.push("3");
		std::cout << "(std::string) stack.size() {\"1\", \"2\", \"3\"} : " << ss.size() << std::endl;
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_push(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (push method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si;
		std::stack<std::string>	ss;

		std::cout << "(int) stack {} : ";
		print_std_stack(si);
		si.push(1);
		std::cout << "si.push(1)" << std::endl;
		si.push(2);
		std::cout << "si.push(2)" << std::endl;
		si.push(3);
		std::cout << "si.push(3)" << std::endl;
		std::cout << "(int) stack {1, 2, 3} : ";
		print_std_stack(si);
		std::cout << "(std::string) stack {} : ";
		print_std_stack(ss);
		ss.push("1");
		std::cout << "ss.push(\"1\")" << std::endl;
		ss.push("2");
		std::cout << "ss.push(\"2\")" << std::endl;
		ss.push("3");
		std::cout << "ss.push(\"3\")" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\", \"3\"} : ";
		print_std_stack(ss);
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;

	}
	std::cout << BOLD << CYAN << "========== ft::stack (push method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;

		std::cout << "(int) stack {} : ";
		print_ft_stack(si);
		si.push(1);
		std::cout << "si.push(1)" << std::endl;
		si.push(2);
		std::cout << "si.push(2)" << std::endl;
		si.push(3);
		std::cout << "si.push(3)" << std::endl;
		std::cout << "(int) stack {1, 2, 3} : ";
		print_ft_stack(si);
		std::cout << "(std::string) stack {} : ";
		print_ft_stack(ss);
		ss.push("1");
		std::cout << "ss.push(\"1\")" << std::endl;
		ss.push("2");
		std::cout << "ss.push(\"2\")" << std::endl;
		ss.push("3");
		std::cout << "ss.push(\"3\")" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\", \"3\"} : ";
		print_ft_stack(ss);
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_pop(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (pop method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si;
		std::stack<std::string>	ss;

		si.push(1);
		std::cout << "si.push(1)" << std::endl;
		si.push(2);
		std::cout << "si.push(2)" << std::endl;
		si.push(3);
		std::cout << "si.push(3)" << std::endl;
		std::cout << "(int) stack {1, 2, 3} : ";
		print_std_stack(si);
		si.pop();
		std::cout << "si.pop();" << std::endl;
		std::cout << "(int) stack {1, 2} : ";
		print_std_stack(si);

		ss.push("1");
		std::cout << "ss.push(\"1\")" << std::endl;
		ss.push("2");
		std::cout << "ss.push(\"2\")" << std::endl;
		ss.push("3");
		std::cout << "ss.push(\"3\")" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\", \"3\"} : ";
		print_std_stack(ss);
		ss.pop();
		std::cout << "ss.pop();" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\"} : ";
		print_std_stack(ss);
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;

	}
	std::cout << BOLD << CYAN << "========== ft::stack (pop method) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si;
		ft::stack<std::string>	ss;

		si.push(1);
		std::cout << "si.push(1)" << std::endl;
		si.push(2);
		std::cout << "si.push(2)" << std::endl;
		si.push(3);
		std::cout << "si.push(3)" << std::endl;
		std::cout << "(int) stack {1, 2, 3} : ";
		print_ft_stack(si);
		si.pop();
		std::cout << "si.pop();" << std::endl;
		std::cout << "(int) stack {1, 2} : ";
		print_ft_stack(si);

		ss.push("1");
		std::cout << "ss.push(\"1\")" << std::endl;
		ss.push("2");
		std::cout << "ss.push(\"2\")" << std::endl;
		ss.push("3");
		std::cout << "ss.push(\"3\")" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\", \"3\"} : ";
		print_ft_stack(ss);
		ss.pop();
		std::cout << "ss.pop();" << std::endl;
		std::cout << "(std::string) stack {\"1\", \"2\"} : ";
		print_ft_stack(ss);
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}

void	test_stack_comparisons(void)
{
	size_t	stdms;
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "========== std::stack (comparisons) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		std::stack<int>			si1;
		std::stack<int>			si2;
		std::stack<std::string>	ss1;
		std::stack<std::string>	ss2;

		si1.push(1);
		std::cout << "si1.push(1)" << std::endl;
		si1.push(2);
		std::cout << "si1.push(2)" << std::endl;
		si1.push(3);
		std::cout << "si1.push(3)" << std::endl;
		si2.push(1);
		std::cout << "si2.push(1)" << std::endl;
		si2.push(2);
		std::cout << "si2.push(2)" << std::endl;
		std::cout << "(int) si1 {1, 2, 3} : ";
		print_std_stack(si1);
		std::cout << "(int) si2 {1, 2} : ";
		print_std_stack(si2);

		ss1.push("1");
		std::cout << "ss1.push(\"1\")" << std::endl;
		ss1.push("2");
		std::cout << "ss1.push(\"2\")" << std::endl;
		ss1.push("3");
		std::cout << "ss1.push(\"3\")" << std::endl;
		ss2.push("1");
		std::cout << "ss2.push(\"1\")" << std::endl;
		ss2.push("2");
		std::cout << "ss2.push(\"2\")" << std::endl;
		std::cout << "(std::string) ss1 {\"1\", \"2\", \"3\"} : ";
		print_std_stack(ss1);
		std::cout << "(std::string) ss2 {\"1\", \"2\"} : ";
		print_std_stack(ss2);

		std::cout << "ss1 == ss2 : " << (ss1 == ss2) << std::endl;
		std::cout << "ss2 == ss1 : " << (ss2 == ss1) << std::endl;
		std::cout << "ss1 != ss2 : " << (ss1 != ss2) << std::endl;
		std::cout << "ss2 != ss1 : " << (ss2 != ss1) << std::endl;
		std::cout << "ss1 < ss2 : " << (ss1 < ss2) << std::endl;
		std::cout << "ss2 < ss1 : " << (ss2 < ss1) << std::endl;
		std::cout << "ss1 <= ss2 : " << (ss1 <= ss2) << std::endl;
		std::cout << "ss2 <= ss1 : " << (ss2 <= ss1) << std::endl;
		std::cout << "ss1 > ss2 : " << (ss1 > ss2) << std::endl;
		std::cout << "ss2 > ss1 : " << (ss2 > ss1) << std::endl;
		std::cout << "ss1 >= ss2 : " << (ss1 >= ss2) << std::endl;
		std::cout << "ss2 >= ss1 : " << (ss2 >= ss1) << std::endl;
		clock_t	end = clock();
		stdms = end - start;
		std::cout << YELLOW << "std::stack took : " << stdms << "us." << RESET << std::endl;

	}
	std::cout << BOLD << CYAN << "========== ft::stack (comparisons) ==========" << RESET << std::endl;
	{
		clock_t	start = clock();
		ft::stack<int>			si1;
		ft::stack<int>			si2;
		ft::stack<std::string>	ss1;
		ft::stack<std::string>	ss2;

		si1.push(1);
		std::cout << "si1.push(1)" << std::endl;
		si1.push(2);
		std::cout << "si1.push(2)" << std::endl;
		si1.push(3);
		std::cout << "si1.push(3)" << std::endl;
		si2.push(1);
		std::cout << "si2.push(1)" << std::endl;
		si2.push(2);
		std::cout << "si2.push(2)" << std::endl;
		std::cout << "(int) si1 {1, 2, 3} : ";
		print_ft_stack(si1);
		std::cout << "(int) si2 {1, 2} : ";
		print_ft_stack(si2);

		ss1.push("1");
		std::cout << "ss1.push(\"1\")" << std::endl;
		ss1.push("2");
		std::cout << "ss1.push(\"2\")" << std::endl;
		ss1.push("3");
		std::cout << "ss1.push(\"3\")" << std::endl;
		ss2.push("1");
		std::cout << "ss2.push(\"1\")" << std::endl;
		ss2.push("2");
		std::cout << "ss2.push(\"2\")" << std::endl;
		std::cout << "(std::string) ss1 {\"1\", \"2\", \"3\"} : ";
		print_ft_stack(ss1);
		std::cout << "(std::string) ss2 {\"1\", \"2\"} : ";
		print_ft_stack(ss2);

		std::cout << "ss1 == ss2 : " << (ss1 == ss2) << std::endl;
		std::cout << "ss2 == ss1 : " << (ss2 == ss1) << std::endl;
		std::cout << "ss1 != ss2 : " << (ss1 != ss2) << std::endl;
		std::cout << "ss2 != ss1 : " << (ss2 != ss1) << std::endl;
		std::cout << "ss1 < ss2 : " << (ss1 < ss2) << std::endl;
		std::cout << "ss2 < ss1 : " << (ss2 < ss1) << std::endl;
		std::cout << "ss1 <= ss2 : " << (ss1 <= ss2) << std::endl;
		std::cout << "ss2 <= ss1 : " << (ss2 <= ss1) << std::endl;
		std::cout << "ss1 > ss2 : " << (ss1 > ss2) << std::endl;
		std::cout << "ss2 > ss1 : " << (ss2 > ss1) << std::endl;
		std::cout << "ss1 >= ss2 : " << (ss1 >= ss2) << std::endl;
		std::cout << "ss2 >= ss1 : " << (ss2 >= ss1) << std::endl;
		clock_t	end = clock();
		size_t	ftms = end - start;
		if (ftms > 20 * stdms)
			std::cout << LIGHTRED;
		else
			std::cout << LIGHTGREEN;
		std::cout << "ft::stack took " << ftms << "us." << std::endl;
	}
}
