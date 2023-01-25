#include <complex>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <string>
#include <set.h>

#include <iostream>
#include <cassert>

class Arithmetic {
    public:
        static void get_divisors(int n, std::vector<int>& v) noexcept;
};

/**
 * @class Monomial
 * @brief Class for representing and operating monomials
 * @details The class consists of the constructors, the operators, the getters, the properties and some private functions.
 */
class Monomial {
    public:
        Monomial() noexcept; //Default constructor
        Monomial(const double cf, const int dgr) noexcept; //Constructor
        Monomial(const Monomial& ogn) noexcept; //Copy constructor
        Monomial(Monomial&& ogn) noexcept; //Move constructor

        Monomial& operator =(const Monomial& ogn) noexcept; //Assigment operator
        Monomial& operator =(Monomial&& ogn) noexcept; //Move assigment operator

        bool operator ==(const Monomial& ogn) const noexcept; //Equal logic operator
        bool operator !=(const Monomial& ogn) const noexcept; //Not Equal logic operator
        bool operator >(const Monomial& ogn) const noexcept; //Greater than logic operator
        bool operator <(const Monomial& ogn) const noexcept; //Lesser than logic operator
        bool operator >=(const Monomial& ogn) const noexcept; //Greater or Equal than logic operator
        bool operator <=(const Monomial& ogn) const noexcept; //Lesser or Equal than logic operator

        Monomial operator +(Monomial ogn) const noexcept; //Addition operator
        Monomial operator -(Monomial ogn) const noexcept; //Substraction operator
        Monomial operator *(Monomial ogn) const noexcept; //Multiplication operator
        Monomial operator /(Monomial ogn) const noexcept; //Division operator
        Monomial operator %(Monomial ogn) const noexcept; //Modulus operator

        Monomial& operator +=(const Monomial& ogn) noexcept; //Addition assigment operator
        Monomial& operator -=(const Monomial& ogn) noexcept; //Substraction assigment operator
        Monomial& operator *=(const Monomial& ogn) noexcept; //Multiplication assigment operator
        Monomial& operator /=(const Monomial& ogn) noexcept; //Division assigment operator
        Monomial& operator %=(const Monomial& ogn) noexcept; //Modulus assigment operator

        std::ostream& operator <<(std::ostream& out); //Stream operator
       
        int get_degree() const noexcept; //Degree getter
        double get_coeff() const noexcept; //Coefficient getter
        std::string get_expression() const noexcept; //String expression getter

        double get_value(const double& x) const noexcept; //Value for x getter

        ~Monomial();
    private:
        double coeff;
        int degree;

        void swap(Monomial& other) noexcept; //Swap function
};

class Polynomial {
    public:
        Polynomial() noexcept; //Default constructor
        Polynomial(const std::vector<Monomial> mns) noexcept; //Constructor
        Polynomial(const std::initializer_list<Monomial> mns) noexcept; //List Constructor
        Polynomial(const Polynomial& ogn) noexcept; //Copy constructor
        Polynomial(Polynomial&& ogn) noexcept; //Move constructor

        Polynomial& operator =(const Polynomial& ogn) noexcept; //Assigment operator
        Polynomial& operator =(Polynomial&& ogn) noexcept; //Move assigment operator

        bool operator ==(const Polynomial& ogn) const noexcept; //Equal logic operator
        bool operator !=(const Polynomial& ogn) const noexcept; //Not equal logic operator
        bool operator >(const Polynomial& ogn) const noexcept; //Greater than logic operator
        bool operator <(const Polynomial& ogn) const noexcept; //Lesser than logic operator
        bool operator >=(const Polynomial& ogn) const noexcept; //Greater or Equal than logic operator
        bool operator <=(const Polynomial& ogn) const noexcept; //Lesser or Equal than logic operator

        Polynomial operator +(Polynomial ogn) const noexcept; //Addition operator
        Polynomial operator -(Polynomial ogn) const noexcept; //Substraction operator
        Polynomial operator *(Polynomial ogn) const noexcept; //Multiplication operator
        Polynomial operator /(Polynomial ogn) const noexcept; //Division operator
        Polynomial operator %(Polynomial ogn) const noexcept; //Modulus operator

        Polynomial& operator +=(const Polynomial& ogn) noexcept; //Addition assigment operator
        Polynomial& operator -=(const Polynomial& ogn) noexcept; //Substraction assigment operator
        Polynomial& operator *=(const Polynomial& ogn) noexcept; //Multiplication assigment operator
        Polynomial& operator /=(const Polynomial& ogn) noexcept; //Division assigment operator
        Polynomial& operator %=(const Polynomial& ogn) noexcept; //Modulus assigment operator

        std::ostream& operator <<(std::ostream& out); //Stream operator

        int get_degree() const noexcept; //Degree getter
        std::vector<Monomial> get_monomials()  const noexcept; //Monomials getter
        std::string get_expression() const noexcept; //String expression getter

        double get_value(const double& x) const noexcept; //Value for x getter

        Polynomial get_derivative() const noexcept;
        Polynomial get_integral() const noexcept;

        ~Polynomial();
    private:
        std::vector<Monomial> monomials;

        void swap(Polynomial& ogn) noexcept; //Swap function
};

namespace eqo {
    //Data transformation
    //int parse();
    
    int solve();
    int evaluate();
};