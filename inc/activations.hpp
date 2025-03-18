#ifndef ACTIVATIONS_HPP
#define ACTIVATIONS_HPP

#include <cmath>

#include "matrix.hpp"

Matrix& sigmoid(const Matrix& x);
Matrix& sigmoidDerivative(const Matrix& dInputs, const Matrix& outputs);
double& binaryCrossEntropyLoss(const Matrix& y, const Matrix& yHat);
Matrix& binaryCrossEntropyLossDerivative(const Matrix& y, const Matrix& dInputs);

#endif