/**
* @file emath.cpp
* @brief This is the main source file for the mathematical equation operations
* @details This file implements the functions declared in emath.h.\n
* It consists of two classes, the Monomial class and the Polynomial class.\n
* The Monomial class implements all the functions, operators, and properties for representing and operating monomials.\n
* The Polynomial class implements all the functions, operators, and properties for representing and operating polynomials.\n
**/
#include "emath.h"
/**
* @brief Gets the all the positive divisors for an integer.
* @param n The integer to get the divisors for.
* @param v The vector reference where to store the divisors.
**/
void emth::Arithmetic::get_divisors(int n, std::vector<int>& v) noexcept {
    int limit(std::sqrt(n));
    for (int i = 1; i <= limit; i++) {
        if (std::fmod(n, i) == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
    return;
}
/**
* @brief Default constructor for when initialized with no arguments
**/
emth::Monomial::Monomial() noexcept : coeff(0), degree(0) {}
/**
* @brief Normal constructor for initialization with coeff and degree
* @param cf The coefficient as a double.
* @param dgr The degree as a integer.
**/
emth::Monomial::Monomial(const double cf, const int dgr) noexcept : coeff(cf), degree(dgr) {}
/**
* @brief Copy constructor for when initialized with an lvalue Monomial object
* @param ogn The lvalue Monomial object.
**/
emth::Monomial::Monomial(const Monomial& ogn) noexcept : coeff(ogn.coeff), degree(ogn.degree) {}
/**
* @brief Move constructor for when initialized with an rvalue Monomial object
* @param ogn The rvalue Monomial object.
**/
emth::Monomial::Monomial(Monomial&& ogn) noexcept : coeff(std::move(ogn.coeff)), degree(std::move(ogn.degree)) {}
/**
* @brief Assigment operator overload for when called with an lvalue
* @param ogn The lvalue Monomial object.
* @return (Monomial&) A reference to the lvalue of the operation
**/
emth::Monomial& emth::Monomial::operator =(const emth::Monomial& ogn) noexcept {Monomial copy(ogn); this->swap(copy); return *this;}
/**
* @brief Move assigment operator overload for when called with an rvalue
* @param ogn The rvalue Monomial object.
* @return (Monomial&) A reference to the lvalue of the operation
**/
emth::Monomial& emth::Monomial::operator =(emth::Monomial&& ogn) noexcept {this->swap(ogn); return *this;}
/**
* @brief Equal logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If Monomial objects coefficients and degrees match.
* @return (false) If Monomial objects coefficients and degrees dont match. 
**/
bool emth::Monomial::operator ==(const emth::Monomial& ogn) const noexcept {return ((this->coeff == ogn.coeff) && (this->degree == ogn.degree));}
/**
* @brief Not equal logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If Monomial objects coefficients and degrees dont match.
* @return (false) If Monomial objects coefficients and degrees match. 
**/
bool emth::Monomial::operator !=(const emth::Monomial& ogn) const noexcept {return (!(*this == ogn));}
/**
* @brief Greater than logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If the Monomial object degree is greater than the degree of the passed Monomial.
* @return (false) If the Monomial object degree is equal or less than the degree of the passed Monomial.
**/
bool emth::Monomial::operator >(const emth::Monomial& ogn) const noexcept {return (this->degree > ogn.degree);};
/**
* @brief Less than logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If the Monomial object degree is less than the degree of the passed Monomial.
* @return (false) If the Monomial object degree is equal or greater than the degree of the passed Monomial.
**/
bool emth::Monomial::operator <(const emth::Monomial& ogn) const noexcept {return (this->degree < ogn.degree);};
/**
* @brief Greater or equal than logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If the Monomial object degree is greater or equal than the degree of the passed Monomial.
* @return (false) If the Monomial object degree is less than the degree of the passed Monomial.
**/
bool emth::Monomial::operator >=(const emth::Monomial& ogn) const noexcept {return (this->degree >= ogn.degree);};
/**
* @brief Less or equal than logic operator overload
* @param ogn The Monomial object to compare to.
* @return (true) If the Monomial object degree is less or equal than the degree of the passed Monomial.
* @return (false) If the Monomial object degree is greater than the degree of the passed Monomial.
**/
bool emth::Monomial::operator <=(const emth::Monomial& ogn) const noexcept {return (this->degree <= ogn.degree);};
/**
* @brief Addition operator overload
* @param ogn The Monomial object to add.
* @return (Monomial) A brand new Monomial that represents the result.
**/
emth::Monomial emth::Monomial::operator +(const emth::Monomial& ogn) const noexcept {return emth::Monomial(*this) += ogn;}
/**
* @brief Substraction operator overload
* @param ogn The Monomial object to substract by.
* @return (Monomial) A brand new Monomial that represents the result.
**/
emth::Monomial emth::Monomial::operator -(const emth::Monomial& ogn) const noexcept {return emth::Monomial(*this) -= ogn;}
/**
* @brief Multiplication operator overload
* @param ogn The Monomial object to multiply by.
* @return (Monomial) A brand new Monomial that represents the result.
**/
emth::Monomial emth::Monomial::operator *(const emth::Monomial& ogn) const noexcept {return emth::Monomial(*this) *= ogn;}
/**
* @brief Division operator overload
* @param ogn The Monomial object to divide by.
* @return (Monomial) A brand new Monomial that represents the result.
**/
emth::Monomial emth::Monomial::operator /(const emth::Monomial& ogn) const noexcept {return emth::Monomial(*this) /= ogn;}
/**
* @brief Modulus operator overload
* @param ogn The Monomial object to divide by.
* @return (Monomial) A brand new Monomial that represents the result.
**/
emth::Monomial emth::Monomial::operator %(const emth::Monomial& ogn) const noexcept {return emth::Monomial(*this) %= ogn;}
/**
* @brief Addition assigment operator overload
* @param ogn The Monomial object to add.
* @return (Monomial&) A reference to the lvalue of the operation.
**/
emth::Monomial& emth::Monomial::operator +=(const emth::Monomial& ogn) noexcept {
    if ((this->degree == ogn.degree) || this->coeff == 0) {
        if (this->coeff == 0) {this->degree = ogn.degree;}
        this->coeff += ogn.coeff;
    }
    return *this;
}
/**
* @brief Substraction assigment operator overload
* @param ogn The Monomial object to substract by.
* @return (Monomial&) A reference to the lvalue of the operation.
**/
emth::Monomial& emth::Monomial::operator -=(const emth::Monomial& ogn) noexcept {
    if ((this->degree == ogn.degree) || this->coeff == 0) {
        if (this->coeff == 0) {this->degree = ogn.degree;}
        this->coeff -= ogn.coeff;
    }
    return *this;
}
/**
* @brief Multiplication assigment operator overload
* @param ogn The Monomial object to multiply by.
* @return (Monomial&) A reference to the lvalue of the operation.
**/
emth::Monomial& emth::Monomial::operator *=(const emth::Monomial& ogn) noexcept {
    this->coeff *= ogn.coeff;
    this->degree += ogn.degree;
    return *this;
}
/**
* @brief Division assigment operator overload
* @param ogn The Monomial object to divide by.
* @return (Monomial&) A reference to the lvalue of the operation.
**/
emth::Monomial& emth::Monomial::operator /=(const emth::Monomial& ogn) noexcept {
    if (ogn.coeff != 0) {
        this->coeff /= ogn.coeff;
        this->degree -= ogn.degree;
    }
    return *this;
}
/**
* @brief Modulus assigment operator overload
* @param ogn The Monomial object to divide by.
* @return (Monomial&) A reference to the lvalue of the operation.
**/
emth::Monomial& emth::Monomial::operator %=(const emth::Monomial& ogn) noexcept {
    if (ogn.coeff != 0) {
        this->coeff = std::fmod(this->coeff, ogn.coeff);
        this->degree -= ogn.degree;
    }
    return *this;
}
/**
* @brief A friend operator to insert the Monomial into a std::stringstream
* @param ss The std::stringstream.
* @param m The Monomial object to insert.
* @return (std::stringstream&) A reference to the std::stringstream.
**/
std::stringstream& emth::operator<<(std::stringstream& ss, const emth::Monomial& m) {ss << m.coeff << "x^" << m.degree; return ss;}
/**
* @brief A friend operator to insert the Monomial into a std::ostream
* @param out The std::ostream.
* @param m The Monomial object to insert.
* @return (std::ostream&) A reference to the std::ostream.
**/
std::ostream& emth::operator<<(std::ostream& out, const emth::Monomial& m) {out << m.coeff << "x^" << m.degree; return out;}
/**
* @brief Getter function for getting the degree of the Monomial
* @return (int) The degree of the Monomial.
**/
int emth::Monomial::get_degree() const noexcept {return this->degree;}
/**
* @brief Getter function for getting the coefficient of the Monomial
* @return (double) The coefficient of the Monomial.
**/
double emth::Monomial::get_coeff() const noexcept {return this->coeff;}
/**
* @brief Getter function for getting the expression of the Monomial
* @return (std::string) The expression of the Monomial.
**/
std::string emth::Monomial::get_expression() const noexcept {return (std::stringstream() << *this).str();}
/**
* @brief Calculus function for getting the value of the Monomial at a point
* @param x The point to evaluate.
* @return (double) The result of the evaluation of the Monomial.
**/
double emth::Monomial::get_value(const double& x) const noexcept {return (this->coeff * std::pow(x, this->degree));};
/**
* @brief The swap function for the copy-and-swap idiom implemented by the assigment operators
* @param ogn The other Monomial to swap the data with.
**/
void emth::Monomial::swap(emth::Monomial& ogn) noexcept {
    std::swap(this->coeff, ogn.coeff);
    std::swap(this->degree, ogn.degree);
    return;
}
/**
* @brief The class destructor
**/
emth::Monomial::~Monomial() = default;
/**
* @brief Default constructor for when initialized with no arguments
**/
emth::Polynomial::Polynomial() noexcept {this->monomials[0] = emth::Monomial(0, 0);}
/**
* @brief Normal constructor for initialization with a std::map<int, Monomial>
* @param mns The std::map<int, Monomial>.
**/
emth::Polynomial::Polynomial(const std::map<int, emth::Monomial> mns) noexcept : monomials(mns) {}
/**
* @brief List constructor for initialization with a std::initializer_list<Monomial>
* @param mns The std::initializer_list<Monomial>.
**/
emth::Polynomial::Polynomial(const std::initializer_list<emth::Monomial> mns) noexcept {for(const emth::Monomial& mn: mns) {this->monomials.emplace(mn.get_degree(), mn);}}
/**
* @brief Vector constructor for initialization with a std::vector<Monomial>
* @param mns The std::vector<Monomial>.
**/
emth::Polynomial::Polynomial(const std::vector<emth::Monomial> mns) noexcept {for(const emth::Monomial& mn: mns) {this->monomials.emplace(mn.get_degree(), mn);}}
/**
* @brief Copy constructor for when initialized with an lvalue Polynomial object
* @param ogn The lvalue Polynomial object.
**/
emth::Polynomial::Polynomial(const emth::Polynomial& ogn) noexcept : monomials(ogn.monomials) {} 
/**
* @brief Move constructor for when initialized with an rvalue Polynomial object
* @param ogn The rvalue Polynomial object.
**/
emth::Polynomial::Polynomial(emth::Polynomial&& ogn) noexcept : monomials(std::move(ogn.monomials)) {}
/**
* @brief Assigment operator overload for when called with an lvalue
* @param ogn The lvalue Polynomial object.
* @return (Polynomial&) A reference to the lvalue of the operation
**/
emth::Polynomial& emth::Polynomial::operator =(const emth::Polynomial& ogn) noexcept {emth::Polynomial copy(ogn); this->swap(copy); return *this;}
/**
* @brief Move assigment operator overload for when called with an rvalue
* @param ogn The rvalue Polynomial object.
* @return (Polynomial&) A reference to the lvalue of the operation
**/
emth::Polynomial& emth::Polynomial::operator =(emth::Polynomial&& ogn) noexcept {this->swap(ogn); return *this;}
/**
* @brief Equal logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If Polynomial objects degrees and monomials match.
* @return (false) If Polynomial objects degrees and monomials dont match. 
**/
bool emth::Polynomial::operator ==(const emth::Polynomial& ogn) const noexcept {return ((this->get_degree() == ogn.get_degree()) && (this->monomials == ogn.monomials));}
/**
* @brief Not equal logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If Polynomial objects degrees and monomials dont match.
* @return (false) If Polynomial objects degrees and monomials match. 
**/
bool emth::Polynomial::operator !=(const emth::Polynomial& ogn) const noexcept {return (!(*this == ogn));}
/**
* @brief Greater than logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If the Polynomial object degree is greater than the degree of the passed Polynomial.
* @return (false) If the Polynomial object degree is equal or less than the degree of the passed Polynomial.
**/
bool emth::Polynomial::operator >(const emth::Polynomial& ogn) const noexcept {return (this->get_degree() > ogn.get_degree());};
/**
* @brief Less than logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If the Polynomial object degree is less than the degree of the passed Polynomial.
* @return (false) If the Polynomial object degree is equal or greater than the degree of the passed Polynomial.
**/
bool emth::Polynomial::operator <(const emth::Polynomial& ogn) const noexcept {return (this->get_degree() < ogn.get_degree());};
/**
* @brief Greater or equal than logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If the Polynomial object degree is greater or equal than the degree of the passed Polynomial.
* @return (false) If the Polynomial object degree is less than the degree of the passed Polynomial.
**/
bool emth::Polynomial::operator >=(const emth::Polynomial& ogn) const noexcept {return (this->get_degree() >= ogn.get_degree());};
/**
* @brief Less or equal than logic operator overload
* @param ogn The Polynomial object to compare to.
* @return (true) If the Polynomial object degree is less or equal than the degree of the passed Polynomial.
* @return (false) If the Polynomial object degree is greater than the degree of the passed Polynomial.
**/
bool emth::Polynomial::operator <=(const emth::Polynomial& ogn) const noexcept {return (this->get_degree() <= ogn.get_degree());};
/**
* @brief Addition operator overload
* @param ogn The Polynomial object to add.
* @return (Polynomial) A brand new Polynomial that represents the result.
**/
emth::Polynomial emth::Polynomial::operator +(const emth::Polynomial& ogn) const noexcept {return emth::Polynomial(*this) += ogn;}
/**
* @brief Substraction operator overload
* @param ogn The Polynomial object to substract by.
* @return (Polynomial) A brand new Polynomial that represents the result.
**/
emth::Polynomial emth::Polynomial::operator -(const emth::Polynomial& ogn) const noexcept {return emth::Polynomial(*this) -= ogn;}
/**
* @brief Multiplication operator overload
* @param ogn The Polynomial object to multiply by.
* @return (Polynomial) A brand new Polynomial that represents the result.
**/
emth::Polynomial emth::Polynomial::operator *(const emth::Polynomial& ogn) const noexcept {return emth::Polynomial(*this) *= ogn;}
/**
* @brief Division operator overload
* @param ogn The Polynomial object to divide by.
* @return (Polynomial) A brand new Polynomial that represents the result.
**/
emth::Polynomial emth::Polynomial::operator /(const emth::Polynomial& ogn) const noexcept {return emth::Polynomial(*this) /= ogn;}
/**
* @brief Modulus operator overload
* @param ogn The Polynomial object to divide by.
* @return (Polynomial) A brand new Polynomial that represents the result.
**/
emth::Polynomial emth::Polynomial::operator %(const emth::Polynomial& ogn) const noexcept {return emth::Polynomial(*this) %= ogn;}
/**
* @brief Addition assigment operator overload
* @param ogn The Polynomial object to add.
* @return (Polynomial&) A reference to the lvalue of the operation.
**/
emth::Polynomial& emth::Polynomial::operator +=(const emth::Polynomial& ogn) noexcept {
    for(const std::pair<const int, emth::Monomial>& kv : ogn.monomials) {this->monomials[kv.first] += kv.second;}
    return this->redux();
}
/**
* @brief Substraction assigment operator overload
* @param ogn The Polynomial object to substract by.
* @return (Polynomial&) A reference to the lvalue of the operation.
**/
emth::Polynomial& emth::Polynomial::operator -=(const emth::Polynomial& ogn) noexcept {
    for(const std::pair<const int, emth::Monomial>& kv : ogn.monomials) {this->monomials[kv.first] -= kv.second;}
    return this->redux();
}
/**
* @brief Multiplication assigment operator overload
* @param ogn The Polynomial object to multiply by.
* @return (Polynomial&) A reference to the lvalue of the operation.
**/
emth::Polynomial& emth::Polynomial::operator *=(const emth::Polynomial& ogn) noexcept {
    std::map<int, emth::Monomial> rs;
    for(const std::pair<const int, emth::Monomial>& kv : this->monomials) {
        for(const std::pair<const int, emth::Monomial>& kkvv : ogn.monomials) {
            rs[kv.first + kkvv.first] += kv.second * kkvv.second;
        }
    }
    this->monomials = std::move(rs);
    return this->redux();
}
/**
* @brief Division assigment operator overload
* @param ogn The Polynomial object to divide by.
* @return (Polynomial&) A reference to the lvalue of the operation.
**/
emth::Polynomial& emth::Polynomial::operator /=(const emth::Polynomial& ogn) noexcept {
    if (!ogn.monomials.empty()) {
        emth::Polynomial quotient;
        while (!this->monomials.empty() && this->monomials.crbegin()->second.get_degree() >= ogn.monomials.crbegin()->second.get_degree()) {
            emth::Monomial mon = this->monomials.crbegin()->second / ogn.monomials.crbegin()->second;
            quotient.monomials[mon.get_degree()] = mon;
            *this -= (ogn * emth::Polynomial({mon}));
        }
        this->monomials = quotient.monomials;
    }
    return this->redux();
}
/**
* @brief Modulus assigment operator overload
* @param ogn The Polynomial object to divide by.
* @return (Polynomial&) A reference to the lvalue of the operation.
**/
emth::Polynomial& emth::Polynomial::operator %=(const emth::Polynomial& ogn) noexcept {
    if (!ogn.monomials.empty()) {
        while (!this->monomials.empty() && this->monomials.crbegin()->second.get_degree() >= ogn.monomials.crbegin()->second.get_degree()) {
            emth::Monomial mon = this->monomials.crbegin()->second / ogn.monomials.crbegin()->second;
            *this -= (ogn * emth::Polynomial({mon}));
        }
    }
    return this->redux();
}
/**
* @brief A friend operator to insert the Polynomial into a std::stringstream
* @param ss The std::stringstream.
* @param m The Polynomial object to insert.
* @return (std::stringstream&) A reference to the std::stringstream.
**/
std::stringstream& emth::operator<<(std::stringstream& ss, const emth::Polynomial& p) noexcept {
    for(std::reverse_iterator<std::map<const int, emth::Monomial>::const_iterator> it = p.monomials.crbegin(); it != p.monomials.crend(); it++) {ss << it->second << " ";}
    return ss;
}
/**
* @brief A friend operator to insert the Polynomial into a std::ostream
* @param out The std::ostream.
* @param m The Polynomial object to insert.
* @return (std::ostream&) A reference to the std::ostream.
**/
std::ostream& emth::operator<<(std::ostream& out, const emth::Polynomial& p) noexcept {
    for(std::reverse_iterator<std::map<const int, emth::Monomial>::const_iterator> it = p.monomials.crbegin(); it != p.monomials.crend(); it++) {out << it->second << " ";}
    return out;
}
/**
* @brief Getter function for getting the degree of the Polynomial
* @return (int) The degree of the Polynomial.
**/
int emth::Polynomial::get_degree() const noexcept {return this->monomials.crbegin()->first;}
/**
* @brief Getter function for getting the monomials of the Polynomial
* @return (std::map<int, Monomial>) The monomials of the Polynomial.
**/
std::map<int, emth::Monomial> emth::Polynomial::get_monomials() const noexcept {return this->monomials;}
/**
* @brief Getter function for getting the expression of the Polynomial
* @return (std::string) The expression of the Polynomial.
**/
std::string emth::Polynomial::get_expression() const noexcept {return (std::stringstream() << *this).str();}
/**
* @brief Calculus function for getting the value of the Polynomial at a point
* @param x The point to evaluate.
* @return (double) The result of the evaluation of the Polynomial.
**/
double emth::Polynomial::get_value(const double& x) const noexcept {
    double y = 0;
    for(const std::pair<const int, emth::Monomial>& kv: this->monomials) {y += kv.second.get_value(x);}
    return y;
};
/**
* @brief Calculus function for getting the derivative of the Polynomial
* @return (Polynomial) The result of the derivative of the Polynomial.
**/
emth::Polynomial emth::Polynomial::get_derivative() const noexcept {
    std::map<int, emth::Monomial> fdx;
    for(const std::pair<const int, emth::Monomial>& kv: this->monomials) {
        if (kv.second.get_degree() != 0) {fdx[kv.second.get_degree() - 1] = emth::Monomial(kv.second.get_coeff() * kv.second.get_degree(), kv.second.get_degree() - 1);}
    }
    return emth::Polynomial(std::move(fdx)).redux();
};
/**
* @brief Calculus function for getting the integral of the Polynomial
* @return (Polynomial) The result of the integral of the Polynomial.
**/
emth::Polynomial emth::Polynomial::get_integral() const noexcept {
    std::map<int, emth::Monomial> sdx;
    for(const std::pair<const int, emth::Monomial>& kv: this->monomials) {
        sdx[kv.second.get_degree() + 1] = emth::Monomial(kv.second.get_coeff() / (kv.second.get_degree() + 1), kv.second.get_degree() + 1);
    }
    return emth::Polynomial(std::move(sdx)).redux();
};
/**
* @brief The swap function for the copy-and-swap idiom implemented by the assigment operators
* @param ogn The other Polynomial to swap the data with.
**/
void emth::Polynomial::swap(emth::Polynomial& ogn) noexcept {
    std::swap(this->monomials, ogn.monomials);
    return;
}
/**
* @brief The redux function for removing the Monomials of zero coefficient
**/
emth::Polynomial& emth::Polynomial::redux() noexcept {
    std::vector<int> ks;
    for(const std::pair<const int, emth::Monomial>& kv: this->monomials) {
        if (kv.second.get_coeff() == 0) {ks.push_back(kv.first);}
    }
    for(int& k: ks) {this->monomials.erase(k);}
    return *this;
}
/**
* @brief The class destructor
**/
emth::Polynomial::~Polynomial() = default;