/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:49:25 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 19:08:34 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:

	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(ScalarConverter const & src);
	ScalarConverter & operator=(ScalarConverter const & src);

public:

	static void convert(std::string const & literal);
};

#endif