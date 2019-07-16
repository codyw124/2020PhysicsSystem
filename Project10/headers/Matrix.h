//Cody Ware
//1/8/19

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include "PhysicsHelper.h"

const size_t DEFAULT_MATRIX_DIMENSIONS = 4;

class Matrix
{
	public:
		Matrix();
		Matrix(const size_t& r, const size_t& c);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other) noexcept;
		~Matrix();		
		Matrix& operator=(const Matrix& other);
		Matrix& operator=(Matrix&& other) noexcept;
		std::vector<double>& operator[](const size_t& i);
		const std::vector<double>& operator[](const size_t& i) const;
		bool operator==(const Matrix& rhs) const;
		bool operator!=(const Matrix& rhs) const;
		Matrix& operator*=(const double& other);
		Matrix& operator*=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
		Matrix& operator-=(const Matrix& other);
		Matrix operator*(const double& scalar)const;
		Matrix operator*(const Matrix& other)const;
		Matrix operator+(const Matrix& other) const;
		Matrix operator-(const Matrix& other) const;

		void transpose();
		Matrix transposed() const;
		Matrix getCut(const size_t& row, const size_t& column);
		double getDeterminant();
		Matrix getMinors();
		double getMinor(const size_t& row, const size_t& column);
		Matrix getCofactors();
		double getCofactor(const size_t& row, const size_t& column);
		Matrix getAdjugate();
		Matrix getInverse();

		size_t getRows() const;
		size_t getColumns() const;
		
	private:
		void deepCopy(const Matrix& other);
		std::vector<std::vector<double>> data_;
		bool isSquare_;
};

std::ostream& operator<<(std::ostream& os, const Matrix& v);