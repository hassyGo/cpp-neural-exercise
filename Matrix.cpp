#include "Matrix.hpp"
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

Rand Matrix::rnd;

Matrix::Matrix():
  row(0), col(0), data(0)
{}

Matrix::Matrix(const unsigned int row_, const unsigned int col_):
  row(row_), col(col_)
{
  assert(this->row > 0 && this->col > 0);

  this->data = new Matrix::Real[this->row*this->col];
  this->fill(0.0);
}

Matrix::Matrix(const Matrix& mat):
  row(mat.row), col(mat.col)
{
  this->data = new Matrix::Real[this->row*this->col];

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] = mat.data[i];
  }
}

Matrix::~Matrix(){
  if (this->data != 0){
    delete this->data;
    this->data = 0;
  }
}

// Implement this
Matrix::Real Matrix::coeff(const unsigned int row_, const unsigned int col_) const{
  assert(row_ >= 0 && row_ < this->row && col_ >= 0 && col_ < this->col);

  return 0.0; // Here
}

// Implement this
Matrix::Real& Matrix::coeffRef(const unsigned int row_, const unsigned int col_){
  assert(row_ >= 0 && row_ < this->row && col_ >= 0 && col_ < this->col);

  return this->data[0]; // Here
}

std::string Matrix::print_() const{
  std::ostringstream oss;

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    oss << " " << this->data[i];
  }

  return oss.str();
}

void Matrix::print() const{
  for (unsigned int i = 0; i < this->row; ++i){
    for (unsigned int j = 0; j < this->col; ++j){
      std::cout << "\t" <<  this->coeff(i, j);
    }

    std::cout << std::endl;
  }
}

void Matrix::fill(const Matrix::Real val){
  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] = val;
  }
}

void Matrix::setRandom(const Matrix::Real scale){
  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] = 2.0*Matrix::rnd.zero2one() - 1.0;
  }
}

// Implement this
Matrix::Real Matrix::sum() const{
  return 0.0; // Here
}

// Implement this
Matrix::Real Matrix::maxCoeff() const{
  return 0.0; // Here
}

// Implement this
Matrix::Real Matrix::dot(const Matrix& arg) const{
  assert(this->row == arg.row && this->col == arg.col);

  return 0.0; // Here
}

// Implement this
Matrix Matrix::transpose() const{
  //assert(this->row == this->col);

  Matrix output(this->col, this->row);

  // Here

  return output;
}

// Implement this
Matrix Matrix::operator + (const Matrix& arg) const{
  assert(this->row == arg.row && this->col == arg.col);

  Matrix output(this->row, this->col);

  // Here

  return output;
}

Matrix Matrix::operator * (const Matrix::Real val) const{
  Matrix output(*this);

  output *= val;

  return output;
}

// Implement this
Matrix Matrix::operator * (const Matrix& arg) const{
  assert(this->col == arg.row);

  Matrix output(this->row, arg.col);

  // Here

  return output;
}

void Matrix::operator = (const Matrix& arg){
  if (this->row != arg.row || this->col != arg.col){
    this->row = arg.row;
    this->col = arg.col;

    if (this->data != 0){
      delete this->data;
    }

    this->data = new Matrix::Real[this->row*this->col];
  }

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] = arg.data[i];
  }
}

void Matrix::operator += (const Matrix& arg){
  assert(this->row == arg.row && this->col == arg.col);

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] += arg.data[i];
  }
}

void Matrix::operator -= (const Matrix& arg){
  assert(this->row == arg.row && this->col == arg.col);

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] -= arg.data[i];
  }
}

void Matrix::operator += (const Matrix::Real val){
  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] += val;
  }
}

void Matrix::operator -= (const Matrix::Real val){
  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] -= val;
  }
}

void Matrix::operator *= (const Matrix::Real val){
  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] *= val;
  }
}

void Matrix::operator /= (const Matrix::Real val){
  Matrix::Real val_ = 1.0/val;

  for (unsigned int i = 0; i < this->row*this->col; ++i){
    this->data[i] *= val_;
  }
}

Matrix Matrix::tanh() const{
  Matrix output(*this);

  for (unsigned int i = 0; i < output.row*output.col; ++i){
    output.data[i] = ::tanh(output.data[i]);
  }

  return output;
}

// Implement this
Matrix Matrix::softmax() const{
  Matrix output(*this);

  // Here

  return output;
}
