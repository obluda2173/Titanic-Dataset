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
void printVector(std::vector<double> printv) {
	for (const auto& i: printv)
    	std::cout << i << ' ';
}
void LinearRegressor::Train(const std::vector<std::vector<double>>& x, const std::vector<double>& y, double learningRate, int iterations) {
	int nSamples = x.size();
	int nFeatures = x[0].size();

	m_weights.resize(nFeatures, 0.0);
	m_bias = 0.0;

	for (int iter = 0; iter < iterations; iter++) {

		std::vector<double> yHat(nSamples, 0.0);

		for (int i = 0; i < nSamples; ++i) {
			yHat[i] = Transform(x[i]);
		}


		std::vector<double> derivativeWeights(nFeatures, 0.0);
		double derivativeBias = 0.0;

		for (int i = 0; i < nSamples; ++i) {

			double error = yHat[i] - y[i];

			for (int j = 0; j < nFeatures; ++j) {
				derivativeWeights[j] += 2 * error * x[i][j];
			}
			derivativeBias += 2 * error;
		}

		for (int j = 0; j < nFeatures; ++j) {
			m_weights[j] -= learningRate * derivativeWeights[j] / nSamples;
		}
		m_bias -= learningRate * derivativeBias / nSamples;
	
		// if (iter % 500 == 0){
		// 	std::cout << "Iteration " << iter << "\n\tMSE: " << MeanSquaredError(y, yHat) << std::endl;
		// }
	}
}
double MeanSquaredError(std::vector<double> y, std::vector<double> yHat) {
	long double sum = 0;
	for (unsigned int i = 0; i < y.size(); i++) {
		sum += (yHat[i] - y[i]) * (yHat[i] - y[i]);
	}
	return (sum / y.size());
}