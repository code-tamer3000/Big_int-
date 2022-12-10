#pragma once 
#include <iostream>
#include <vector>
#include <string>
namespace BI {
    class big_int {
  public:

    //Конструкторы создания для всех целочисленных типов
    big_int() : lenght(1) , digits(1), is_positive(true) {};
    explicit big_int(std::string number);
    explicit big_int(const char* number);
    explicit big_int(const char number);
    explicit big_int(const unsigned char number);
    explicit big_int(const short number);
    explicit big_int(const unsigned short number);
    explicit big_int(const int number);
    explicit big_int(const unsigned int number);
    explicit big_int(const long number);
    explicit big_int(const unsigned long number);
    explicit big_int(const long long number);
    explicit big_int(const unsigned long long number);
    
    big_int& operator= (const big_int& other);

    //перегрузка арифметики 
    big_int& operator +=(const big_int& other); 
    big_int& operator -=(const big_int& other);
    big_int& operator *=(const big_int& other);
    big_int& operator /=(const big_int& other);
    big_int& operator ++();
    big_int operator ++(int);
    big_int& operator --();
    big_int operator --(int);
    big_int& operator -();

    //перегрузка сравнений
    bool operator <(const big_int& other) const;
    bool operator ==(const big_int& other) const;
    bool operator >(const big_int& other) const;
    bool operator <=(const big_int& other) const;
    bool operator >=(const big_int& other) const;
    bool operator !=(const big_int& other) const;

    //методы
    std::string get_number() const;
    std::string get_abs() const;  
    ~big_int() {};

  private:
    unsigned int lenght;
    bool is_positive;
    std::vector<int> digits;
};

big_int operator %(const big_int& first, const big_int& second);
std::istream& operator>>(std::istream& stream, big_int& number);
std::ostream& operator<<(std::ostream& stream, const big_int& number);
big_int operator -(const big_int& first, const big_int& second);
big_int operator +(const big_int& first, const big_int& second);
big_int operator /(const big_int& first, const big_int& second);
big_int operator *(const big_int& first, const big_int& second);
}

