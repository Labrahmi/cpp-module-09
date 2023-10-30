/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:36:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/30 16:17:42 by ylabrahm         ###   ########.fr       */
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
            return (true);
        }
    }
    return (false);
}

void calculateInput(std::ifstream &file, std::map<std::string, float> &inpData)
{
    // ====================================================
    float f_value = 0;
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
            if (valueStream >> f_value)
            {
                if (f_value < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (f_value > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else
                {
                    std::map<std::string, float>::iterator it = inpData.lower_bound(date);
                    if (it == inpData.end() || it->first != date)
                    {
                        if (it != inpData.begin())
                            --it;
                        else
                            it = inpData.begin();
                    }

                    std::cout << date << " => " << f_value << " = " << (it->second * f_value) << std::endl;
                }
            }
            else
            {
                std::cout << "Error: too large a number." << std::endl;
            }
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    // ====================================================
}

std::map<std::string, float> getData(void)
{
    std::string line;
    std::map<std::string, float> dataMap;
    std::ifstream dataFile("data/data.csv");
    float btcValue = 0;
    // ====================================================
    if (!dataFile.is_open())
        ft_error("Could not open data file.");
    std::getline(dataFile, line);
    while (std::getline(dataFile, line))
    {
        int st = (line.length() - 11);
        std::stringstream btcValueStream(line.substr(11, st));
        btcValueStream >> btcValue;
        dataMap[line.substr(0, 10)] = btcValue;
    }
    // ====================================================
    return dataMap;
    // ====================================================
}

int main(int ac, char **av)
{
    // ====================================================
    std::ifstream file(av[1]);
    std::map<std::string, float> inpData;
    // ====================================================
    if (ac == 1)
        ft_error("Could not open file.");
    if (!file.is_open())
        ft_error("Could not open file.");
    // ====================================================
    inpData = getData();
    std::map<std::string, float>::iterator it = inpData.begin();
    // while (it != inpData.end())
    // {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    //     ++it;
    // }
    calculateInput(file, inpData);
    file.close();
    // ====================================================
}

