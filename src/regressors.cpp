#include "regression.hpp"
#include "activations.hpp"

// bool LinearRegressor::Fit(std::vector<double> x, std::vector<double> y)
// {
// 	if (x.size() != y.size()) {
// 		return false;
// 	}
	
// 	int n = x.size();

// 	float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		sumX = sumX + x[i];
// 		sumY = sumY + y[i];
// 		sumXY = sumXY + x[i] * y[i];
// 		sumX2 = sumX2 + x[i] * x[i];
// 	}
// 	m_weight = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
// 	m_bias = (sumY-m_weight*sumX)/n;
// 	return true;
// }

// double LinearRegressor::Transform(double value) const {
// 	return value * m_weight + m_bias;
// }
LinearRegressor::LinearRegressor(double learningRate) : m_weights(0.0) {
	m_learningRate = learningRate;
}

Matrix LinearRegressor::GetWeights() const {
	return m_weights;
}


Matrix LinearRegressor::Transform(Matrix& values) const {
	Matrix retMatrix = values.dot(m_weights);
	// retMatrix.print();
	return retMatrix + Matrix(m_bias);
}
Matrix LinearRegressor::Transform(Passenger& passenger) const {
	std::vector<double> retArr;
	retArr.push_back((double)passenger.getPassengerClass());
	retArr.push_back((double)passenger.getSex());
	retArr.push_back((double)passenger.getAge());
	retArr.push_back((double)passenger.getFamilySize());
	retArr.push_back((double)passenger.getFare());
	Matrix retMatrix(retArr, 0);
	return Transform(retMatrix);
}
void LinearRegressor::Train(Matrix& x, Matrix& y, int iterations) {
	int nSamples = x.getRows();
	int nFeatures = x.getCols();

	m_weights.nRandomised(nFeatures, 1);
	m_bias = 0.0;


	for (int iteration = 0; iteration < iterations; iteration++) {

		Matrix yHat = sigmoid(Transform(x));

		// Matrix error = yHat - y;
		Matrix derivativeLoss = binaryCrossEntropyLossDerivative(y, yHat);
		Matrix derivativeActivation = sigmoidDerivative(derivativeLoss, yHat);
		Matrix derivativeWeights = x.T().dot(derivativeActivation);
		double derivativeBias = derivativeActivation.sum()(0, 0);

		m_weights = m_weights - derivativeWeights * Matrix(m_learningRate / nSamples);
		m_bias = m_bias - m_learningRate * derivativeBias / nSamples;
	
		if (iteration % 500 == 0){
			std::cout << "Iteration " << iteration << "\n\tMSE: " << binaryCrossEntropyLoss(y, yHat) << std::endl;
		}
	}
}
double MeanSquaredError(Matrix& y, Matrix& yHat) {
	Matrix error = (yHat-y) * (yHat-y);
	return (error.sum()(0, 0) / y.getRows());
}