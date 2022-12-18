#include "BigFloatLib.h"







bool BF::big_float::operator ==(const big_float& other) const{
    if (is_positive == other.is_positive) {
        if (dot_pos == other.dot_pos) {
            return get_abs() == other.get_abs();
        }
    }   
    return false;        
}

bool BF::big_float::operator >(const big_float& other) const{ 
    return !(*this < other);        
}

bool BF::big_float::operator <=(const big_float& other) const{   
    return (*this < other || *this == other);        
}

bool BF::big_float::operator >=(const big_float& other) const{   
    return (*this > other || *this == other);        
}

bool BF::big_float::operator !=(const big_float& other) const{   
    return !(*this == other);        
}

BF::big_float& BF::big_float::operator --() {
    *this -= big_float(1);
    return *this;
}

BF::big_float BF::big_float::operator --(int) {
    big_float copy(*this);
    --*this;
    return copy;
}

BF::big_float BF::operator /(const BF::big_float& first, const BF::big_float& second) {
    BF::big_float tmp(first);
    tmp /= second;
    return tmp;
}

BF::big_float& BF::big_float::operator /=(const big_float& other) {
    long pos1 = lenght - dot_pos;
    long pos2 = other.lenght - other.dot_pos;
    if (pos1 < pos2) {
        number = BI::big_int(number.get_number() + std::string(pos2 - pos1, '0'));
    }
    BI::big_int answer; 
    answer = number / other.number;  
    lenght = answer.get_abs().length();
    dot_pos = lenght - pos2 - pos1;
    std::string ans = answer.get_abs();
    answer = number % other.number; 
    BI::big_int tmp;
    for (int i = 0; i < 20; i++) {
        answer *= BI::big_int(10);
        tmp = (answer) / other.number;
        ans += tmp.get_abs();
        answer = (answer) % other.number;
    }
    big_float an(ans);
    lenght = an.lenght;
    number = an.number;
    if (other.is_positive != is_positive) {
        if (is_positive) {
            is_positive = false;
        }
    } else if (other.is_positive == is_positive && !is_positive) {
        is_positive = true;
    }
    return *this;
    
}

BF::big_float BF::operator *(const BF::big_float& first, const BF::big_float& second) {
    BF::big_float tmp(first);
    tmp *= second;
    return tmp;
}

BF::big_float& BF::big_float::operator ++() {
    *this += big_float(1);
    return *this;
}

BF::big_float BF::big_float::operator ++(int) {
    big_float copy(*this);
    ++*this;
    return copy;
}

BF::big_float& BF::big_float::operator *=(const big_float& other) {
    long pos1 = lenght - dot_pos;
    long pos2 = other.lenght - other.dot_pos;
    number *= other.number;
    lenght = number.get_abs().length();
    dot_pos = lenght - pos1 - pos2;
    if (other.is_positive != is_positive) {
        if (is_positive) {
            is_positive = false;
        }
    } else if (other.is_positive == is_positive && !is_positive) {
        is_positive = true;
    }
    return *this;
}

BF::big_float BF::operator -(const BF::big_float& first, const BF::big_float& second) {
    BF::big_float tmp(first);
    tmp -= second;
    return tmp;
}

BF::big_float BF::operator +(const BF::big_float& first, const BF::big_float& second) {
    BF::big_float tmp(first);
    tmp += second;
    return tmp;
}

BF::big_float& BF::big_float::operator -=(const big_float& other) {
    if (is_positive != other.is_positive) {
        -*this += other;
        -*this;
        return *this;
    }
    long pos1 = lenght - dot_pos;
    long pos2 = other.lenght - other.dot_pos;
    long flag_lenght = std::max(pos1, pos2) + std::max(dot_pos, other.dot_pos);
    long set_dot = flag_lenght - std::max(pos1, pos2);
    if (pos1 < pos2) {
        number = BI::big_int(number.get_number() + std::string(pos2 - pos1, '0'));
    }
    if (pos1 > pos2) {
        BF::big_float tmp = other;
        tmp -= *this;
        *this = tmp;
        -*this;
        if (number < BI::big_int(0)) {
            -number;
        }
        return *this;
    }
    bool add_lenght = false; 
    if (get_abs()[0] == '0' && get_abs()[1] == '.') {
        add_lenght = true;
    }
    bool change_sign = false;
    if (number < other.number) {
        change_sign = true;
    }
    number -= other.number;
    lenght = number.get_abs().length();
    dot_pos = set_dot; 
    if (other.get_abs()[0] == '0' && other.get_abs()[1] == '.') {
        number = BI::big_int(std::string(1, '0') + number.get_abs());
        lenght++;
    }
    if (lenght > flag_lenght) {
        dot_pos--;
    }
    if (add_lenght) {
        number = BI::big_int(std::string(1, '0') + number.get_abs());
        lenght++;
    }
    if (change_sign) {
        -*this;
    }
    return *this;
}

