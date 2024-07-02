/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:38:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/31 07:45:42 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STL
#include <algorithm>
#include <iterator>
#include <map>
#include <set>

// Enums
typedef enum
{
	e_CHAR = 'c',
	e_INT = 'i',
	e_FLOAT = 'f',
	e_DOUBLE = 'd',
	e_ERR = 'e',
} literal_type;

// IO
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Function prototype
void ft_error(std::string message);
void calculateInput(std::ifstream &file, std::map<std::string, float> &inpData);
std::map<std::string, float> getData(void);
literal_type setLetType(std::string &string);
