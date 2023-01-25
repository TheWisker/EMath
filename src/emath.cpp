/**
* @file emath.cpp
* @brief This is the main source file for the mathematical equation operations
* @details This file implements the functions declared in emath.h.\n
* It consist of two classes, the Monomial class and the Polynomial class.\n
* The Monomial class implements all the functions, operators, and properties for representing and operating monomials.\n
* The Polynomial class implements all the functions, operators, and properties for representing and operating polynomials.\n
**/
#include "emath.h"

//--------------------------------------
//          ARITHMETIC CLASS
//--------------------------------------
//Divisors
void Arithmetic::get_divisors(int n, std::vector<int>& v) noexcept {
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

//--------------------------------------
//            MONOMIAL CLASS
//--------------------------------------
//Default constructor
Monomial::Monomial() noexcept : coeff(0), degree(0) {}

//Constructor
Monomial::Monomial(const double cf, const int dgr) noexcept : coeff(cf), degree(dgr) {}

//Copy constructor
Monomial::Monomial(const Monomial& ogn) noexcept : coeff(ogn.coeff), degree(ogn.degree) {}

//Move constructor
Monomial::Monomial(Monomial&& ogn) noexcept : coeff(std::move(ogn.coeff)), degree(std::move(ogn.degree)) {}

//Assigment operator
Monomial& Monomial::operator =(const Monomial& ogn) noexcept {Monomial copy(ogn); this->swap(copy); return *this;}

//Move assigment operator
Monomial& Monomial::operator =(Monomial&& ogn) noexcept {this->swap(ogn); return *this;}

//Comparison operators
bool Monomial::operator ==(const Monomial& ogn) const noexcept {return ((this->coeff == ogn.coeff) && (this->degree == ogn.degree));} 
bool Monomial::operator !=(const Monomial& ogn) const noexcept {return (!(*this == ogn));}
bool Monomial::operator >(const Monomial& ogn) const noexcept {return (this->degree > ogn.degree);};
bool Monomial::operator <(const Monomial& ogn) const noexcept {return (this->degree < ogn.degree);};
bool Monomial::operator >=(const Monomial& ogn) const noexcept {return (this->degree >= ogn.degree);};
bool Monomial::operator <=(const Monomial& ogn) const noexcept {return (this->degree <= ogn.degree);};

//Arithmetic operators
Monomial Monomial::operator +(Monomial ogn) const noexcept {return ogn += *this;}
Monomial Monomial::operator -(Monomial ogn) const noexcept {return ogn -= *this;}
Monomial Monomial::operator *(Monomial ogn) const noexcept {return ogn *= *this;}
Monomial Monomial::operator /(Monomial ogn) const noexcept {return ogn /= *this;}
Monomial Monomial::operator %(Monomial ogn) const noexcept {return ogn %= *this;}

//Arithmetic assigment operators
Monomial& Monomial::operator +=(const Monomial& ogn) noexcept {
    if (this->degree != ogn.degree) {this->coeff += ogn.coeff;}
    return *this;
}
Monomial& Monomial::operator -=(const Monomial& ogn) noexcept {
    if (this->degree == ogn.degree) {this->coeff -= ogn.coeff;}
    return *this;
}
Monomial& Monomial::operator *=(const Monomial& ogn) noexcept {
    this->coeff *= ogn.coeff;
    this->degree += ogn.degree;
    return *this;
}
Monomial& Monomial::operator /=(const Monomial& ogn) noexcept {
    if (this->coeff != 0) {
        this->coeff /= ogn.coeff;
        this->degree -= ogn.degree;
    }
    return *this;
}
Monomial& Monomial::operator %=(const Monomial& ogn) noexcept {
    if (this->coeff != 0) {
        this->coeff = this->coeff - ogn.coeff * (this->coeff / ogn.coeff);
        this->degree -= ogn.degree;
    }
    return *this;
}

//Stream operator
std::ostream& Monomial::operator <<(std::ostream& out) {
    out << this->coeff << "x^" << this->degree;
    return out;
}

//Attributes getters (degree, coeff, expression)
int Monomial::get_degree() const noexcept {return this->degree;}
double Monomial::get_coeff() const noexcept {return this->coeff;}
std::string Monomial::get_expression() const noexcept {return std::to_string(this->coeff) + "x^" + std::to_string(this->degree);}

//Value for x getter
double Monomial::get_value(const double& x) const noexcept {return (this->coeff * std::pow(x, this->degree));};

//Swap function for swapping data between two monomial objects
void Monomial::swap(Monomial& ogn) noexcept {
    std::swap(this->coeff, ogn.coeff);
    std::swap(this->degree, ogn.degree);
    return;
}

//Destructor
Monomial::~Monomial() = default;

//--------------------------------------
//           POLYNOMIAL CLASS
//--------------------------------------
//Default constructor
Polynomial::Polynomial() noexcept {this->monomials.push_back(Monomial(0, 0));}

//Constructor
Polynomial::Polynomial(const std::vector<Monomial> mns) noexcept {set::sort(this->monomials, mns);}

//List Constructor
Polynomial::Polynomial(const std::initializer_list<Monomial> mns) noexcept {
    for(const Monomial& mn: mns) {this->monomials.push_back(mn);}
    set::sort(this->monomials, this->monomials);
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& ogn) noexcept : monomials(ogn.monomials) {} 

//Move constructor
Polynomial::Polynomial(Polynomial&& ogn) noexcept : monomials(std::move(ogn.monomials)) {}

//Assigment operator
Polynomial& Polynomial::operator =(const Polynomial& ogn) noexcept {Polynomial copy(ogn); this->swap(copy); return *this;}

//Move assigment operator
Polynomial& Polynomial::operator =(Polynomial&& ogn) noexcept {this->swap(ogn); return *this;}

//Comparison operators
bool Polynomial::operator ==(const Polynomial& ogn) const noexcept {return ((this->get_degree() == ogn.get_degree()) && (this->monomials == ogn.monomials));}
bool Polynomial::operator !=(const Polynomial& ogn) const noexcept {return (!(*this == ogn));}
bool Polynomial::operator >(const Polynomial& ogn) const noexcept {return (this->get_degree() > ogn.get_degree());};
bool Polynomial::operator <(const Polynomial& ogn) const noexcept {return (this->get_degree() < ogn.get_degree());};
bool Polynomial::operator >=(const Polynomial& ogn) const noexcept {return (this->get_degree() >= ogn.get_degree());};
bool Polynomial::operator <=(const Polynomial& ogn) const noexcept {return (this->get_degree() <= ogn.get_degree());};

//Arithmetic operators
Polynomial Polynomial::operator +(Polynomial ogn) const noexcept {return ogn += *this;}
Polynomial Polynomial::operator -(Polynomial ogn) const noexcept {return ogn -= *this;}
Polynomial Polynomial::operator *(Polynomial ogn) const noexcept {return ogn *= *this;}
Polynomial Polynomial::operator /(Polynomial ogn) const noexcept {return ogn /= *this;}
Polynomial Polynomial::operator %(Polynomial ogn) const noexcept {return ogn %= *this;}

//Arithmetic assigment operators
Polynomial& Polynomial::operator +=(const Polynomial& ogn) noexcept {
    std::unordered_map<int, double> mms;
    for (const Monomial& k : this->monomials) {mms[k.get_degree()] += k.get_coeff();}
    for (const Monomial& kk : ogn.monomials) {mms[kk.get_degree()] += kk.get_coeff();}
    this->monomials.clear();
    for (const std::pair<int, double>& kv : mms) {this->monomials.emplace_back(kv.second, kv.first);}
    this->monomials = set::sort(this->monomials, this->monomials);
    return *this;
}
Polynomial& Polynomial::operator -=(const Polynomial& ogn) noexcept {
    std::unordered_map<int, double> mms;
    for (const Monomial& k : this->monomials) {mms[k.get_degree()] -= k.get_coeff();}
    for (const Monomial& kk : ogn.monomials) {mms[kk.get_degree()] += kk.get_coeff();}
    this->monomials.clear();
    for (const std::pair<int, double>& kv : mms) {this->monomials.emplace_back(kv.second, kv.first);}
    this->monomials = set::sort(this->monomials, this->monomials);
    return *this;
}
Polynomial& Polynomial::operator *=(const Polynomial& ogn) noexcept {
    std::unordered_map<int, double> mms;
    for (const Monomial& k : this->monomials) {
        for (const Monomial& kk : ogn.monomials) {mms[k.get_degree() + kk.get_degree()] += k.get_coeff() * kk.get_coeff();}
    }
    this->monomials.clear();
    for (const std::pair<int, double>& kv : mms) {this->monomials.emplace_back(kv.second, kv.first);}
    this->monomials = set::sort(this->monomials, this->monomials);
    return *this;
}
Polynomial& Polynomial::operator /=(const Polynomial& ogn) noexcept {
    if (ogn.monomials.empty() || ogn.monomials[0].get_coeff() == 0) {throw std::invalid_argument("Divide by zero");}
    Polynomial rmd(std::move(this->monomials));
    while (rmd.monomials.size() >= ogn.monomials.size() && rmd.monomials.back().get_degree() >= ogn.monomials.back().get_degree()) {
        Monomial qmn = Monomial(rmd.monomials.back().get_degree() - ogn.monomials.back().get_degree(), rmd.monomials.back().get_coeff() / ogn.monomials.back().get_coeff());
        this->monomials.push_back(qmn);
        rmd -= (ogn * Polynomial(std::vector<Monomial>({this->monomials.back()})));
        while (rmd.monomials.size() > 0 && rmd.monomials.back().get_coeff() == 0) {rmd.monomials.pop_back();}
    }
    this->monomials = set::sort(this->monomials, this->monomials);
    return *this;
}
Polynomial& Polynomial::operator %=(const Polynomial& ogn) noexcept {
    if (ogn.monomials.empty() || ogn.monomials[0].get_coeff() == 0) {throw std::invalid_argument("Divide by zero");}
    Polynomial rmd(std::move(this->monomials));
    while (rmd.monomials.size() >= ogn.monomials.size() && rmd.monomials.back().get_degree() >= ogn.monomials.back().get_degree()) {
        Monomial qmn = Monomial(rmd.monomials.back().get_degree() - ogn.monomials.back().get_degree(), rmd.monomials.back().get_coeff() / ogn.monomials.back().get_coeff());
        this->monomials.push_back(qmn);
        rmd -= (ogn * Polynomial(std::vector<Monomial>({this->monomials.back()})));
        while (rmd.monomials.size() > 0 && rmd.monomials.back().get_coeff() == 0) {rmd.monomials.pop_back();}
    }
    this->monomials = set::sort(this->monomials, this->monomials);
    return *this;
}

std::ostream& Polynomial::operator<<(std::ostream &out) {
    if(this->monomials.empty()) {return out;}
    if(this->monomials.size() >= 2) {
        out << this->monomials.back().get_coeff() << "x^" << this->monomials.back().get_degree();
        for (int i = this->monomials.size() - 2; i > 0; i--) {
            out << ((this->monomials[i].get_coeff() >= 0) ? (" + " + std::to_string(this->monomials[i].get_coeff())) : (" - " + std::to_string(-this->monomials[i].get_coeff()))) << "x^" << i;
        }
    }
    out << ((this->monomials.front().get_coeff() >= 0) ? (" + " + std::to_string(this->monomials.front().get_coeff())) : (" - " + std::to_string(-this->monomials.front().get_coeff())));
    return out;
}

//Attributes getters (degree, monomials, expression)
int Polynomial::get_degree() const noexcept {return this->monomials.back().get_degree();}
std::vector<Monomial> Polynomial::get_monomials() const noexcept {return this->monomials;}
std::string Polynomial::get_expression() const noexcept {
    std::string expression = "";
    for (Monomial k: this->monomials) {expression += ((k.get_coeff() > 0) ? "+" + std::to_string(k.get_coeff()).erase(4) : std::to_string(k.get_coeff())).erase(3) + "x^" + std::to_string(k.get_degree()) + " ";}
    expression.pop_back();
    return expression;
}

//Value for x getter
double Polynomial::get_value(const double& x) const noexcept {
    double y = 0;
    for(const Monomial& m: this->monomials) {y += m.get_value(x);}
    return y;
};

Polynomial Polynomial::get_derivative() const noexcept {
    Polynomial fdx;
    for (Monomial k: this->monomials) {
        if (k.get_degree() != 0) {fdx.monomials.emplace_back(k.get_coeff() * k.get_degree(), k.get_degree() - 1);}
    }

    return fdx;
};

Polynomial Polynomial::get_integral() const noexcept {
    Polynomial sdx;
    for (Monomial k: this->monomials) {
        if (k.get_degree() != 0) {
            sdx.monomials.emplace_back(k.get_coeff() / (k.get_degree() + 1), k.get_degree() + 1);
        } else {
            sdx.monomials.emplace_back(k.get_coeff(), k.get_degree() + 1);
        }
    }
    return sdx;
};

//Swap function for swapping data between two polynomial objects
void Polynomial::swap(Polynomial& ogn) noexcept {
    std::swap(this->monomials, ogn.monomials);
    return;
}

Polynomial::~Polynomial() = default;


std::ostream& operator<<(std::ostream &out, const Polynomial &p) {
    if(p.get_monomials().empty()) {return out;}
    if(p.get_monomials().size() >= 2) {
        out << p.get_monomials().back().get_coeff() << "x^" << p.get_monomials().back().get_degree();
        for (int i = p.get_monomials().size() - 2; i > 0; i--) {
            out << ((p.get_monomials()[i].get_coeff() >= 0) ? (" + " + std::to_string(p.get_monomials()[i].get_coeff())) : (" - " + std::to_string(-p.get_monomials()[i].get_coeff()))) << "x^" << p.get_monomials()[i].get_degree();
        }
    }
    out << ((p.get_monomials().front().get_coeff() >= 0) ? (" + " + std::to_string(p.get_monomials().front().get_coeff())) : (" - " + std::to_string(-p.get_monomials().front().get_coeff())));
    return out;
}

int main() {
    std::cout << "Executing tests!" << std::endl;

    // Test constructors
    Polynomial p1;
    assert(p1.get_degree() == 0); // Default constructor should create a polynomial with degree 0

    std::cout << "First test passed!" << std::endl;

    Monomial m1(2, 3);
    Monomial m2(-1, 2);
    Monomial m3(4, 1);
    Monomial m4(5, 0);
    std::cout << "2 test passed!" << std::endl;
    std::vector<Monomial> monomials {m1, m2, m3, m4};
    std::cout << "3 test passed!" << std::endl;
    Polynomial p2(monomials);
    std::cout << "4 test passed!" << std::endl;
    assert(p2.get_degree() == 3); // Constructor with monomial vector should create a polynomial with highest degree of monomials

    std::cout << "Second test passed!" << std::endl;

    // Test assignment operator
    Polynomial p3;
    p3 = p2;
    assert(p3 == p2); // p3 should be a copy of p2

    std::cout << "Third test passed!" << std::endl;

    // Test addition operator
    Polynomial p4(monomials);
    Polynomial p5 = p2 + p4;
    assert(p5.get_monomials().back().get_coeff() == 4); // Coefficient of x^3 should be 4 after adding p2 and p4
    assert(p5.get_monomials()[2].get_coeff() == -2); // Coefficient of x^2 should be -2 after adding p2 and p4

    std::cout << "Fourth test passed!" << std::endl;

    // Test subtraction operator
    std::cout << p5 << std::endl;
    std::cout << p4 << std::endl;
    Polynomial p6 = p5 - p4;
    std::cout << p6 << std::endl;
    std::cout << p2 << std::endl;
    std::vector<Monomial> monomials_p6 = p6.get_monomials();
    assert(monomials_p6 == monomials); // p6 should be equal to p2 after subtracting p4 from p5

    std::cout << "Fifth test passed!" << std::endl;

    // Test multiplication operator
    Polynomial p7 = p5 * p4;
    std::vector<Monomial> monomials_p7 = p7.get_monomials();
    assert(monomials_p7[3].get_coeff() == 16); // Coefficient of x^6 should be 16 after multiplying p5 and p4
    assert(monomials_p7[2].get_coeff() == 8); // Coefficient of x^5 should be 8 after multiplying p5 and p4

    std::cout << "Sixth test passed!" << std::endl;

    // Test division operator
    Polynomial p8 = p7 / p5;
    std::vector<Monomial> monomials_p8 = p8.get_monomials();
    assert(monomials_p8 == monomials); // p8 should be equal to p4 after dividing p7 by p5

    std::cout << "Seventh test passed!" << std::endl;

    // Test modulus operator
    Polynomial p9 = p7 % p5;
    assert(p9.get_degree() == 0); // p9 should be a constant polynomial after taking modulus of p7 and p5

    std::cout << "Tenth test passed!" << std::endl;

    // Test derivative function
    Polynomial p10 = p7.get_derivative();
    std::vector<Monomial> monomials_p10 = p10.get_monomials();
    assert(monomials_p10[2].get_coeff() == 40); // Coefficient of x^5 should be 40 after taking derivative of p7
    assert(monomials_p10[1].get_coeff() == 24); // Coefficient of x^4 should be 24 after taking derivative of p7

    std::cout << "Eleventh test passed!" << std::endl;

    // Test integral function
    Polynomial p11 = p10.get_integral();
    std::vector<Monomial> monomials_p11 = p11.get_monomials();
    assert(monomials_p11[3].get_coeff() == 8); // Coefficient of x^6 should be 8 after taking integral of p10
    assert(monomials_p11[2].get_coeff() == 6); // Coefficient of x^5 should be 6 after taking integral of p10
    assert(monomials_p11[0].get_coeff() == 0); // Constant term should be 0 after taking integral of p10

    std::cout << "All test passed!" << std::endl;
    return 0;
}