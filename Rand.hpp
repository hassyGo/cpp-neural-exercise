#pragma once

class Rand{
public:
  static Rand r_;

  Rand(unsigned long w_ = 88675123):
    x(123456789), y(362436069), z(521288629), w(w_) {};

  unsigned long next();
  double zero2one();

private:
  unsigned long x;
  unsigned long y;
  unsigned long z;
  unsigned long w;
  unsigned long t; //tmp
};

inline unsigned long Rand::next(){
  this->t=(this->x^(this->x<<11));
  this->x=this->y;
  this->y=this->z;
  this->z=this->w;
  return (this->w=(this->w^(this->w>>19))^(this->t^(this->t>>8)));
}

inline double Rand::zero2one(){
  return ((this->next()&0xFFFF)+1)/65536.0;
}
