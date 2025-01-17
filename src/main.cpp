#include "data.hpp"
#include "regression.hpp"

int main() {
	std::vector<Passenger> titanic_data;

	Passenger hisRoyalHighness(true, 2, "Mr.", 1, 19, 1, 2, 31.15);
	// Load, preprocess, and export data
	LoadData("titanic.csv", titanic_data);
	std::cout << "Loaded " << titanic_data.size() << " rows of data." << std::endl;

	auto x = RetValsX(titanic_data);
	auto y = RetValY(titanic_data);
	LinearRegressor regressor;
	regressor.Train(x, y, .01, 100);
	std::cout << regressor.Transform(hisRoyalHighness) << std::endl;
	
	// PreprocessData(titanic_data);
	// ExportDataToCSV(titanic_data, "processed_data.csv");

	// // Execute the Python script
	// int result = std::system("python src/graphs.py");
	// if (result != 0) {
	// 	std::cerr << "Error: Could not execute Python script." << std::endl;
	// 	return result;
	// }

	return 0;
}
