/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:13:52 by afaby             #+#    #+#             */
/*   Updated: 2023/01/26 15:17:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET			"\e[0m"

#define DEFAULT			"\e[39m"
#define BLACK			"\e[30m"
#define RED				"\e[31m"
#define GREEN			"\e[32m"
#define YELLOW			"\e[33m"
#define BLUE			"\e[34m"
#define MAGENTA			"\e[35m"
#define CYAN			"\e[36m"
#define LIGHTGRAY		"\e[37m"
#define DARKGRAY		"\e[90m"
#define LIGHTRED		"\e[91m"
#define LIGHTGREEN		"\e[92m"
#define LIGHTYELLOW		"\e[93m"
#define LIGHTBLUE		"\e[94m"
#define LIGHTMAGENTA	"\e[95m"
#define LIGHTCYAN		"\e[96m"
#define WHITE			"\e[97m"

#define BOLD			"\e[1m"
#define DIM				"\e[2m"
#define UNDERLINED		"\e[4m"
#define BLINK			"\e[5m"
#define REVERSE			"\e[7m"
#define HIDDEN			"\e[8m"

#include <iostream>
#include <ctime>
#include <fstream>

// STACK TESTING
void	test_stack_creation(void);
void	test_stack_top(void);
void	test_stack_empty(void);
void	test_stack_size(void);
void	test_stack_push(void);
void	test_stack_pop(void);
void	test_stack_comparisons(void);

// VECTOR TESTING
void	test_vector_creation(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_get_allocator(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_at(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_operator_square_brackets(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_front(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_back(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_assign(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_data(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_iterator(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_reverse_iterator(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_empty(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_size(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_max_size(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_reserve(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_capacity(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_clear(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_insert(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_erase(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_push_back(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_pop_back(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_resize(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_swap(std::ofstream &ftfs, std::ofstream &stdfs);
void	test_vector_comparisons(std::ofstream &ftfs, std::ofstream &stdfs);