bool BF::big_float::operator <(const big_float& other) const{
    if (is_positive == other.is_positive) {
        if (dot_pos < other.dot_pos) {
            return is_positive;
        } else if (dot_pos > other.dot_pos) {
            return !is_positive;
        } else {
            if (is_positive) {
                return get_abs() < other.get_abs();
            } else {
                return other.get_abs() < get_abs();
            }
        }
    } else {
        return !is_positive;
    }
}

BF::big_float& BF::big_float::operator -() {
    is_positive = !is_positive;
    return *this;
}
BF::big_float& BF::big_float::operator +=(const big_float& other) {
    if (is_positive != other.is_positive) {
        -*this -= other;
        -*this;
        return *this;
    }
    long pos1 = lenght - dot_pos;
    long pos2 = other.lenght - other.dot_pos;
    long flag_lenght = std::max(pos1, pos2) + std::max(dot_pos, other.dot_pos);
    long set_dot = flag_lenght - std::max(pos1, pos2);
    if (pos1 < pos2) {
        number = BI::big_int(number.get_number() + std::string(pos2 - pos1, '0'));
    }
    if (pos1 > pos2) {
        BF::big_float tmp = other;
        tmp += *this;
        *this = tmp;
        return *this;
    }
    number += other.number;
    lenght = number.get_abs().length();
    dot_pos = set_dot;
    if (lenght > flag_lenght) {
        dot_pos++;
    }
    return *this;
}

BF::big_float& BF::big_float::operator= (const big_float& other) {
    lenght = other.lenght;
    is_positive = other.is_positive;
    number = other.number;
    dot_pos = other.dot_pos;
    return *this;
}

std::istream& BF::operator>>(std::istream& stream, BF::big_float& number) {
    std::string num;
    stream >> num;
    number = BF::big_float(num);
    return stream;
}

std::ostream& BF::operator<<(std::ostream& stream, const BF::big_float& number) {
    stream << number.get_number();
    return stream;
}

BF::big_float::big_float(std::string number) {
    if (number.empty()) {
        lenght = 1;
        is_positive = true;
        this->number = BI::big_int(0);
        dot_pos = 1;
        return;
    }
    if (number[0] == '-') {
        is_positive = false;
        number = number.substr(1);
    } else {
        is_positive = true;
    }
    int pos = number.find('.');
    if (pos > 0) {
        dot_pos = pos;
        number.erase(pos, 1);
        lenght = number.length();
    } else {
        lenght = number.length();
        dot_pos = lenght;
    }
    this->number = BI::big_int(number);
}

BF::big_float::big_float(const char* number): BF::big_float(std::string(number)) {};

BF::big_float::big_float(const char number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const unsigned char number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const short number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const unsigned short number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const int number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const unsigned int number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const long number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const unsigned long number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const long long number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const unsigned long long number): BF::big_float(std::to_string(number)) {};

BF::big_float::big_float(const BI::big_int& number): BF::big_float(number.get_number()) {};

std::string BF::big_float::get_number() const {
    std::string answer;
    answer += number.get_abs();
    if (dot_pos == lenght) {
        answer += ".0";
    } else if (dot_pos == 0) {
        answer.insert(answer.begin(), '.');
        answer.insert(answer.begin(), '0');
    } else {
        answer.insert(answer.begin() + dot_pos, '.');
    }
    if (!is_positive) {
        answer.insert(answer.begin(), '-');
    }
    long tmp = answer.length() - 1;
    while (answer[tmp] == '0' && answer[--tmp] != '.') {
        answer.pop_back();
    }
    return answer;
}

std::string BF::big_float::get_abs() const {
    return is_positive ? get_number() : get_number().substr(1) ;
}
