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
	//Constructors
	Passenger(std::string& line);
	Passenger(bool survived, int pclass, std::string name, int sex, 
			int age, int sibsp, int parch, double fare);

	//Getters
	bool getSurvived();
	int getPassengerClass();
	std::string getName();
	int getSex();
	int getAge();
	int getNumSibPart();
	int getNumParentChild();
	double getFare();

	//Derived Getter
	//Returns m_sibsp + m_parch
	int getFamilySize();

	//Removes Title or Honorific ie. Mr, Mrs, Master from m_name
	void removeHonorific();
};


#endif
