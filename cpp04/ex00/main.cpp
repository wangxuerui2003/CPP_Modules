/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:01:46 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:11:31 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void	test1(void) {
	std::cout << GREEN << "Correct classes test 1" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete i;
	delete j;
}

void	test2(void) {
	std::cout << GREEN << "Correct classes test 2" << RESET << std::endl;
	
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();

	std::cout << "Animal's _type: " << animal->getType() << std::endl;
	std::cout << "Dog's _type: " << dog->getType() << std::endl;
	std::cout << "Cat's _type: " << cat->getType() << std::endl;

	*animal = *dog;
	*dog = *cat;
	
	std::cout << "Animal's _type: " << animal->getType() << std::endl;
	std::cout << "Dog's _type: " << dog->getType() << std::endl;
	std::cout << "Cat's _type: " << cat->getType() << std::endl;

	delete animal;
	delete dog;
	delete cat;
}

void	wrongtest(void) {
	std::cout << GREEN << "Wrong classes test" << RESET << std::endl;

	const WrongAnimal* wanimal = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound(); //will output the animal sound!
	wanimal->makeSound();
	
	delete wanimal;
	delete wcat;
}

int main()
{
	test1();
	test2();
	wrongtest();
	// system("leaks animal");
	return 0;
}