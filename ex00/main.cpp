/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:05:05 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 21:26:24 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
int	main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        std::cerr << "Usage: ./convert <literal>" << "\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;

}

// int main(void)
// {
//     std::string a = "+4.";
//     std::stringstream ss(a);
//     float nbr;

//     ss >> nbr;
//     std::cout << nbr << std::endl;
// }