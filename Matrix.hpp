#pragma once

#include <string>

class Matrix{
public:
  typedef double Real;

  Matrix();
  Matrix(const unsigned int row_, const unsigned int col_);
  Matrix(const Matrix& mat);
  ~Matrix();

  Matrix::Real coeff(unsigned int row_, unsigned int col_) const; // return the value at (row_, col_)
  Matrix::Real& coeffRef(unsigned int row_, unsigned int col_); // return the reference to (row_, col_)

  std::string print_() const;
  void print() const;

  void fill(const Matrix::Real val);
  Matrix::Real sum() const;
  Matrix::Real maxCoeff() const;
  Matrix::Real dot(const Matrix& arg) const; // dot product: sum of element-wise products
  Matrix transpose() const; // transpose

  Matrix operator + (const Matrix& arg) const; // m1 = m2 + m3;
  Matrix operator * (const Matrix::Real val) const; // m1 = m2 * val;
  Matrix operator * (const Matrix& arg) const; // m1 = m2 * m3;

  void operator = (const Matrix& arg); // m1 = m2
  void operator += (const Matrix& arg); // m1 += m2;
  void operator -= (const Matrix& arg); // m1 -= m2;

  void operator += (const Matrix::Real val); // m += val;
  void operator -= (const Matrix::Real val); // m -= val;
  void operator *= (const Matrix::Real val); // m *= val;
  void operator /= (const Matrix::Real val); // m /= val;

  Matrix tanh() const; // element-wise tanh
  Matrix softmax() const; // softmax

private:
  unsigned int row;
  unsigned int col;

  Matrix::Real* data; // store matrix data in a one-dimensional array
};
