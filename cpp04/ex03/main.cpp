/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:36:03 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/25 14:09:33 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "colors.h"
#include <cstdlib>

void test0() {
	std::cout << GREEN << "TEST 0: subject test" << RESET << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	test1() {
	std::cout << GREEN << "TEST 1: Unequip" << RESET << std::endl;

	AMateria *allMaterias[10];

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	allMaterias[0] = src->createMateria("ice");
	me->equip(allMaterias[0]);
	allMaterias[1] = src->createMateria("cure");
	me->equip(allMaterias[1]);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0); // Test for unequip
	me->unequip(1);

	delete allMaterias[0];
	delete allMaterias[1];

	delete bob;
	delete me;
	delete src;
}

void	test2() {
	std::cout << GREEN << "TEST 2: Equip more than 4 materias to a character and use invalid materia index" << RESET << std::endl;

	AMateria *allMaterias[10];
	for (int i = 0; i < 10; i++) {
		allMaterias[i] = NULL;
	}

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	allMaterias[0] = src->createMateria("ice");
	me->equip(allMaterias[0]);
	allMaterias[1] = src->createMateria("cure");
	me->equip(allMaterias[1]);
	allMaterias[2] = src->createMateria("ice");
	me->equip(allMaterias[2]);
	allMaterias[3] = src->createMateria("cure");
	me->equip(allMaterias[3]);
	allMaterias[4] = src->createMateria("ice"); // not equiped successfully, need to be deleted
	me->equip(allMaterias[4]);
	allMaterias[5] = src->createMateria("cure"); // not equiped successfully, need to be deleted
	me->equip(allMaterias[5]);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // invalid materia index used

	me->unequip(0); // Only unequip one of the materia and handle on ground case

	for (int i = 0; allMaterias[i] != NULL && i < 10; i++) { // delete all extra and on ground materias
		if (allMaterias[i]->isEquiped() == false) {
			delete allMaterias[i];
		}
	}

	delete bob;
	delete me;
	delete src;
}

void	test3() {
	std::cout << GREEN << "TEST 3: Learn more than 4 materias to MateriaSource" << RESET << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *tmp = new Ice();
	src->learnMateria(tmp); // Not learned successfully, need to delete

	delete src;
	std::cout << BLUE << "Here" << RESET << std::endl;
	delete tmp;
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	system("leaks -q interface");
	return 0;
}