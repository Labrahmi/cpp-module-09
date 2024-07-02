/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeTool.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:42:24 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/31 07:44:28 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

int check_err(std::string &string)
{
	int i = 0;
	int f_count = 0;
	int dot_count = 0;
	int strange_count = 0;
	int gen_err = 0;
	while (string[i])
	{
		if (string[i] == 'f')
			f_count++;
		if (string[i] == '.')
			dot_count++;
		if (((string[i] >= '0' && string[i] <= '9') == 0) && string[i] != '.' && string[i] != 'f')
			strange_count++;
		i++;
	}
	gen_err = (string[i - 1]) && (string[i - 1] == '.');
	return ((strange_count > 0) || (f_count > 1) || (dot_count > 1) || (gen_err));
}

literal_type setLetType(std::string &string)
{
	size_t pos;
	char sign = 'p';
	if (string.length() == 1)
	{
		if (string[0] >= '0' && string[0] <= '9')
			return e_INT;
		return e_CHAR;
	}
	else if (string.length() > 1)
	{
		if (string[0] == '-' || string[0] == '+')
		{
			if (string.length() == 1)
				return e_ERR;
			if (string[0] == '-')
				sign = 'n';
			string = string.substr(1, (string.length() - 1));
		}
		if (check_err(string))
			return e_ERR;
		if (string.find(".") == std::string::npos)
		{
			if (string.find("f") != std::string::npos)
				return e_ERR;
			return e_INT;
		}
		else
		{
			pos = string.find("f");
			if (pos == std::string::npos)
			{
				if (string[0] == '.')
					return e_ERR;
				return e_DOUBLE;
			}
			else
			{
				if (string[pos - 1] && string[pos - 1] == '.')
					return e_ERR;
				return e_FLOAT;
			}
		}
	}
	return e_ERR;
}
