#include "Affine.hpp"
#include <assert.h>
#include <iostream>

Affine::Affine(const unsigned int inputDim, const unsigned int outputDim){
  assert(inputDim > 0 && outputDim > 0);

  this->weight = Matrix(outputDim, inputDim);
  this->bias = Matrix(outputDim, 1);

  this->gradWeight = Matrix(outputDim, inputDim);
  this->gradBias = Matrix(outputDim, 1);
  this->initGrad();
}

void Affine::setRandom(const Matrix::Real scale){
  this->weight.setRandom(scale);
  this->bias.setRandom(scale);
}

// Implement this
Matrix Affine::forward(const Matrix& inputVec) const{
  return Matrix(); // Here
}

// Implement this
Matrix Affine::backward(const Matrix& inputVec, const Matrix& delOutputVec){
  return Matrix(); // Here
}

// Implement this
void Affine::sgd(const Matrix::Real learningRate){
  // Here

  this->initGrad();
}

void Affine::initGrad(){
  this->gradWeight.fill(0.0);
  this->gradBias.fill(0.0);
}
