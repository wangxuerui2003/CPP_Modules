/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:40:44 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/27 15:22:04 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.h"
#include "colors.h"

void	randomPtrTest(void) {
	std::cout << GREEN << "Random Pointers test" << RESET << std::endl;

	Base	*randPtrs[5];
	srand(time(NULL)); // Reset the random seed
	for (int i = 0; i < 5; ++i) {
		randPtrs[i] = generate();
	}

	for (int i = 0; i < 5; ++i) {
		identify(randPtrs[i]);
	}

	for (int i = 0; i < 5; ++i) {
		delete randPtrs[i];
	}
}

void	certainTypePtrTest(void) {
	std::cout << GREEN << "\nCertain type Pointers test" << RESET << std::endl;

	Base	*a = new A;
	Base	*b = new B;
	Base	*c = new C;

	identify(a);
	identify(b);
	identify(c);

	delete a;
	delete b;
	delete c;
}

void	refTest(void) {
	std::cout << GREEN << "\nReference test" << RESET << std::endl;

	A a;
	C c;
	B b;

	Base&	aRef = a;
	Base&	bRef = b;
	Base&	cRef = c;

	identify(aRef);
	identify(cRef);
	identify(bRef);
}

int main(void) {
	randomPtrTest();
	certainTypePtrTest();
	refTest();

	std::cout << std::endl;
	system("leaks -q identify");
}