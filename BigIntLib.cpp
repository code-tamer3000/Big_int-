#include "BigIntLib.h"

BI::big_int& BI::big_int::operator *=(const big_int& other) {
    if (lenght == 1 && digits[0] == 0 || other.lenght == 1 && other.digits[0] == 0){
        *this = big_int(0);
        return *this;
    }

    if (lenght < other.lenght) {
        big_int copy = other;
        copy *= *this;
        *this = copy;
        return *this;
    }
    big_int answer;
    int overload = 0;
    
    for ( int i = 0; i < other.lenght; i++){
        big_int tmp(std::string(i, '0'));
        for (int j = 0 ; j < lenght; j++) {
            int digit = digits[j] * other.digits[i] + overload;
            overload = digit / 10;
            digit = digit % 10;
            tmp.digits.push_back(digit);
            ++tmp.lenght;
        }
        if (overload) {
            tmp.digits.push_back(overload);
            ++tmp.lenght;
        }
        overload = 0;
        answer += tmp;
    }
    if (is_positive != other.is_positive) {
        answer.is_positive = false;
    }
    *this = answer;
    return *this;
}

BI::big_int& BI::big_int::operator ++() {
    *this += big_int(1);
    return *this;
}

BI::big_int BI::big_int::operator ++(int) {
    big_int copy(*this);
    ++*this;
    return copy;
}

BI::big_int& BI::big_int::operator --() {
    *this -= big_int(1);
    return *this;
}

BI::big_int BI::big_int::operator --(int) {
    big_int copy(*this);
    --*this;
    return copy;
}

BI::big_int BI::operator -(const BI::big_int& first, const BI::big_int& second) {
    BI::big_int tmp(first);
    tmp -= second;
    return tmp;
}

BI::big_int BI::operator +(const BI::big_int& first, const BI::big_int& second) {
    BI::big_int tmp(first);
    tmp += second;
    return tmp;
}

BI::big_int BI::operator /(const BI::big_int& first, const BI::big_int& second) {
    BI::big_int tmp(first);
    tmp /= second;
    return tmp;
}

BI::big_int BI::operator *(const BI::big_int& first, const BI::big_int& second) {
    BI::big_int tmp(first);
    tmp *= second;
    return tmp;
}

BI::big_int& BI::big_int::operator -() {
    is_positive = !is_positive;
    return *this;
}

bool BI::big_int::operator <(const big_int& other) const{
    if (is_positive == other.is_positive) {
        if (lenght < other.lenght) {
            return is_positive ? true : false;
        } else if (lenght > other.lenght) {
            return is_positive ? false : true;
        } else {
           return (is_positive ? get_abs() < other.get_abs() : other.get_abs() < get_abs()); 
        }
    } else {
        return is_positive ? false : true;
    }
}

bool BI::big_int::operator ==(const big_int& other) const{
    if (is_positive == other.is_positive) {
        if (lenght == other.lenght) {
            return get_abs() == other.get_abs();
        }
    }   
    return false;        
}

bool BI::big_int::operator >(const big_int& other) const{ 
    return !(*this < other);        
}

bool BI::big_int::operator <=(const big_int& other) const{   
    return (*this < other || *this == other);        
}

bool BI::big_int::operator >=(const big_int& other) const{   
    return (*this > other || *this == other);        
}

bool BI::big_int::operator !=(const big_int& other) const{   
    return !(*this == other);        
}

BI::big_int& BI::big_int::operator -=(const big_int& other) {
    if (is_positive != other.is_positive) {
        big_int tmp = other;
        *this += -tmp;
        return *this;
    }
    if (*this < other && is_positive) {
        if (lenght < other.lenght) {
            digits.resize(other.lenght);
            lenght = other.lenght;
        }
        big_int tmp = other;
        *this = -(tmp -= *this);
        return *this;
    }
    int overload = 0;
    int i = 0;
    for ( ; i < other.lenght; i++) {
        int new_digit = digits[i] - other.digits[i] - overload;
        if (new_digit < 0) {
            overload = 1;
            new_digit = 10 + new_digit; 
        } else {
            overload = 0;
        }
        digits[i] = new_digit;
    }
    while (overload && i != lenght) {
        int new_digit = digits[i] - overload--;
        if (new_digit < 0) {
            new_digit = 10 + new_digit;
            ++overload; 
        }
        digits[i++] = new_digit;
    }
    int zeros  = lenght - 1;
    while (digits[zeros] == 0 && zeros != 0) {
        --zeros;
    }
    if (zeros != lenght - 1) {
        digits.resize(++zeros);
        lenght = zeros;
    }
    return *this;
}

