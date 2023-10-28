/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:36:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/28 01:54:04 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

void ft_error(std::string message)
{
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}

bool splitDateAndValue(const std::string &line, std::string &date, std::string &value)
{
    std::stringstream stream(line);
    if (std::getline(stream, date, '|'))
    {
        date = date.substr(0, date.find_last_not_of(' ') + 1);
        if (std::getline(stream, value))
        {
            value = value.substr(value.find_first_not_of(' '));
            return true;
        }
    }
    return false;
}

intMap getInputData(std::ifstream &file)
{
    // ====================================================
    intMap map;
    int intValue;
    std::string fline, line;
    std::string date, value;

    std::getline(file, fline);
    if (fline != "date | value")
        ft_error("Wrong header for input file.");
    // ====================================================
    while (std::getline(file, line))
    {
        if (splitDateAndValue(line, date, value))
        {
            std::stringstream valueStream(value);
            if (valueStream >> intValue)
            {
                // std::cout << date << " <> " << intValue << std::endl;
                // map.insert(std::);
                // map.insert(std::pair<int, std::string>(1, "Hey"));
                // map[date] = intValue;
            }
            else
            {
                std::cout << "Error: " << std::endl;
            }
            // map[date] = 1;
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    // ====================================================
    return map;
}

int main(int ac, char **av)
{
    // ====================================================
    std::ifstream file(av[1]);
    intMap inpData;
    // ====================================================
    if (ac == 1)
        ft_error("Could not open file.");
    if (!file.is_open())
        ft_error("Could not open file.");
    // ====================================================
    inpData = getInputData(file);
    intMap::iterator it = inpData.begin();
    while (it != inpData.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    file.close();
    // ====================================================
}

// $> ./btc
// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>