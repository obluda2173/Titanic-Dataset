#include "data.hpp"

Passenger::Passenger(std::string& line) {
	std::stringstream ss(line);
	Passenger p;
	std::string token;

	std::getline(ss, token, ','); p.survived = std::stoi(token);
	std::getline(ss, token, ','); p.pclass = std::stoi(token);
	std::getline(ss, p.name, ',');
	std::getline(ss, token, ','); p.sex = (token == "male") ? 1 : 0;
	std::getline(ss, token, ','); p.age = std::stoi(token);
	std::getline(ss, token, ','); p.sibsp = std::stoi(token);
	std::getline(ss, token, ','); p.parch = std::stoi(token);
	std::getline(ss, token, ','); p.fare = std::stod(token);
	
	return p;
}
Passenger::getSurvived() {
	return m_survived;
}
Passenger::getPassengerClass() {
	return m_pclass;
}
Passenger::getName() {
	return m_name;
}
Passenger::getSex() {
	return m_sex;
}
Passenger::getAge() {
	return m_age;
}
Passenger::getNumSibPart() {
	return m_sibsp;
}
Passenger::getNumParentChild() {
	return m_parch;
}
Passenger::getFare() {
	return m_fare;
}
