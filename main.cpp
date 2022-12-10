#include "BigIntLib.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    BI::big_int first("132321321564648985132134869854321321");
    BI::big_int second(132131546498478);
    BI::big_int third("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    std::cout << "first number is " << first << "\n\n";
    std::cout << "second number is " << second << "\n\n";
    std::cout << "third number is " << third << "\n\n";
    std::cout << "first plus third is eqal to " << first + third << "\n\n";
    std::cout << "first multiple second is eqal to " << first * second << "\n\n";
    std::cout << "let's use increment ++ on third number: " << ++third << "\n\n";
    std::cout << "after ++ let's use increment -- on the third number: " << '\n' << --third << "\n\n";
    if (first > second) {
        std::cout << "first greater than second" << "\n\n";
    }
    std::cout << "let's devide third by second, it will be eqal to " << '\n' << third / second << "\n\n";
    std::cout << "the remainder of this division will be " << third % second << "\n\n";
    return 0;
}
