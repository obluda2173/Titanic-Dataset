#ifndef DATA_HPP
#define DATA_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class Passenger {
private:
	bool m_survived;
	int m_pclass;
	std::string m_name;
	int m_sex;				// 1 for male, 0 for female
	int m_age;
	int m_sibsp;			// Number of siblings/spouses aboard
	int m_parch;			// Number of parents/children aboard
	double m_fare;
public:
	Passenger(std::string& line);

	int getSurvived();
	int getPassengerClass();
	std::string getName();
	int getSex();
	int getAge();
	int getNumSibPart();
	int getNumParentChild();
	double getFare();
};

#endif
