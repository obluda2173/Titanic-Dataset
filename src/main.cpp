#include "data.hpp"

int main() {
	std::vector<Passenger> titanic_data;

	// Load, preprocess, and export data
	LoadData("titanic.csv", titanic_data);
	std::cout << "Loaded " << titanic_data.size() << " rows of data." << std::endl;

	// PreprocessData(titanic_data);
	ExportDataToCSV(titanic_data, "processed_data.csv");

	// Execute the Python script
	int result = std::system("python3 src/graphs.py");
	if (result != 0) {
		std::cerr << "Error: Could not execute Python script." << std::endl;
		return result;
	}

	return 0;
}
