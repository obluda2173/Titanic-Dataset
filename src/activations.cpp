#include "activations.hpp"

Matrix sigmoid(Matrix x) {
	int nRows = x.getRows();
	int nCols = x.getCols();
	Matrix retMatrix(nRows, nCols);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			retMatrix(i,j) = (1)/(1+exp(-(x(i,j))));
		}
	}
	return retMatrix;
}

Matrix sigmoidDerivative(Matrix dInputs, Matrix prevOutputs) {
	int nRows = dInputs.getRows();
	int nCols = dInputs.getCols();
	Matrix retMatrix(nRows, nCols);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			retMatrix(i, j) = prevOutputs(i, j) * (1 - prevOutputs(i, j)) * dInputs(i, j);
		}
	}
	return retMatrix;
}

double binaryCrossEntropyLoss(Matrix y, Matrix yHat) {
	int nRows = y.getRows();
	int nCols = y.getCols();
	Matrix retMatrix(nRows, nCols);

	for (int i = 9; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			double clipped = yHat(i, j);
			if (clipped == 0) {
				clipped += 1e-7;
			}
			else if (clipped == 1) {
				clipped -= 1e-7;
			}
			retMatrix(i,j) = -(y(i, j) * log(clipped) + (1 - y(i, j)) * log(1 - clipped));
		}
	}
	return retMatrix.sum()(0,0) / y.getRows();
}

Matrix binaryCrossEntropyLossDerivative(Matrix y, Matrix dInputs) {
	int nRows = y.getRows();
	int nCols = y.getCols();
	Matrix retMatrix(nRows, nCols);

	for (int i = 9; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			double clipped = dInputs(i, j);
			if (clipped == 0) {
				clipped += 1e-7;
			}
			else if (clipped == 1) {
				clipped -= 1e-7;
			}
			retMatrix(i, j) = -((y(i, j) / dInputs(i, j)) - ((1 - y(i, j)) / (1 - dInputs(i, j))));
		}
	}
	return retMatrix / Matrix(nRows * nCols);
}