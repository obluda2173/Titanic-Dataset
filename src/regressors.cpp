#include "regression.hpp"
bool LinearRegressor::Fit(std::vector<double> x, std::vector<double> y)
{
	if (x.size() != y.size()) {
		return false;
	}
	
	int n = x.size();

	float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
	for (int i = 0; i < n; i++)
	{
		sumX = sumX + x[i];
		sumY = sumY + y[i];
		sumXY = sumXY + x[i] * y[i];
		sumX2 = sumX2 + x[i] * x[i];
	}
	m_weight = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
	m_bias = (sumY-m_weight*sumX)/n;
	return true;
}
double LinearRegressor::Transform(double value) const {
	return value * m_weight + m_bias;
}
double LinearRegressor::Transform(std::vector<double> values) const {
	double sum = 0;
	for (unsigned int i = 0; i < values.size(); i++) {
		sum += values[i] * m_weights[i];
	}
	return sum + m_bias;
}
double LinearRegressor::Transform(Passenger passenger) const {
	std::vector<double> retArr;
	retArr.push_back((double)passenger.getPassengerClass());
	retArr.push_back((double)passenger.getSex());
	retArr.push_back((double)passenger.getAge());
	retArr.push_back((double)passenger.getFamilySize());
	retArr.push_back((double)passenger.getFare());
	return Transform(retArr);
}
void printVector(std::vector<long double> printv) {
	for (const auto& i: printv)
    	std::cout << i << ' ';
}
bool LinearRegressor::Train(std::vector<std::vector<double>> x, std::vector<double> y, double learningRate, int iterations) {
	while (m_weights.size() < x[0].size()) {
		m_weights.push_back(.9);
	}
	for (int iteration = 0; iteration < iterations; iteration++) {

		std::cout << std::endl;
		std::vector<long double> sumDerivativeWeights(x[0].size());
		long double sumDerivativeBias = 0;
		std::vector<double> yHatVals;
		for (unsigned int i = 0; i < x.size(); i++) {
			yHatVals.push_back(Transform(x[i]));
			double error = y[i] - yHatVals[i];
			for (unsigned j = 0; j < x[i].size(); j++) {
				sumDerivativeWeights[j] += 2 * x[i][j] * error;
			}
			sumDerivativeBias += 2 * error;
		}


		for (unsigned i = 0; i < m_weights.size(); i++) {
			m_weights[i] -= (sumDerivativeWeights[i] /= x[i].size()) * learningRate;
		}
		printVector(sumDerivativeWeights);
		m_bias -= (sumDerivativeBias / y.size()) * learningRate;
		// std::cout << MeanSquaredError(y, yHatVals) << std::endl;
	}
	return true;
}
double MeanSquaredError(std::vector<double> y, std::vector<double> yHat) {
	long double sum = 0;
	for (unsigned int i = 0; i < y.size(); i++) {
		sum += (y[i] - yHat[i]) * (y[i] - yHat[i]);
	}
	return (sum / y.size());
}