BI::big_int& BI::big_int::operator +=(const big_int& other) {
    if (is_positive != other.is_positive) {
        big_int tmp = other;
        *this -= -tmp;
        return *this;
    }
    if (lenght < other.lenght) {
        digits.resize(other.lenght);
        lenght = other.lenght;
    }
    int overload = 0;
    int i = 0;
    for ( ; i < other.lenght; i++) {
        int new_digit = digits[i] + other.digits[i] + overload;
        digits[i] = new_digit % 10;
        overload = new_digit / 10;
    }
    while (overload && i < lenght) {
        int new_digit = digits[i] + overload;
        digits[i++] = new_digit % 10;
        overload = new_digit / 10;
    }
    if (overload) {
        digits.push_back(overload);
        ++lenght;
    }
    return *this;
}

BI::big_int& BI::big_int::operator /=(const big_int& other) {
    if ((lenght <= other.lenght && this->get_abs() < other.get_abs()) || (lenght == 1 && digits[0] == 0)) {
        *this = big_int(0);
        return *this;
    }
    if (other.lenght == 1 && other.digits[0] == 0) {
        throw std::overflow_error("Divide by zero exception");
    }
    if (this->get_abs() == other.get_abs()) {
        *this = big_int(1);
        return *this;
    }
    bool change = false;
    if (is_positive != other.is_positive) {
        if (is_positive) {
            big_int tmp(other);
            *this /= -tmp;
            -*this;
            return *this;
        } else {
            -*this;
            change = true;
        }
    }
    
    big_int answer(std::string(lenght - other.lenght, '0'));

    if (!is_positive) {
        -answer;
        -*this;
        change = true;
    }

    for (int i = answer.lenght - 1; i >= 0; i--) {
        while (answer * other < *this + big_int(1)) {
            ++answer.digits[i];
        }
        --answer.digits[i];
    }
    while (answer.lenght > 1 &&  !answer.digits.back()) {
            answer.digits.pop_back();
            --answer.lenght;
    }
    if (change) {
        -answer;
    }
    *this = answer;
    return *this;
}

BI::big_int& BI::big_int::operator= (const big_int& other) {
    lenght = other.lenght;
    is_positive = other.is_positive;
    digits = other.digits;
    return *this;
}

BI::big_int BI::operator %(const big_int& first, const big_int& second) {
    big_int tmp = first / second;
    if (tmp == big_int()) {
        tmp = big_int(first);
    } else {
        tmp = first - (tmp * second);
    }
    return tmp;
}

std::istream& BI::operator>>(std::istream& stream, BI::big_int& number) {
    std::string num;
    stream >> num;
    number = BI::big_int(num);
    return stream;
}

std::ostream& BI::operator<<(std::ostream& stream, const BI::big_int& number) {
    stream << number.get_number();
    return stream;
}

BI::big_int::big_int(std::string number) {
    if (number.empty()) {
        lenght = 0;
        is_positive = true;
        return;
    }
    if (number[0] == '-') {
        number = number.substr(1);
        is_positive = false;
    } else {
        is_positive = true;
    }
    lenght = number.length();
    for (int i = lenght - 1; i >= 0; i--){
            digits.push_back(number[i] - '0');
    }
}

BI::big_int::big_int(const char* number): big_int(std::string(number)) {};

BI::big_int::big_int(const char number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const unsigned char number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const short number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const unsigned short number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const int number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const unsigned int number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const long number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const unsigned long number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const long long number): big_int(std::to_string(number)) {};

BI::big_int::big_int(const unsigned long long number): big_int(std::to_string(number)) {};

std::string BI::big_int::get_number() const {
    std::string number;
    if (!is_positive) {
        number += '-';
    }
    for (int i = lenght - 1; i >= 0; --i){
        number += std::to_string(digits[i]);
    }
    return number;
}

std::string BI::big_int::get_abs() const {
    return is_positive ? get_number() : get_number().substr(1) ;
}
