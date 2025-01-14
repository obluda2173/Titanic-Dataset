#include "data.hpp"


//-------@ Bug @ ---- |ParseRow doesnt exist|

// void loadData(const std::string& filename, std::vector<Passenger>& data) {
// 	std::ifstream file(filename);
// 	std::string line;
	
// 	while (std::getline(file, line)) {
// 		if (!line.empty()){
// 			data.push_back(ParseRow(line));
// 		}
// 	}
// }

void preprocessData(std::vector<Passenger>& data) {
	for (Passenger passenger : data) {
		passenger.removeHonorific();
	}
}

//------- @ later fix @ --------

// void ExportDataToCSV(const std::vector<Passenger>& data, const std::string& filename) {
// 	std::ofstream file(filename);
// 	for (const auto& p : data) {
// 		file << p.survived << ","
// 			<< p.pclass << ","
// 			<< p.name << ","
// 			<< p.sex << ","
// 			<< p.age << ","
// 			<< p.sibsp << ","
// 			<< p.parch << ","
// 			<< p.fare << "\n";
// 	}
// 	file.close();
// }


// void CallPythonScript() {
//     py::scoped_interpreter guard{}; // Start the Python interpreter

//     py::exec(R"(
//         import pandas as pd
//         import matplotlib.pyplot as plt

//         # Example Python code
//         data = pd.read_csv('processed_titanic_data.csv')
//         survival_rate = data.groupby('Pclass')['Survived'].mean()
//         survival_rate.plot(kind='bar')
//         plt.title('Survival Rate by Passenger Class')
//         plt.xlabel('Passenger Class')
//         plt.ylabel('Survival Rate')
//         plt.show()
//     )");
// }

int main(int ac, char **av){
	std::vector<Passenger> titanic_data;
	Passenger passenger(true, 1, "Mr. Erik An", 1, 19, 3, 2, 1000);
	
	(void)av;
	
	if (ac != 1){
		std::cout << "invalid input\n" << std::endl;
		return 0;
	}

	// loadData("titanic.csv", titanic_data);
	// std::cout << "loaded " << titanic_data.size() << " rows of data." << std::endl;
	

	// preprocessData(titanic_data);
	
	// for (auto& passenger : titanic_data) {
	// 	std::cout << passenger.getName() << std::endl;
	// }

	std::cout << passenger.getName() << std::endl;
	passenger.removeHonorific();
	std::cout << passenger.getName() << std::endl;
	// ExportDataToCSV(titanic_data, "preprocessed_titanic_data.csv");

	return 0;
}
