/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:52:44 by wxuerui           #+#    #+#             */
/*   Updated: 2023/04/19 18:48:49 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

#include <string>
#include <iostream>
#include <fstream>
#include "colors.h"

bool	sed(std::string filename, std::string s1, std::string s2);

#endif