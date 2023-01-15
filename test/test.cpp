#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string input = "1/2x⁶ + 3x² + 5x - 2 -1x³ -2x^2 -           2.2x⁵";
    std::regex pattern("((?:[+-]\\s*)?(?:\\d+\\.?\\d*|\\.\\d+)(?:[eE][+-]?\\d+)?(?:/(?:\\d+\\.?\\d*|\\.\\d+)(?:[eE][+-]?\\d+)?)?)(?:x((?:\\^[+-]?\\d+)|[¹²³⁴⁵⁶⁷⁸⁹⁰])?)?", std::regex::ECMAScript|std::regex::icase);
    std::sregex_iterator it(input.begin(), input.end(), pattern);
    std::sregex_iterator it_end;

    while (it != it_end) {
        std::smatch match = *it;
        std::cout << match.str() << std::endl;
        ++it;
    }

    return 0;
}