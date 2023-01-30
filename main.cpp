/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:22:05 by afaby             #+#    #+#             */
/*   Updated: 2023/01/30 17:00:03 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"header.hpp"
#define		STACK 0
#define		VECTOR 1


int	main(void)
{
	std::ofstream	ft_fs; 
	std::ofstream	std_fs; 
	
	ft_fs.open("ft_tests");
	std_fs.open("std_tests");
	if (STACK)
	{
		test_stack_creation();
		test_stack_top();
		test_stack_empty();
		test_stack_size();
		test_stack_push();
		test_stack_pop();
		test_stack_comparisons();
	}
	if (VECTOR)
	{
		test_vector_creation(ft_fs, std_fs);
	//	test_vector_get_allocator(ft_fs, std_fs);
		test_vector_at(ft_fs, std_fs);
		test_vector_operator_square_brackets(ft_fs, std_fs);
		test_vector_front(ft_fs, std_fs);
		test_vector_back(ft_fs, std_fs);
		test_vector_data(ft_fs, std_fs);
		test_vector_empty(ft_fs, std_fs);
		test_vector_max_size(ft_fs, std_fs);
		test_vector_capacity(ft_fs, std_fs);
		test_vector_size(ft_fs, std_fs);
		test_vector_clear(ft_fs, std_fs);
		test_vector_assign(ft_fs, std_fs);
		test_vector_iterator(ft_fs, std_fs);
		test_vector_reverse_iterator(ft_fs, std_fs);
		test_vector_reserve(ft_fs, std_fs);
	//	test_vector_erase(ft_fs, std_fs);
		test_vector_push_back(ft_fs, std_fs);
		test_vector_pop_back(ft_fs, std_fs);
		test_vector_insert(ft_fs, std_fs);
	//	test_vector_resize(ft_fs, std_fs);
	//	test_vector_swap(ft_fs, std_fs);
	//	test_vector_comparisons(ft_fs, std_fs);

	}
	ft_fs.close();
	std_fs.close();
	return (0);
}
