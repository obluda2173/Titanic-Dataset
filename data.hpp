/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:10:06 by erian             #+#    #+#             */
/*   Updated: 2025/01/12 20:08:48 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

#include <embed.h>
namespace py = pybind11;

struct Passenger {
	int survived;
	int pclass;
	std::string name;
	int sex;			// 1 for male, 0 for female
	int age;
	int sibsp;			// Number of siblings/spouses aboard
	int parch;			// Number of parents/children aboard
	double fare;
};


#endif