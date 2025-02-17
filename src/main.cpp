#include "data.hpp"
#include "regression.hpp"
#include "matrix.hpp"

int main() {
	std::vector<Passenger> titanic_data;
	// Load, preprocess, and export data
	LoadData("titanic.csv", titanic_data);
	std::cout << "Loaded " << titanic_data.size() << " rows of data." << std::endl;

	Matrix x(RetValsX(titanic_data));
	Matrix y(RetValY(titanic_data), 1);

	LinearRegressor regressor(.00025);

	regressor.Train(x, y, 100);

	Passenger hsRoyalHighness(true, 1, "mr.  s enter ", 1, 19, 3, 2, 31.15);
	std::cout << hsRoyalHighness.getName() << regressor.Transform(hsRoyalHighness)(0,0) << std::endl;

	
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
