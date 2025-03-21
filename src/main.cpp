#include "data.hpp"
#include "regression.hpp"
#include "matrix.hpp"
#include "activations.hpp"

int main() {
	std::vector<Passenger> titanic_data;
	// Load, preprocess, and export data
	LoadData("titanic.csv", titanic_data);
	std::cout << "Loaded " << titanic_data.size() << " rows of data." << std::endl;

	Matrix x(RetValsX(titanic_data));
	Matrix y(RetValY(titanic_data), 1);

	y = y * Matrix(100);

	LinearRegressor regressor(.0001);

	regressor.Train(x, y, 10500);

	regressor.GetWeights().print();

	Passenger hisRoyalHighness(true, 1, "mr. s enter ", 1, 19, 3, 2, 300);

	std::cout.precision(2);

	std::cout << hisRoyalHighness.getName() << sigmoid(regressor.Transform(hisRoyalHighness))(0,0) << std::endl;

	
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

/*
 * make Sigmoid function
 * Loss Function: Binary Cross-Entropy / Log Loss
 * make partial derivatives of both functions
 */