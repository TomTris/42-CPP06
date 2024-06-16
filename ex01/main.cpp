/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:25:02 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 20:11:05 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Serialization.hpp"

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

}