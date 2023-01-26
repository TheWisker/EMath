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
Monomial Monomial::operator +(const Monomial& ogn) const noexcept {return Monomial(*this) += ogn;}
Monomial Monomial::operator -(const Monomial& ogn) const noexcept {return Monomial(*this) -= ogn;}
Monomial Monomial::operator *(const Monomial& ogn) const noexcept {return Monomial(*this) *= ogn;}
Monomial Monomial::operator /(const Monomial& ogn) const noexcept {return Monomial(*this) /= ogn;}
Monomial Monomial::operator %(const Monomial& ogn) const noexcept {return Monomial(*this) %= ogn;}

//Arithmetic assigment operators
Monomial& Monomial::operator +=(const Monomial& ogn) noexcept {
    if (this->degree == ogn.degree) {this->coeff += ogn.coeff;}
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
    if (ogn.coeff != 0) {
        this->coeff /= ogn.coeff;
        this->degree -= ogn.degree;
    }
    return *this;
}
Monomial& Monomial::operator %=(const Monomial& ogn) noexcept {
    if (ogn.coeff != 0) {
        this->coeff = std::fmod(this->coeff, ogn.coeff);
        this->degree -= ogn.degree;
    }
    return *this;
}

std::stringstream& operator<<(std::stringstream& ss, const Monomial& m) {ss << m.coeff << "x^" << m.degree; return ss;}
std::ostream& operator<<(std::ostream& out, const Monomial& m) {out << m.coeff << "x^" << m.degree; return out;}

//Attributes getters (degree, coeff, expression)
int Monomial::get_degree() const noexcept {return this->degree;}
double Monomial::get_coeff() const noexcept {return this->coeff;}
std::string Monomial::get_expression() const noexcept {return (std::stringstream() << *this).str();}

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