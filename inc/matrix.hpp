#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Matrix {
private:
	std::vector<std::vector<double>> m_data;
	int m_rows, m_cols;

	bool checkSize(const Matrix& other) const;

public:
	Matrix(int rows, int cols);
	Matrix(const std::vector<std::vector<double>>& vector);
	Matrix(const std::vector<double>& vector, int axis);
	Matrix(double value);

	double& operator()(int rows, int cols);
	double operator()(int rows, int cols) const;
	

	Matrix dot(const Matrix& other) const;
	Matrix T() const;

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator/(const Matrix& other) const;

	//simple sum matrix that sums all values 
	//add direction to summing later
	Matrix sum() const;

	void nRandomised(int rows, int cols);
	void resize(int rows, int cols, double value);

	int getRows() const {return m_rows;}
    int getCols() const {return m_cols;}

	void print() const;
};

#endif