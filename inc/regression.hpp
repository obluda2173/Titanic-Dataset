#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include "data.hpp"
#include <iostream>
#include <vector>
#include "matrix.hpp"

class LinearRegressor {
private:
	Matrix m_weights;
	double m_bias;

	double m_learningRate;

public:
	LinearRegressor(double learningRate);
	//Getters
	Matrix GetWeights() const;
	double GetBias() const;

	// bool Fit(std::vector<double>& x, std::vector<double>& y);
	void Train(Matrix& x, Matrix& y, int iterations);
	double Transform(double value) const;
	Matrix Transform(Matrix& values) const;
	Matrix Transform(Passenger& passenger) const;
};

double MeanSquaredError(Matrix& y, Matrix& yHat);

#endif