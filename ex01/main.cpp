/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:36:13 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/11/05 10:13:28 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

void ft_err()
{
    std::cout << "Error" << std::endl;
    exit(1);
}

void rpn_op(std::stack<int> &numbers, std::string &token)
{
    int x1, x2;
    if (numbers.size() < 2)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    x2 = numbers.top();
    numbers.pop();
    x1 = numbers.top();
    numbers.pop();
    if (token == "+")
        numbers.push(x1 + x2);
    else if (token == "-")
        numbers.push(x1 - x2);
    else if (token == "*")
        numbers.push(x1 * x2);
    else if (token == "/")
    {
        if (x2 == 0)
            ft_err();
        numbers.push(x1 / x2);
    }
    else
        ft_err();
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        std::stack<int> numbers;
        std::string token;
        std::istringstream iss(argv[1]);
        int num = 0;
        while (iss >> token)
        {
            if (token.length() != 1)
                ft_err();
            else
            {
                if (isdigit(token[0]))
                {
                    std::istringstream(token) >> num;
                    numbers.push(num);
                }
                else
                    rpn_op(numbers, token);
            }
        }
        if (numbers.size() != 1)
            ft_err();
        std::cout << numbers.top() << std::endl;
    }
    return 0;
}
