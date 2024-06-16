/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:50:11 by qdo               #+#    #+#             */
/*   Updated: 2024/06/16 20:59:40 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
	static int a = -1;
	a++;

	if (a % 3 == 0)
	{
		std::cout << "new A born" << std::endl;
		return (new A);
	}
	if (a % 3 == 1)
	{
		std::cout << "new B born" << std::endl;
		return (new B);
	}
	std::cout << "new C born" << std::endl;
	return (new C);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
		
}

void	identify(Base &p)
{
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try {
			(void) dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "C" << std::endl;
		}
	}

}

int main(void)
{
	Base *ptr;
	ptr = generate();
	
	identify(ptr);
	identify(*ptr);


	
	std::cout << "----------" << std::endl;
	Base *ptr1;
	ptr1 = generate();
	
	identify(ptr1);
	identify(*ptr1);


	std::cout << "----------" << std::endl;
	Base *ptr2;
	ptr2 = generate();
	
	identify(ptr2);
	identify(*ptr2);


	std::cout << "----------" << std::endl;
	Base *ptr3;
	ptr3 = generate();
	
	identify(ptr3);
	identify(*ptr3);
}