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

  std::ostringstream oss;
  oss << "A:" << A.print_() << "\t";
  oss << "B:" << B.print_() << "\t";
  oss << "C:" << C.print_() << "\t";
  oss << "D:" << D.print_() << "\t";
  oss << "E:" << E.print_() << "\t";
  oss << "F:" << F.print_() << "\t";
  oss << "G:" << G.print_() << "\t";
  
  //std::ofstream ofs("./test/TEST1.txt");
  //ofs << oss.str() << std::endl;

  std::ifstream ifs("./test/TEST1.txt");
  std::string line;
  std::getline(ifs, line);

  if (line == oss.str()){
    std::cout << "***** Passed the first test *****" << std::endl;
  }
  else {
    std::cout << "!!!!! Failed to pass the first test !!!!!" << std::endl;
  }
}

void test2(){
  std::cout << "!!!!! Failed to pass the second test !!!!!" << std::endl;
}

void test3(){
  std::cout << "!!!!! Failed to pass the third test !!!!!" << std::endl;
}
