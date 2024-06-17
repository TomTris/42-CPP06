/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:25:02 by qdo               #+#    #+#             */
/*   Updated: 2024/06/17 09:36:29 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"
#include <sstream>


std::string decimalToHex(unsigned long long nbr)
{
     std::stringstream ss;    

     ss<< std::hex << nbr;
     return ss.str();
}

int	main(void)
{
	Data a;

	a.str = "123";


	std::cout << Serialization::serialize(&a) << std::endl;
	std::cout << Serialization::deserialize(Serialization::serialize(&a)) << std::endl;
	std::cout << Serialization::serialize(Serialization::deserialize(Serialization::serialize(&a))) << std::endl;
	std::cout << "----------------------" << std::endl;
	Data foo;
    uintptr_t reinterpreted;

    foo.str = std::string("test");
    reinterpreted = Serialization::serialize(&foo);

    std::cout << "OG foo (Data) Address = " << &foo << std::endl
         << "str value = " << foo.str << std::endl;
    std::cout << std::endl;
    std::cout << "Reinterpreted foo value = " << reinterpreted << std::endl;
    std::cout << std::endl;
    Data *deserialized;
    deserialized = Serialization::deserialize(reinterpreted);

    std::cout << "Deserialized Address = " << deserialized << std::endl
         << "str value = " << deserialized->str << std::endl;
     std::cout << sizeof(&foo) << " : " << sizeof(deserialized) << std::endl;

     std::cout << " ----------- ------- " << std::endl;
     unsigned long long decimalNumber = 140732754241344;
     std::string hexNumber = decimalToHex(decimalNumber);
     std::cout << "The hex: " << hexNumber << std::endl;
     std::cout << "0x7ffee5d32740" << std::endl;

}
