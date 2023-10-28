/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:38:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/27 21:58:31 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STL
#include <algorithm>
#include <iterator>
#include <map>
#include <set>

// IO
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Alias
typedef std::multimap<std::string, float> intMap;

// Function prototype
void ft_error(std::string message);
intMap getInputData(std::ifstream &file);
