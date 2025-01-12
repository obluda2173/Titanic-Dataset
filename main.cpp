/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:06:45 by erian             #+#    #+#             */
/*   Updated: 2025/01/12 14:54:34 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

Passenger ParseRow(std::string& line) {
	std::stringstream ss(line);
	Passenger p;
	std::string token;

	std::getline(ss, token, ','); p.survived = std::stoi(token);
	std::getline(ss, token, ','); p.pclass = std::stoi(token);
	std::getline(ss, p.name, ',');
	std::getline(ss, p.sex, ',');
	std::getline(ss, token, ','); p.age = std::stoi(token);
	std::getline(ss, token, ','); p.sibsp = std::stoi(token);
	std::getline(ss, token, ','); p.parch = std::stoi(token);
	std::getline(ss, token, ','); p.fare = std::stod(token);
	
	return p;
}

void LoadData(const std::string& filename, std::vector<Passenger>& data) {
	std::ifstream file(filename);
	std::string line;
	
	while (std::getline(file, line)) {
		if (!line.empty()){
			data.push_back(ParseRow(line));
		}
	}
}

int main(int ac, char **av){
	std::vector<Passenger> titanic_data;
	
	if (ac != 3){
		std::cout << "invalid number of arguments\n" << std::endl;
		return 0;
	}
	(void)ac;
	(void)av;
	LoadData("titanic.csv", titanic_data);
	std::cout << "Loaded " << titanic_data.size() << " rows of data." << std::endl;
	return 0;
}
