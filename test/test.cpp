/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:50:39 by wxuerui           #+#    #+#             */
/*   Updated: 2022/09/13 17:02:01 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	int	a;

	a = 10;
	std::cout << "Hello World" << std::endl;
	std::cout << a << std::endl;
	std::cout << "input a: ";
	std::cin >> a;
	std::cout << "the value of a now is " << a << std::endl;
	return (0);
}
