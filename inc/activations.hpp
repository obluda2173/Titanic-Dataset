#ifndef ACTIVATIONS_HPP
#define ACTIVATIONS_HPP

#include <cmath>

#include "matrix.hpp"

Matrix sigmoid(Matrix x);
Matrix sigmoidDerivative(Matrix dInputs, Matrix outputs);
double binaryCrossEntropyLoss(Matrix y, Matrix yHat);
Matrix binaryCrossEntropyLossDerivative(Matrix y, Matrix dInputs);

#endif