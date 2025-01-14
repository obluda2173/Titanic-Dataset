#ifndef DATA_HPP
#define DATA_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

class Passenger {
private:
	int m_survived;
	int m_pclass;
	std::string m_name;
	int m_sex;			// 1 for male, 0 for female
	int m_age;
	int m_sibsp;			// Number of siblings/spouses aboard
	int m_parch;			// Number of parents/children aboard
	double m_fare;
public:
	Passenger(std::string& line);

	int getSurvived() const;
	int getPassengerClass() const;
	std::string getName() const;
	int getSex() const;
	int getAge() const;
	int getNumSibPart() const;
	int getNumParentChild() const;
	double getFare() const;
};

void LoadData(const std::string& filename, std::vector<Passenger>& data);
void PreprocessData(std::vector<Passenger>& data);
void ExportDataToCSV(const std::vector<Passenger>& data, const std::string& filename);


#endif
