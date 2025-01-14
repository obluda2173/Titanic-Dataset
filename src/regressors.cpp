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