#include "BigIntLib.h"
#include "BigFloatLib.h"

int main() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BIG INT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
    
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
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BIG FLOAT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
    
    BF::big_float first1("39848946646.254658");
    BF::big_float second1("-12238989465456213315548999.13256468947978975646548665");
    BF::big_float third3("9999999999999999999212323999999999999.999999999999999948651364548962158465999999");
    std::cout << "first number is " << first1 << "\n\n";
    std::cout << "second number is " << second1 << "\n\n";
    std::cout << "third number is " << third3 << "\n\n";
    std::cout << "first plus third is eqal to " << first1 + third3 << "\n\n";
    std::cout << "first multiple second is eqal to " << first1 * second1 << "\n\n";
    std::cout << "let's use increment ++ on third number: " << ++third3 << "\n\n";
    std::cout << "after ++ let's use increment -- on the third number: " << '\n' << --third3 << "\n\n";
    if (first1 > second1) {
        std::cout << "first greater than second" << "\n\n";
    }
    std::cout << "let's devide second by first, it will be eqal to " << '\n' << second1 / first1 << "\n\n";
    return 0;
}
