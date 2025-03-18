#include "activations.hpp"

Matrix sigmoid(Matrix x) {
	// Matrix neg_x = x * Matrix(-1);
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