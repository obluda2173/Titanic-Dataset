#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include "data.hpp"
#include <iostream>
#include <vector>

class LinearRegressor {
private:
	std::vector<double> m_weights;
	double m_weight;
	double m_bias;

public:
	//Getters
	double GetWeight() const;
	double GetBias() const;

	bool Fit(std::vector<double> x, std::vector<double> y);
	void Train(const std::vector<std::vector<double>>& x, const std::vector<double>& y, double learningRate, int iterations);
	double Transform(double value) const;
	double Transform(std::vector<double> values) const;
	double Transform(Passenger passenger) const;
};
double MeanSquaredError(std::vector<double> y, std::vector<double> yHat);

#endif