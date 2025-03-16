#include "matrix.hpp"


bool Matrix::checkSize(const Matrix& other) const {
	if (m_rows != other.getRows() && other.getCols() != 1) {
		return false;
	}
	else if (m_cols != other.getCols() && other.getRows() != 1) {
		return false;
	}

	return true;
}

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
	m_data.resize(rows, std::vector<double>(cols, 0.0));
}

Matrix::Matrix(const std::vector<std::vector<double>>& vector) : m_rows(vector.size()), m_cols(vector[0].size()) {
	m_data = vector;
}
Matrix::Matrix(const std::vector<double>& vector, int axis) {
	if (axis == 0) {
		m_data.resize(1, vector);
		m_rows = 1;
		m_cols = vector.size();
	}
	else if (axis == 1) {
		(*this).resize(vector.size(), 1, 0.0);
		for (int i = 0; (unsigned long)i < vector.size(); i++) {
			m_data[0][i] = vector[i];
		}
	}
}
Matrix::Matrix(double value) : m_rows(1), m_cols(1) {
	m_data.resize(1, std::vector<double>(1, value));
}

double& Matrix::operator()(int rows, int cols) {
	if (rows >= m_rows || cols >= m_cols) {
		throw std::invalid_argument("Error: Indexation out of bounds");
	}
	return m_data[rows][cols];
}
double Matrix::operator()(int rows, int cols) const {
	if (rows >= m_rows || cols >= m_cols) {
		throw std::invalid_argument("Error: Indexation out of bounds");
	}
	return m_data[rows][cols];
}

Matrix Matrix::dot(const Matrix& other) const {
	if (m_cols != other.getRows()) {
		throw std::invalid_argument("Error: | Dot | Number of collums in the first matrix must match the number of rows in the second matrix");
	}
	Matrix retMatrix(m_rows, other.getCols());
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < other.getCols(); j++) {
			for (int k = 0; k < m_cols; k++) {
				retMatrix(i, j) += m_data[i][k] * other(k, j);
			}
		}
	}
	return retMatrix;
}
Matrix Matrix::T() const {
	Matrix retMatrix(m_cols, m_rows);
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			retMatrix(j, i) = m_data[i][j];
		}
	}
	return retMatrix;
}

void Matrix::print() const {
	for (std::vector<double>row : m_data) {
		for (double element: row) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}
Matrix Matrix::operator+(const Matrix& other) const {
	if (!checkSize(other)) {
		throw std::invalid_argument("Error: | Add | Incorrect sizes");
	}

	Matrix retMatrix(m_rows, m_cols);

	int irow = other.getRows() > 1;
	int icol = other.getCols() > 1;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			retMatrix(i, j) = m_data[i][j] + other(i*irow, j*icol);
		}
	}
	return retMatrix;
}
Matrix Matrix::operator-(const Matrix& other) const {
	if (!checkSize(other)) {
		throw std::invalid_argument("Error: | Add | Incorrect sizes");
	}

	Matrix retMatrix(m_rows, m_cols);

	int irow = other.getRows() > 1;
	int icol = other.getCols() > 1;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			retMatrix(i, j) = m_data[i][j] - other(i*irow, j*icol);
		}
	}
	return retMatrix;
}
Matrix Matrix::operator*(const Matrix& other) const {
	if (!checkSize(other)) {
		throw std::invalid_argument("Error: | Add | Incorrect sizes");
	}

	Matrix retMatrix(m_rows, m_cols);

	int irow = other.getRows() > 1;
	int icol = other.getCols() > 1;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			retMatrix(i, j) = m_data[i][j] * other(i*irow, j*icol);
		}
	}
	return retMatrix;
}
Matrix Matrix::operator/(const Matrix& other) const {
	if (!checkSize(other)) {
		throw std::invalid_argument("Error: | Add | Incorrect sizes");
	}

	Matrix retMatrix(m_rows, m_cols);

	int irow = other.getRows() > 1;
	int icol = other.getCols() > 1;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			retMatrix(i, j) = m_data[i][j] / other(i*irow, j*icol);
		}
	}
	return retMatrix;
}


Matrix Matrix::sum() const {
	Matrix sum(1, 1);

	for (std::vector<double> row : m_data) {
		for (double element: row) {
			sum(0, 0) += element;
		}
	}
	return sum;
}

void Matrix::nRandomised(int rows, int cols) {
	std::srand(static_cast<unsigned>(std::time(0)));
	double rnd_nbr = -1 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 2));
	// std::cout << rnd_nbr << "\n";
	m_data.resize(rows, std::vector<double>(cols, rnd_nbr));
	m_cols = cols;
	m_rows = rows;
}

void Matrix::resize(int rows, int cols, double value) {
	m_data.resize(rows, std::vector<double>(cols, value));
	m_cols = cols;
	m_rows = rows;
}