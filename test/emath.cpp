/**
* @file emath.cpp
* @brief This is the main test file of the emath library. It contains all the tests needed to assure that the library works properly
* @details This file contains a main function that calls a function for the monomials and a function for the polynomials that test that every method works as it should.\n
* If it doesn't then a message gets printed to the console describing the error. If this does happen open an issue on my github page.
**/
#include <cassert>
#include <iostream>
#include "emath.h"
using namespace emth;
/**
* @brief Runs all the monomial class tests
* @return (int) Returns 0 to specify to Meson that the tests finished correctly
**/
int test_monomial() {
    //--------------------------------------
    //             CONSTRUCTORS
    //--------------------------------------
    // Default constructor
    Monomial md;
    assert((md.get_coeff() == 0) && "Error on default Monomial constructor: coeff is not default!");
    assert((md.get_degree() == 0) && "Error on default Monomial constructor: degree is not default!");
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
    // Well done!
    std::cout << "Monomial tests passed!" << std::endl;
    return 0;
}
/**
* @brief Runs all the polynomial class tests
* @return (int) Returns 0 to specify to Meson that the tests finished correctly
**/
int test_polynomial() {
    //--------------------------------------
    //             CONSTRUCTORS
    //--------------------------------------
    // Default constructor
    Polynomial pd;
    assert((pd.get_monomials().crbegin()->second.get_coeff() == 0) && "Error on default Polynomial constructor: monomial coeff is not default!");
    assert((pd.get_monomials().crbegin()->second.get_degree() == 0) && "Error on default Polynomial constructor: monomial degree is not default!");
    // Normal constructor
    Polynomial pn(std::map<int, Monomial>({{1, Monomial(1, 1)}}));
    assert((pn.get_monomials().crbegin()->second.get_coeff() == 1) && "Error on normal Polynomial constructor: monomial coeff is not coeff!");
    assert((pn.get_monomials().crbegin()->second.get_degree() == 1) && "Error on normal Polynomial constructor: monomial degree is not degree!");
    assert((pn.get_degree() == 1) && "Error on normal Polynomial constructor: polynomial degree is not degree!");
    // List constructor
    Polynomial pl({Monomial(1, 1), Monomial(2, 2)});
    assert((pl.get_monomials().crbegin()->second.get_coeff() == 2) && "Error on list Polynomial constructor: last monomial coeff is not coeff!");
    assert((pl.get_monomials().crbegin()->second.get_degree() == 2) && "Error on list Polynomial constructor: last monomial degree is not degree!");
    assert((pl.get_monomials().cbegin()->second.get_coeff() == 1) && "Error on list Polynomial constructor: first monomial coeff is not coeff!");
    assert((pl.get_monomials().cbegin()->second.get_degree() == 1) && "Error on list Polynomial constructor: first monomial degree is not degree!");
    assert((pl.get_degree() == 2) && "Error on list Polynomial constructor: polynomial degree is not degree!");
    // Vector constructor
    Polynomial pv(std::vector<Monomial>({Monomial(1, 1), Monomial(2, 2)}));
    assert((pv.get_monomials().crbegin()->second.get_coeff() == 2) && "Error on vector Polynomial constructor: last monomial coeff is not coeff!");
    assert((pv.get_monomials().crbegin()->second.get_degree() == 2) && "Error on vector Polynomial constructor: last monomial degree is not degree!");
    assert((pv.get_monomials().cbegin()->second.get_coeff() == 1) && "Error on vector Polynomial constructor: first monomial coeff is not coeff!");
    assert((pv.get_monomials().cbegin()->second.get_degree() == 1) && "Error on vector Polynomial constructor: first monomial degree is not degree!");
    assert((pv.get_degree() == 2) && "Error on vector Polynomial constructor: polynomial degree is not degree!");
    // Copy constructor
    Polynomial pc(pn);
    assert((pc.get_monomials().crbegin()->second.get_coeff() == 1) && "Error on copy Polynomial constructor: coeff is not copy coeff!");
    assert((pc.get_monomials().crbegin()->second.get_degree() == 1) && "Error on copy Polynomial constructor: degree is not copy degree!");
    assert((pc.get_degree() == 1) && "Error on copy Polynomial constructor: polynomial degree is not copy degree!");
    // Move constructor
    Polynomial pm(Polynomial(std::map<int, Monomial>({{2, Monomial(2, 2)}})));
    assert((pm.get_monomials().crbegin()->second.get_coeff() == 2) && "Error on move Polynomial constructor: coeff is not move coeff!");
    assert((pm.get_monomials().crbegin()->second.get_degree() == 2) && "Error on move Polynomial constructor: degree is not move degree!");
    assert((pm.get_degree() == 2) && "Error on move Polynomial constructor: polynomial degree is not move degree!");
    //--------------------------------------
    //             ASSIGMENT
    //--------------------------------------
    // Copy assigment
    pc = pm;
    assert((pc.get_monomials().crbegin()->second.get_coeff() == 2) && "Error on copy assigment operator: coeff is not copy coeff!");
    assert((pc.get_monomials().crbegin()->second.get_degree() == 2) && "Error on copy assigment operator: degree is not copy degree!");
    assert((pc.get_degree() == 2) && "Error on copy assigment operator: polynomial degree is not copy degree!");
    // Move assigment
    pm = Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}}));
    assert((pm.get_monomials().crbegin()->second.get_coeff() == 3) && "Error on move assigment operator: coeff is not move coeff!");
    assert((pm.get_monomials().crbegin()->second.get_degree() == 3) && "Error on move assigment operator: degree is not move degree!");
    assert((pm.get_degree() == 3) && "Error on move assigment operator: polynomial degree is not move degree!");
    //--------------------------------------
    //             COMPARISON
    //--------------------------------------
    const Polynomial p2(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})), p4(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}));
    // Equality
    assert((p2 == p2) && (p2 == Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) == p2) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) == Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && "Error on equal operator: equal monomials are not diffent!");
    assert((p2 != p4) && (p2 != Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && (Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) != p2) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) != Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && "Error on equal operator: diffent monomials are not equal!");
    // Size
    assert((p4 > p2) && (p4 > Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && (Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) > p2) && (Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) > Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && "Error on greater monomial operator!");
    assert((p2 < p4) && (p2 < Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) < p4) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) < Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && "Error on lesser monomial operator!");
    assert((p4 >= p2 && p4 >= p4) && (p4 >= Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) && p4 >= Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && (Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) >= p2 && Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) >= p4) && (Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) >= Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) && Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) >= Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}}))) && "Error on greater or equal monomial operator!");
    assert((p2 <= p4 && p2 <= p2) && (p2 <= Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) && p2 <= Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) <= p4 && Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) <= p2) && (Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) <= Polynomial(std::map<int, Monomial>({{3, Monomial(3, 3)}, {4, Monomial(4, 4)}})) && Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}})) >= Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(2, 2)}}))) && "Error on lesser or equal monomial operator!");
    //--------------------------------------
    //             ARITHMETIC
    //--------------------------------------
    Polynomial pn1(std::map<int, Monomial>({{1, Monomial(2, 1)}, {2, Monomial(2, 2)}})), pn3(std::map<int, Monomial>({{1, Monomial(2, 1)}, {3, Monomial(3, 3)}}));
    // Addition
    assert(pn1 + pn3 == Polynomial(std::map<int, Monomial>({{1, Monomial(4, 1)}, {2, Monomial(2, 2)}, {3, Monomial(3, 3)}})) && "Error on addition operator: wrong results");
    // Substraction
    assert(pn1 - pn3 == Polynomial(std::map<int, Monomial>({{2, Monomial(2, 2)}, {3, Monomial(-3, 3)}})) && "Error on substraction operator: wrong results");
    // Multiplication
    assert(pn1 * pn3 == Polynomial(std::map<int, Monomial>({{2, Monomial(4, 2)}, {3, Monomial(4, 3)}, {4, Monomial(6, 4)}, {5, Monomial(6, 5)}})) && "Error on multiplication operator: wrong results");
    // Division
    assert(pn3 / pn1 == Polynomial(std::map<int, Monomial>({{0, Monomial(-1.5, 0)}, {1, Monomial(1.5, 1)}})) && "Error on division operator: wrong results");
    // Modulus
    assert(pn3 % pn1 == Polynomial(std::map<int, Monomial>({{1, Monomial(5, 1)}})) && "Error on modulus operator: wrong results");
    //--------------------------------------
    //               STREAM
    //--------------------------------------
    std::stringstream ss;
    const Polynomial ps(std::map<int, Monomial>({{0, Monomial(1, 0)}, {1, Monomial(1, 1)}, {2, Monomial(1, 2)}}));
    assert(((ss << ps).str() == "1x^2 1x^1 1x^0 ") && "Error on stream operator!"); //"x^2 + x + 1"
    //--------------------------------------
    //                 MISC
    //--------------------------------------
    // Expression getter
    assert((ps.get_expression() == "1x^2 1x^1 1x^0 ") && "Error on expression getter!");
    // Value getter
    assert((ps.get_value(1) == 3) && (ps.get_value(2) == 7) && "Error on value getter!");
    //--------------------------------------
    //               CALCULUS
    //--------------------------------------
    // Derivative getter
    assert((ps.get_derivative() == Polynomial(std::map<int, Monomial>({{0, Monomial(1, 0)}, {1, Monomial(2, 1)}}))) && "Error on derivative getter!");
    // Integral getter
    assert((ps.get_integral() == Polynomial(std::map<int, Monomial>({{1, Monomial(1, 1)}, {2, Monomial(0.5, 2)}, {3, Monomial(1.0/3.0, 3)}}))) && "Error on integral getter!");
    // Well done!
    std::cout << "Polynomial tests passed!" << std::endl;
    return 0;
}
/**
* @brief Calls the monomial and polynomial tests
* @return (int) The sum of the test_monomial and test_polynomial function wich should be zero when all tests pass
**/
int main() {return test_monomial() + test_polynomial();}