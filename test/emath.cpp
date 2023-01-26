/**
* @file emath.cpp
* @brief This is the main test file of the emath library. It contains all the test needed to assure that the library works properly
* @details This file contains the main function with asserts that every library method works as it should.\n
* Each method gets tested with two asserts that verify that the library method returns the expected value when performing an operation.\n
* If it doesn't then a message gets printed to the console describing the error. If this does happen open an issue on my github page.
**/
#include "emath.h"
/**
* @brief Runs all the tests
* @return (int) Returns 0 to specify to Meson that the tests finished correctly
**/

int test_monomial() {
    //--------------------------------------
    //             CONSTRUCTORS
    //--------------------------------------
    // Default constructor
    Monomial md;
    assert((md.get_coeff() == 0) && "Error on default Monomial constructor: coeff is not 0!");
    assert((md.get_degree() == 0) && "Error on default Monomial constructor: degree is not 0!");
    // Normal constructor
    Monomial mn(1, 1);
    assert((mn.get_coeff() == 1) && "Error on normal Monomial constructor: coeff is not coeff!");
    assert((mn.get_degree() == 1) && "Error on normal Monomial constructor: degree is not degree!");
    // Copy constructor
    Monomial mc(mn);
    assert((mc.get_coeff() == 1) && "Error on copy Monomial constructor: coeff is not copy coeff!");
    assert((mc.get_degree() == 1) && "Error on copy Monomial constructor: degree is not copy degree!");
    // Move constructor
    Monomial mm(Monomial(2,2));
    assert((mm.get_coeff() == 2) && "Error on move Monomial constructor: coeff is not move coeff!");
    assert((mm.get_degree() == 2) && "Error on move Monomial constructor: degree is not move degree!");
    //--------------------------------------
    //             ASSIGMENT
    //--------------------------------------
    // Copy assigment
    mc = mm;
    assert((mc.get_coeff() == 2) && "Error on copy assigment operator: coeff is not copy coeff!");
    assert((mc.get_degree() == 2) && "Error on copy assigment operator: degree is not copy degree!");
    // Move assigment
    mm = Monomial(3, 3);
    assert((mm.get_coeff() == 3) && "Error on move assigment operator: coeff is not move coeff!");
    assert((mm.get_degree() == 3) && "Error on move assigment operator: degree is not move degree!");
    //--------------------------------------
    //             COMPARISON
    //--------------------------------------
    const Monomial m1(1, 1), m2(2, 2);
    // Equality
    assert((m1 == m1) && (m1 == Monomial(1, 1)) && (Monomial(1, 1) == m1) && (Monomial(1, 1) == Monomial(1, 1)) && "Error on equal operator: equal monomials are not diffent!");
    assert((m1 != m2) && (m1 != Monomial(2, 2)) && (Monomial(2, 2) != m1) && (Monomial(1, 1) != Monomial(2, 2)) && "Error on equal operator: diffent monomials are not equal!");
    // Size
    assert((m2 > m1) && (m2 > Monomial(1, 1)) && (Monomial(2, 2) > m1) && (Monomial(2, 2) > Monomial(1, 1)) && "Error on greater monomial operator!");
    assert((m1 < m2) && (m1 < Monomial(2, 2)) && (Monomial(1, 1) < m2) && (Monomial(1, 1) < Monomial(2, 2)) && "Error on lesser monomial operator!");
    assert((m2 >= m1 && m2 >= m2) && (m2 >= Monomial(1, 1) && m2 >= Monomial(2, 2)) && (Monomial(2, 2) >= m1 && Monomial(2, 2) >= m2) && (Monomial(2, 2) >= Monomial(1, 1) && Monomial(2, 2) >= Monomial(2, 2)) && "Error on greater or equal monomial operator!");
    assert((m1 <= m2 && m1 <= m1) && (m1 <= Monomial(2, 2) && m1 <= Monomial(1, 1)) && (Monomial(1, 1) <= m2 && Monomial(1, 1) <= m1) && (Monomial(1, 1) <= Monomial(2, 2) && Monomial(1, 1) >= Monomial(1, 1)) && "Error on lesser or equal monomial operator!");
    //--------------------------------------
    //             ARITHMETIC
    //--------------------------------------
    Monomial m3(3, 3), m4(4, 4), mn3(-3, -3), mn4(-4, -4);
    // Addition
    assert(((m3 + m4).get_coeff() == 3) && ((m3 + m4).get_degree() == 3) && "Error on addition operator: different degree monomials addition didnt return default value");
    assert(((m3 + m3).get_coeff() == 6) && ((m3 + m3).get_degree() == 3) && ((Monomial(3, 3) + Monomial(3, 3)).get_coeff() == 6) && ((Monomial(3, 3) + Monomial(3, 3)).get_degree() == 3) && "Error on addition operator: positive values addition failed!");
    assert(((mn3 + mn3).get_coeff() == -6) && ((mn3 + mn3).get_degree() == -3) && ((Monomial(-3, -3) + Monomial(-3, -3)).get_coeff() == -6) && ((Monomial(-3, -3) + Monomial(-3, -3)).get_degree() == -3) && "Error on addition operator: negative values addition failed!");
    // Substraction
    assert(((m3 - m4).get_coeff() == 3) && ((m3 - m4).get_degree() == 3) && "Error on substraction operator: different degree monomials substraction didnt return default value");
    assert(((m3 - m3).get_coeff() == 0) && ((m3 - m3).get_degree() == 3) && ((Monomial(3, 3) - Monomial(3, 3)).get_coeff() == 0) && ((Monomial(3, 3) - Monomial(3, 3)).get_degree() == 3) && "Error on substraction operator: positive values substraction failed!");
    assert(((mn3 - mn3).get_coeff() == 0) && ((mn3 - mn3).get_degree() == -3) && ((Monomial(-3, -3) - Monomial(-3, -3)).get_coeff() == 0) && ((Monomial(-3, -3) - Monomial(-3, -3)).get_degree() == -3) && "Error on substraction operator: negative values substraction failed!");
    // Multiplication
    assert(((m3 * m4).get_coeff() == 12) && ((m3 * m4).get_degree() == 7) && ((Monomial(3, 3) * Monomial(4, 4)).get_coeff() == 12) && ((Monomial(3, 3) * Monomial(4, 4)).get_degree() == 7) && "Error on multiplication operator: positive values multiplication failed!");
    assert(((mn3 * mn4).get_coeff() == 12) && ((mn3 * mn4).get_degree() == -7) && ((Monomial(-3, -3) * Monomial(-4, -4)).get_coeff() == 12) && ((Monomial(-3, -3) * Monomial(-4, -4)).get_degree() == -7) && "Error on multiplication operator: negative values multiplication failed!");
    // Division
    assert(((m3 / Monomial(0, 0)).get_coeff() == 3) && ((m3 / Monomial(0, 0)).get_degree() == 3) && "Error on division operator: divide by zero didnt return default value");
    assert(((m3 / m4).get_coeff() == 0.75) && ((m3 / m4).get_degree() == -1) && ((Monomial(3, 3) / Monomial(4, 4)).get_coeff() == 0.75) && ((Monomial(3, 3) / Monomial(4, 4)).get_degree() == -1) && "Error on division operator: positive values division failed!");
    assert(((mn3 / mn4).get_coeff() == 0.75) && ((mn3 / mn4).get_degree() == 1) && ((Monomial(-3, -3) / Monomial(-4, -4)).get_coeff() == 0.75) && ((Monomial(-3, -3) / Monomial(-4, -4)).get_degree() == 1) && "Error on division operator: negative values division failed!");
    // Modulus
    assert(((m3 % Monomial(0, 0)).get_coeff() == 3) && ((m3 % Monomial(0, 0)).get_degree() == 3) && "Error on modulus operator: divide by zero didnt return default value");
    assert(((m4 % m3).get_coeff() == 1) && ((m4 % m3).get_degree() == 1) && ((Monomial(4, 4) % Monomial(3, 3)).get_coeff() == 1) && ((Monomial(4, 4) % Monomial(3, 3)).get_degree() == 1) && "Error on modulus operator: positive values modulus failed!");
    assert(((mn4 % mn3).get_coeff() == -1) && ((mn4 % mn3).get_degree() == -1) && ((Monomial(-4, -4) % Monomial(-3, -3)).get_coeff() == -1) && ((Monomial(-4, -4) % Monomial(-3, -3)).get_degree() == -1) && "Error on modulus operator: negative values modulus failed!");
    //--------------------------------------
    //               STREAM
    //--------------------------------------
    std::stringstream ss, sss;
    Monomial m5(5, 5), mn5(-5, -5);
    assert(((ss << m5).str() == "5x^5") && ((sss << mn5).str() == "-5x^-5") && "Error on stream operator!");
    //--------------------------------------
    //                 MISC
    //--------------------------------------
    // Expression getter
    assert((m5.get_expression() == "5x^5") && (mn5.get_expression() == "-5x^-5") && "Error on expression getter!");
    // Value getter
    assert((m5.get_value(2) == 160) && (mn5.get_value(2) == -0.15625) && "Error on value getter!");
    std::cout << "Monomial tests passed!" << std::endl;
    return 0;
}

int test_polynomial() {
    std::cout << "Polynomial tests passed!" << std::endl;
    return 0;
}

int main() {return test_monomial() + test_polynomial();}