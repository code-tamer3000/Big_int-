#pragma once
#include "BigIntLib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace BF {

class big_float {
public:

  //Конструкторы создания для численных типов
  big_float() : lenght(1), number(BI::big_int(0)), is_positive(true), dot_pos(1) {};
  explicit big_float(std::string number);
  explicit big_float(const char* number);
  explicit big_float(const char number);
  explicit big_float(const unsigned char number);
  explicit big_float(const short number);
  explicit big_float(const unsigned short number);
  explicit big_float(const int number);
  explicit big_float(const unsigned int number);
  explicit big_float(const long number);
  explicit big_float(const unsigned long number);
  explicit big_float(const long long number);
  explicit big_float(const unsigned long long number);
  explicit big_float(const BI::big_int& a);
 
    
  big_float& operator= (const big_float& other);

  //перегрузка арифметики 
  big_float& operator +=(const big_float& other); 
  big_float& operator -=(const big_float& other);
  big_float& operator *=(const big_float& other);
  big_float& operator /=(const big_float& other);
  big_float& operator ++();
  big_float operator ++(int);
  big_float& operator --();
  big_float operator --(int);
  big_float& operator -();

  //перегрузка сравнений
  bool operator <(const big_float& other) const;
  bool operator ==(const big_float& other) const;
  bool operator >(const big_float& other) const;
  bool operator <=(const big_float& other) const;
  bool operator >=(const big_float& other) const;
  bool operator !=(const big_float& other) const;

  //методы
  std::string get_number() const;
  std::string get_abs() const;  
  ~big_float() {};

private:
  unsigned int lenght;
  unsigned int dot_pos;
  bool is_positive;
  BI::big_int number;

};

std::istream& operator>>(std::istream& stream, big_float& number);
std::ostream& operator<<(std::ostream& stream, const big_float& number);
big_float operator -(const big_float& first, const big_float& second);
big_float operator +(const big_float& first, const big_float& second);
big_float operator /(const big_float& first, const big_float& second);
big_float operator *(const big_float& first, const big_float& second);

}
