#include "data.hpp"

void LoadData(const std::string& filename, std::vector<Passenger>& data) {
	std::ifstream file(filename);
	std::string line;

	bool isHeader = true;
	while (std::getline(file, line)) {
		if (isHeader) {
			isHeader = false;
			continue;
		}

		if (!line.empty()) {
			try {
				data.emplace_back(line);
			} catch (const std::invalid_argument& e) {
				std::cerr << "Error parsing line: " << line << "\n";
				std::cerr << "Reason: " << e.what() << "\n";
				continue;
			}
		}
	}
}

void PreprocessData(std::vector<Passenger>& data) {
	for (auto& passenger : data) {
		size_t dot_pos = passenger.getName().find('.');
		if (dot_pos != std::string::npos) {
			passenger.getName() = passenger.getName().substr(dot_pos + 2);
		}
	}
}

void ExportDataToCSV(const std::vector<Passenger>& data, const std::string& filename) {
	std::ofstream file(filename);
	file << "Survived,Pclass,Name,Sex,Age,SibSpouse,ParChild,FarePrice\n";
	for (const auto& p : data) {
		file << p.getSurvived() << ","
			<< p.getPassengerClass() << ","
			<< p.getName() << ","
			<< p.getSex() << ","
			<< p.getAge() << ","
			<< p.getNumSibPart() << ","
			<< p.getNumParentChild() << ","
			<< p.getFare() << "\n";
	}
}
