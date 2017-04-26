#pragma once

#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void test1(){
  Matrix A(3, 4);
  Matrix B(4, 1);
  Matrix C(3, 1);

  A.fill(1.0);
  B.fill(10.0);
  C.fill(-2.0);
  A *= -3.0;
  A += 1.0;
  B -= 2.0;
  B /= 2.0;

  A.coeffRef(1, 0) = 1.0;
  A.coeffRef(2, 1) = 0.0;
  B.coeffRef(2, 0) = -1.0;
  C.coeffRef(1, 0) *= -1.0;

  Matrix D = A*B+C;
  Matrix E = A.transpose();
  Matrix F = E*C.dot(D);
  Matrix G = B.softmax();
  
  A.print();
  std::cout << std::endl;

  B.print();
  std::cout << std::endl;

  C.print();
  std::cout << std::endl;

  D.print();
  std::cout << std::endl;

  E.print();
  std::cout << std::endl;

  F.print();
  std::cout << std::endl;

  G.print();
  std::cout << std::endl;

  /*  
  std::ofstream a("./test/TEST1_A.txt");
  a << A.print_() << std::endl;
  std::ofstream b("./test/TEST1_B.txt");
  b << B.print_() << std::endl;
  std::ofstream c("./test/TEST1_C.txt");
  c << C.print_() << std::endl;
  std::ofstream d("./test/TEST1_D.txt");
  d << D.print_() << std::endl;
  std::ofstream e("./test/TEST1_E.txt");
  e << E.print_() << std::endl;
  std::ofstream f("./test/TEST1_F.txt");
  f << F.print_() << std::endl;
  std::ofstream g("./test/TEST1_G.txt");
  g << G.print_() << std::endl;
  */
  
  std::ifstream a("./test/TEST1_A.txt");
  std::ifstream b("./test/TEST1_B.txt");
  std::ifstream c("./test/TEST1_C.txt");
  std::ifstream d("./test/TEST1_D.txt");
  std::ifstream e("./test/TEST1_E.txt");
  std::ifstream f("./test/TEST1_F.txt");
  std::ifstream g("./test/TEST1_G.txt");
  std::string line;

  std::getline(a, line);
  if (line != A.print_()){
    std::cout << "Something is wrong with A!" << std::endl;
    std::cout << "Please check the coeff functions." << std::endl;
    exit(1);
  }

  std::getline(b, line);
  if (line != B.print_()){
    std::cout << "Something is wrong with B!" << std::endl;
    std::cout << "Please check the coeff functions." << std::endl;
    exit(1);
  }

  std::getline(c, line);
  if (line != C.print_()){
    std::cout << "Something is wrong with C!" << std::endl;
    std::cout << "Please check the coeff functions." << std::endl;
    exit(1);
  }

  std::getline(d, line);
  if (line != D.print_()){
    std::cout << "Something is wrong with D!" << std::endl;
    std::cout << "Please check the matrix-matrix multiplication or addition function." << std::endl;
    exit(1);
  }

  std::getline(e, line);
  if (line != E.print_()){
    std::cout << "Something is wrong with E!" << std::endl;
    std::cout << "Please check the transpose function." << std::endl;
    exit(1);
  }

  std::getline(f, line);
  if (line != F.print_()){
    std::cout << "Something is wrong with F!" << std::endl;
    std::cout << "Please check the dot function." << std::endl;
    exit(1);
  }

  std::getline(g, line);
  if (line != G.print_()){
    std::cout << "Something is wrong with G!" << std::endl;
    std::cout << "Please check the softmax function." << std::endl;
    exit(1);
  }
  
  std::cout << "***** Passed the first test *****" << std::endl;
}

void test2(){
  std::cout << "!!!!! Failed to pass the second test !!!!!" << std::endl;
}

void test3(){
  std::cout << "!!!!! Failed to pass the third test !!!!!" << std::endl;
}
