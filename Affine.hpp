#pragma once

#include "Matrix.hpp"

class Affine{
public:
  Affine(const unsigned int inputDim, const unsigned int outputDim);

  void setRandom(const Matrix::Real scale);

  Matrix forward(const Matrix& inputVec) const;
  Matrix backward(const Matrix& inputVec, const Matrix& delOutputVec);
  void sgd(const Matrix::Real learningRate);

private:
  Matrix weight;
  Matrix bias;

  Matrix gradWeight;
  Matrix gradBias;

  void initGrad();
};
