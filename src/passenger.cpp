#include "data.hpp"

Passenger::Passenger(std::string& line) {
	std::stringstream ss(line);
	std::string token;

	std::getline(ss, token, ','); m_survived = std::stoi(token);
	std::getline(ss, token, ','); m_pclass = std::stoi(token);
	std::getline(ss, m_name, ',');
	std::getline(ss, token, ','); m_sex = (token == "male") ? 1 : 0;
	std::getline(ss, token, ','); m_age = std::stoi(token);
	std::getline(ss, token, ','); m_sibsp = std::stoi(token);
	std::getline(ss, token, ','); m_parch = std::stoi(token);
	std::getline(ss, token, ','); m_fare = std::stod(token);
}
int Passenger::getSurvived() const {
	return m_survived;
}
int Passenger::getPassengerClass() const {
	return m_pclass;
}
std::string Passenger::getName() const {
	return m_name;
}
int Passenger::getSex() const {
	return m_sex;
}
int Passenger::getAge() const {
	return m_age;
}
int Passenger::getNumSibPart() const {
	return m_sibsp;
}
int Passenger::getNumParentChild() const {
	return m_parch;
}
double Passenger::getFare() const {
	return m_fare;
}
