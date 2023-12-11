/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:42:51 by wxuerui           #+#    #+#             */
/*   Updated: 2023/07/28 16:28:46 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "colors.h"

void	test0() {
	std::cout << GREEN << "----- Test 0: Basic -----" << RESET << std::endl;
	
	Array<int>	arr(2);
	arr[0] = 1;
	arr[1] = 2;

	std::cout << arr[0] << std::endl;
	std::cout << arr[1] << std::endl;
}

void	test1() {
	std::cout << GREEN << "\n----- Test 1: Copying (deep) -----" << RESET << std::endl;

	{
		Array<int>	arr1(2);
		Array<int>	arr2; // empty at first
		arr1[0] = 1;
		arr1[1] = 2;

		std::cout << BLUE << "Copy assignment operator test" << RESET << std::endl;

		arr2 = arr1;
		std::cout << YELLOW << "After copy assignment" << RESET << std::endl;
		std::cout << "arr1[0]: " << arr1[0] << std::endl;
		std::cout << "arr1[1]: " << arr1[1] << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;

		arr1[0] = 4587;
		std::cout << YELLOW << "Do some modification" << RESET << std::endl;
		std::cout << "arr1[0]: " << arr1[0] << std::endl;
		std::cout << "arr1[1]: " << arr1[1] << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;
	}
	{
		Array<int>	arr1(2);
		arr1[0] = 1;
		arr1[1] = 2;
		Array<int>	arr2(arr1);
		
		std::cout << BLUE << "\nCopy constructor test" << RESET << std::endl;
		std::cout << "arr1[0]: " << arr1[0] << std::endl;
		std::cout << "arr1[1]: " << arr1[1] << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;

		arr1[0] = 4587;
		std::cout << YELLOW << "Do some modification" << RESET << std::endl;
		std::cout << "arr1[0]: " << arr1[0] << std::endl;
		std::cout << "arr1[1]: " << arr1[1] << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << std::endl;
		std::cout << "arr2[1]: " << arr2[1] << std::endl;
	}
}

void	test2() {
	std::cout << GREEN << "\n----- Test 2: Index out of range -----" << RESET << std::endl;

	Array<std::string> *arr = new Array<std::string>(3);
	(*arr)[0] = "ray";
	(*arr)[1] = "ricky";
	(*arr)[2] = "py";
	
	try {
		(*arr)[3] = "out of range";
	} catch (std::exception& e) {
		std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
	}
	try {
		(*arr)[-1] = "out of range also";
	} catch (std::exception& e) {
		std::cout << "Exception: " << RED << e.what() << RESET << std::endl;
	}

	delete arr;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
// 	system("leaks -q array");
//     return 0;
// }

int main(void) {
	test0();
	test1();
	test2();

	std::cout << std::endl;
	system("leaks -q array");
}