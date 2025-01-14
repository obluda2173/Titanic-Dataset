#ifndef REGRESSION
#define REGRESSION

#include "data.hpp"
#include <vector>

class LinearRegressor {
private:
	double m_weight;
	double m_bias;

public:
	//Getters
	double GetWeight() const;
	double GetBias() const;

	bool Fit(std::vector<double> x, std::vector<double> y);
	double Transform(double value) const;
};


#endif