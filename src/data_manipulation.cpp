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

//useless for now
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
	file << "Survived,Pclass,Name,Sex,Age,SibSpouse,ParChild,FarePrice,FamilySize\n";
	for (const auto& p : data) {
		file << p.getSurvived() << ","
			<< p.getPassengerClass() << ","
			<< p.getName() << ","
			<< p.getSex() << ","
			<< p.getAge() << ","
			<< p.getNumSibPart() << ","
			<< p.getNumParentChild() << ","
			<< p.getFare() << ","
			<< p.getFamilySize() << "\n";
	}
}

std::vector<std::vector<double>> RetValsX(std::vector<Passenger>& passengers){
	unsigned int size = passengers.size();
	std::vector<std::vector<double>> ret_arr(size);
	for (unsigned int i = 0; i < size; i++){
		ret_arr[i].push_back((double)passengers[i].getPassengerClass());
		ret_arr[i].push_back((double)passengers[i].getSex());
		ret_arr[i].push_back((double)passengers[i].getAge());
		ret_arr[i].push_back((double)passengers[i].getFamilySize());
		ret_arr[i].push_back((double)passengers[i].getFare());
	}
	return ret_arr;
}

std::vector<double> RetValX(std::vector<Passenger>& passengers){
	std::vector<double> ret_arr;
	for (Passenger passenger : passengers){
		ret_arr.push_back((double)passenger.getFare());
	}
	return ret_arr;
}
std::vector<double> RetValY(std::vector<Passenger>& passengers){
	std::vector<double> ret_arr;
	for (Passenger passenger : passengers){
		ret_arr.push_back((double)passenger.getSurvived());
	}
	return ret_arr;
}