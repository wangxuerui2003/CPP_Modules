/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:01:46 by wxuerui           #+#    #+#             */
/*   Updated: 2023/06/07 21:32:53 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <unistd.h>

void	test1(void) {
	std::cout << GREEN << "Simple memory leaks test given from the subject.pdf" << RESET << std::endl;
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}

void	test2(void) {
	std::cout << GREEN << "Destructors test" << RESET << std::endl;

	AAnimal	*arr[100];
	for (int i = 0; i < 50; i++) {
		arr[i] = new Dog();
		std::cout << "-----------------" << std::endl;
	}
	for (int i = 50; i < 100; i++) {
		arr[i] = new Cat();
		std::cout << "-----------------" << std::endl;
	}

	for (int i = 0; i < 50; i++) {
		// sleep(1);
		delete arr[i];
		std::cout << "-----------------" << std::endl;
	}
	for (int i = 50; i < 100; i++) {
		// sleep(1);
		delete arr[i];
		std::cout << "-----------------" << std::endl;
	}
}

void	test3(void) {
	std::cout << GREEN << "Test for deep copy" << RESET << std::endl;

	Dog	dog1, dog2;
	Cat	cat1, cat2;

	dog1.setIdea("idea0"); // init some dog1 ideas
	dog1.setIdea("idea1");
	dog2 = dog1; // copy dog1 to dog2
	dog1.setIdea("idea3"); // Add another idea for dog1
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getIdea(1) << std::endl;
	std::cout << "Dog1 idea 2: " << dog1.getIdea(2) << std::endl;
	std::cout << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 1: " << dog2.getIdea(1) << std::endl;
	std::cout << "Dog2 idea 2: " << dog2.getIdea(2) << std::endl; // Should be empty
	std::cout << "Dog1 mem addr: " << &dog1 << std::endl;
	std::cout << "Dog2 mem addr: " << &dog2 << std::endl;

	cat1.setIdea("idea0"); // init some cat1 ideas
	cat1.setIdea("idea1");
	cat2 = cat1; // copy cat1 to cat2
	cat2.setIdea("idea3"); // Add another idea for cat2
	std::cout << "cat1 idea 0: " << cat1.getIdea(0) << std::endl;
	std::cout << "cat1 idea 1: " << cat1.getIdea(1) << std::endl;
	std::cout << "cat1 idea 2: " << cat1.getIdea(2) << std::endl; // Should be empty
	std::cout << std::endl;
	std::cout << "cat2 idea 0: " << cat2.getIdea(0) << std::endl;
	std::cout << "cat2 idea 1: " << cat2.getIdea(1) << std::endl;
	std::cout << "cat2 idea 2: " << cat2.getIdea(2) << std::endl;
	std::cout << "cat1 mem addr: " << &cat1 << std::endl;
	std::cout << "cat2 mem addr: " << &cat2 << std::endl;
}

int main()
{
	test1();
	test2();

	test3();

	// This following line would output error "AAnimal is an abstract class" when compile
	// AAnimal	cannotbeinstantiated;
	
	std::cout << std::endl;
	system("leaks -q abstractBrain");

	return 0;
}