/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:36:13 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/11/04 16:41:38 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        std::stack<int> numbers;
        std::string token;
        std::string input(argv[1]);
        std::istringstream iss(input);
        while (iss >> token)
        {
            if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1])))
            {
                int num;
                std::istringstream(token) >> num;
                numbers.push(num);
            }
            else
            {
                if (numbers.size() < 2)
                {
                    std::cout << "Error" << std::endl;
                    return (1);
                }
                int x2 = numbers.top();
                numbers.pop();
                int x1 = numbers.top();
                numbers.pop();

                if (token == "+")
                {
                    numbers.push(x1 + x2);
                }
                else if (token == "-")
                {
                    numbers.push(x1 - x2);
                }
                else if (token == "*")
                {
                    numbers.push(x1 * x2);
                }
                else if (token == "/")
                {
                    if (x2 == 0)
                    {
                        std::cerr << "Division by zero is not allowed." << std::endl;
                        return (1);
                    }
                    numbers.push(x1 / x2);
                }
                else
                {
                    std::cerr << "Invalid operation: " << token << std::endl;
                    return (1);
                }
            }
        }

        if (numbers.size() != 1)
        {
            std::cerr << "Invalid RPN expression. More than one result." << std::endl;
            return (1);
        }

        int result = numbers.top();
        std::cout << result << std::endl;
    }
    return 0;
}
