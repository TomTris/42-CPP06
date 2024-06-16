/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:49:24 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 21:49:38 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

bool	isChar(std::string const &str_o)
{
	// std::cout << "Char" << std::endl;
	std::string::iterator iter;
	std::string str = (std::string) str_o;

	if (str.size() == 1)
	{
		iter = str.begin();
		if (isprint(*iter))
			std::cerr << "char: " << *iter << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
		std::cerr << "int: " << static_cast<int>(*iter) << std::endl;
		std::cerr << "float: " << static_cast<float>(*iter) << ".0f" << std::endl;
		std::cerr << "double: " << static_cast<double>(*iter) << ".0" << std::endl;
		return (true);
	}
	return (false);
}

int	convertInt(std::string str)
{
	std::stringstream ss(str);
	int	ret;

	ss >> ret;
	return (ret);
}

bool	isInt(std::string const &str_o)
{
	// std::cout << "Int" << std::endl;
	std::string str = (std::string) str_o;
	std::string::iterator iter;
	
	iter = str.begin();
	if (*iter == '+' || *iter == '-')
		iter++;
	while (iter != str.end())
	{
		if (*iter > '9' || *iter < '0')
			return (false);
		iter++;
	}
	int nbr = convertInt(str);
	if (isprint(nbr))
		std::cerr << "char: " << static_cast<char>(nbr) << std::endl;
	else
	{
		if (nbr < 0 || nbr > 255)
			std::cerr << "char: impossible - because of overflow" << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
	}
	std::cerr << "int: " << nbr << std::endl;
	std::cerr << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
	std::cerr << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	return (true);
}


float	convertFloat(std::string str)
{
	std::stringstream ss(str);
	float nbr;

	ss >> nbr;
	return (nbr);
}

int	addDotCheck(std::string str)
{
	std::string::iterator iter;
	std::string::iterator iter2;

	if (str.find(".") == std::string::npos)
		return (1);
	iter = str.begin();
	iter += str.find(".") + 1;
	// std::cout << ":: " << *iter << std::endl;
	iter2 = str.end() - 1;
	if (*iter2 == 'f')
	{
		while (iter != str.end() -1)
		{
			if (*iter != '0')
				return (0);
			iter++;
		}
		return (1);
	}
	while (iter != str.end())
	{
		while (iter != str.end())
		{
			if (*iter != '0')
				return (0);
			iter++;
		}
		return (1);
	}
	return (1);
}

bool	isFloat(std::string const &str_o)
{
	// std::cout << "Float" << std::endl;
	std::string str = (std::string) str_o;
	int		cnt = 0;
	int	add_dot = 0;

	add_dot = addDotCheck(str);
	std::string::iterator iter = str.end() - 1;
	if (*iter != 'f')
		return (false);
	iter = str.begin();
	if (*iter == '+' || *iter == '-')
		iter++;
	if (str_o.size() == 2 && add_dot == 1 && (*(iter - 1) == '+' || *(iter - 1) == '-'))
		return (false);
	iter = str.begin();
	if (*iter == '+' || *iter == '-')
		iter++;
	while (iter != str.end() - 1)
	{
		if (*iter == '.')
			cnt++;
		if (cnt >= 2)
			return (false);
		if (*iter != '.' && (*iter > '9' || *iter < '0'))
			return (false);
		iter++;
	}
	if (cnt == 0)
		return (false);
	str = str.substr(0, str.find("f"));
	float nbr = convertFloat(str);
	if (isprint(static_cast<int>(nbr)))
		std::cerr << "char: " << static_cast<char>(static_cast<int>(nbr)) << std::endl;
	else
		std::cerr << "char: " << "Non displayable" << std::endl;
	std::cerr << "int: " << static_cast<int>(nbr) << std::endl;
	if (add_dot == 1)
	{
		std::cerr << "float: " << nbr << ".0f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	}
	else
	{
		std::cerr << "float: " << nbr << "f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << std::endl;
	}
	return (true);
}

double	convertDouble(std::string str)
{
	std::stringstream ss(str);
	double num;

	ss >> num;
	return (num);
}

bool	isDouble(std::string const &str_o)
{
	// std::cout << "Double" << std::endl;
	std::string str = (std::string) str_o;
	int	cnt = 0;
	int	add_dot = 0;

	add_dot = addDotCheck(str);
	std::string::iterator iter;
	iter = str.end() - 1;
	iter = str.begin();
	if (*iter == '+' || *iter == '-')
		iter++;
	if (str_o.size() == 2 && add_dot == 1 && (*(iter - 1) == '+' || *(iter - 1) == '-'))
		return (false);
	while (iter != str.end())
	{
		if (*iter == '.')
			cnt++;
		if (cnt >= 2)
			return (false);
		if (*iter != '.' && (*iter > '9' || *iter < '0'))
			return (false);
		iter++;
	}
	if (iter != str.end())
		return (false);
	double nbr = convertDouble(str);
	if (isprint(nbr))
		std::cerr << "char: " << static_cast<char>(nbr) << std::endl;
	else
		std::cerr << "char: " << "Non displayable" << std::endl;
	std::cerr << "int: " << static_cast<int>(nbr) << std::endl;
	if (add_dot == 1)
	{
		std::cerr << "float: " << nbr << ".0f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	}
	else
	{
		std::cerr << "float: " << nbr << "f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << std::endl;
	}
	return (true);
}

bool	isPseudo(std::string const &str_o)
{
	std::string const str[6] = {"-inff", "+inff", "-inff", "+inf", "nan", "nanf"};
	std::string str2 = (std::string) str_o;
	std::string::iterator iter;
	iter = str2.begin();

	for (int i = 0; i < 6; i++)
	{
		if (str[i] == str_o)
		{
			std::cerr << "char: " << "impossible" << std::endl;
			if (*iter == '-' || *iter == '+')
			{
				std::cerr << "int :" << str[i].substr(0, str[i].find("f") + 1) << std::endl;
				std::cerr << "float: " << str[i].substr(0, 4) << std::endl;
				std::cerr << "double: " << str[i].substr(0, 3) << std::endl;
			}
			else
			{
				std::cerr << "int: " << "impossible" << std::endl;
				std::cerr << "float: " << str[i].substr(0, 4) << "f" << std::endl;
				std::cerr << "double: " << str[i].substr(0, 4) << std::endl;
			}
			return (true);
		}
	}
	return (false);
}

void ScalarConverter::convert(std::string const & literal)
{
	(void) literal;
	bool	(*isFunc[5])(std::string const &) = {isInt, isChar, isDouble, isFloat, isPseudo};

	for (int i = 0; i < 5; i++)
	{
		if (isFunc[i](literal) == true)
			return ;
	}
	std::cerr << "Can't regconized" << std::endl;
}



ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void) src;
}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void)src;
	return *this;
}