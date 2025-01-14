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
Passenger::Passenger(bool survived, int pclass, std::string name, 
		int sex, int age, int sibsp, int parch, double fare) {
	m_survived = survived;
	m_pclass = pclass;
	m_name = name;
	m_sex = sex;
	m_age = age;
	m_sibsp = sibsp;
	m_parch = parch;
	m_fare = fare;
}
bool Passenger::getSurvived() {
	return m_survived;
}
int Passenger::getPassengerClass() {
	return m_pclass;
}
std::string Passenger::getName() {
	return m_name;
}
int Passenger::getSex() {
	return m_sex;
}
int Passenger::getAge() {
	return m_age;
}
int Passenger::getNumSibPart() {
	return m_sibsp;
}
int Passenger::getNumParentChild() {
	return m_parch;
}
int Passenger::getFamilySize() {
	return m_sibsp + m_parch;
}
double Passenger::getFare() {
	return m_fare;
}

void Passenger::removeHonorific() {
	size_t dotPos = m_name.find('.');
	if (dotPos != std::string::npos) {
		m_name = m_name.substr(dotPos + 2);
	}
}
