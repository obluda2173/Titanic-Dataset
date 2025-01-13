#include "data.hpp"

Passenger ParseRow(std::string& line) {
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

void LoadData(const std::string& filename, std::vector<Passenger>& data) {
	std::ifstream file(filename);
	std::string line;
	
	while (std::getline(file, line)) {
		if (!line.empty()){
			data.push_back(ParseRow(line));
		}
	}
}

void PreprocessData(std::vector<Passenger>& data) {
	for (auto& passenger : data) {
		size_t dot_pos = passenger.name.find('.');
		if (dot_pos != std::string::npos) {
			passenger.name = passenger.name.substr(dot_pos + 2);
		}
	}
}

void ExportDataToCSV(const std::vector<Passenger>& data, const std::string& filename) {
	std::ofstream file(filename);
	for (const auto& p : data) {
		file << p.survived << ","
			<< p.pclass << ","
			<< p.name << ","
			<< p.sex << ","
			<< p.age << ","
			<< p.sibsp << ","
			<< p.parch << ","
			<< p.fare << "\n";
	}
	file.close();
}


void CallPythonScript() {
    py::scoped_interpreter guard{}; // Start the Python interpreter

    py::exec(R"(
        import pandas as pd
        import matplotlib.pyplot as plt

        # Example Python code
        data = pd.read_csv('processed_titanic_data.csv')
        survival_rate = data.groupby('Pclass')['Survived'].mean()
        survival_rate.plot(kind='bar')
        plt.title('Survival Rate by Passenger Class')
        plt.xlabel('Passenger Class')
        plt.ylabel('Survival Rate')
        plt.show()
    )");
}

int main(int ac, char **av){
	std::vector<Passenger> titanic_data;
	Passenger passenger;
	
	(void)av;
	
	if (ac != 1){
		std::cout << "invalid input\n" << std::endl;
		return 0;
	}
	
	passenger.pclass = 1;
	passenger.name = "Mr. Erik An";
	passenger.sex = 1;
	passenger.age = 19;
	passenger.sibsp = 3;
	passenger.parch = 2;
	passenger.fare = 1000;
	

	LoadData("titanic.csv", titanic_data);
	std::cout << "loaded " << titanic_data.size() << " rows of data." << std::endl;
	

	PreprocessData(titanic_data);
	
	for (auto& passenger : titanic_data) {
		std::cout << passenger.name << std::endl;
	}

	ExportDataToCSV(titanic_data, "preprocessed_titanic_data.csv");

	return 0;
}
