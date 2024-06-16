/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:49:24 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 18:58:43 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

bool	isChar(std::string const &str_o)
{
	std::string::iterator iter;
	std::string str = (std::string) str_o;
	bool check = false;

	iter = str.begin();
	if (str.size() == 1)
	{
		check = true;
		if (isprint(*iter))
			std::cerr << "char: " << *iter << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
		std::cerr << "int: " << static_cast<int>(*iter) << std::endl;
		std::cerr << "float: " << static_cast<float>(*iter) << ".0f" << std::endl;
		std::cerr << "double: " << static_cast<double>(*iter) << ".0" << std::endl;
	}
	return (check);
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
	std::string str = (std::string) str_o;
	bool	check = true;

	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter > '9' || *iter < '0')
		{
			check = false;
			break ;
		}
	}
	if (check == true)
	{
		int nbr = convertInt(str);
		if (isprint(nbr))
			std::cerr << "char: " << static_cast<char>(nbr) << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
		std::cerr << "int: " << nbr << std::endl;
		std::cerr << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << std::endl;
	}
	return (check);
}


float	convertFloat(std::string str)
{
	std::stringstream ss(str);
	float nbr;

	ss >> nbr;
	return (nbr);
}


bool	isFloat(std::string const &str_o)
{
	std::string str = (std::string) str_o;
	int	cnt = 0;
	bool	check = true;

	std::string::iterator iter = str.end() - 1;
	if (*iter != 'f')
		check = false;
	else
	{
		for (iter = str.begin(); iter != str.end() - 1; iter++)
		{
			if (*iter == '.')
				cnt++;
			if (cnt >= 2)
			{
				check = false;
				break ;
			}
			if (*iter != '.' && (*iter > '9' || *iter < '0'))
			{
				check = false;
				break ;
			}
		}
	}
	str = str.substr(0, str.find("f"));
	if (check == true)
	{
		float nbr = convertFloat(str);
		if (isprint(static_cast<int>(nbr)))
			std::cerr << "char: " << static_cast<char>(static_cast<int>(nbr)) << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
		std::cerr << "int: " << static_cast<int>(nbr) << std::endl;
		std::cerr << "float: " << nbr << "f" << std::endl;
		std::cerr << "double: " << static_cast<double>(nbr) << std::endl;
	}
	return (check);
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
	std::string str = (std::string) str_o;
	int	cnt = 0;
	bool check = false;

	std::string::iterator iter;
	for (iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter == '.')
			cnt++;
		if (cnt >= 2)
			break ;
		if (*iter != '.' && (*iter > '9' || *iter < '0'))
			break ;
	}
	if (iter == str.end())
		check = true;
	if (check == true)
	{
		double nbr = convertDouble(str);
		if (isprint(nbr))
			std::cerr << "char: " << *iter << std::endl;
		else
			std::cerr << "char: " << "Non displayable" << std::endl;
		std::cerr << "int: " << static_cast<int>(nbr) << std::endl;
		std::cerr << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cerr << "double: " << nbr << std::endl;
	}
	return (check);
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