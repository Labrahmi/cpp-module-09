/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:38:49 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/30 15:53:21 by ylabrahm         ###   ########.fr       */
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

// Function prototype
void ft_error(std::string message);
void calculateInput(std::ifstream &file, std::map<std::string, float> &inpData);
std::map<std::string, float> getData(void);
