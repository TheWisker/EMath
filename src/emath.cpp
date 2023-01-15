#include "emath.h"

//--------------------------------------
//          ARITHMETIC CLASS
//--------------------------------------
//Divisors
void Arithmetic::get_divisors(double n, std::vector<double>& v) noexcept {
    double limit(std::sqrt(n));
    for (double i = 1; i <= limit; i++) {
        if (std::fmod(n, i) == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
}

//--------------------------------------
//            MONOMIAL CLASS
//--------------------------------------
//Constructor
Monomial::Monomial(const int dgr, const double cf) noexcept : degree(dgr), coeff(cf) {this->refresh_expression();}

//Copy constructor
Monomial::Monomial(const Monomial& ogn) noexcept : degree(ogn.degree), coeff(ogn.coeff), expression(ogn.expression) {} 

//Move constructor
Monomial::Monomial(Monomial&& ogn) noexcept : degree(std::move(ogn.degree)), coeff(std::move(ogn.coeff)), expression(std::move(ogn.expression)) {}

//Assigment operator
Monomial& Monomial::operator =(Monomial ogn) noexcept {
    this->swap(ogn);
    return *this;
}

//Move assigment operator
Monomial& Monomial::operator =(Monomial&& ogn) noexcept {
    this->swap(ogn);
    return *this;
}

//Arithmetic operators
Monomial Monomial::operator +(Monomial ogn) const noexcept {return ogn += *this;}
Monomial Monomial::operator -(Monomial ogn) const noexcept {return ogn -= *this;}
Monomial Monomial::operator *(Monomial ogn) const noexcept {return ogn *= *this;}
Monomial Monomial::operator /(Monomial ogn) const noexcept {return ogn /= *this;}

//Arithmetic assigment operators
Monomial& Monomial::operator +=(const Monomial& ogn) noexcept {
    if (this->degree != ogn.degree) {
        throw std::invalid_argument("Monomial degrees do not match");
    }
    this->coeff += ogn.coeff;
    this->refresh_expression();
    return *this;
}
Monomial& Monomial::operator -=(const Monomial& ogn) noexcept {
    if (this->degree != ogn.degree) {
        throw std::invalid_argument("Monomial degrees do not match");
    }
    this->coeff -= ogn.coeff;
    this->refresh_expression();
    return *this;
}
Monomial& Monomial::operator *=(const Monomial& ogn) noexcept {
    this->coeff *= ogn.coeff;
    this->degree += ogn.degree;
    this->refresh_expression();
    return *this;
}
Monomial& Monomial::operator /=(const Monomial& ogn) noexcept {
    if (coeff == 0) {
        throw std::invalid_argument("Divide by zero");
    }
    this->coeff /= ogn.coeff;
    this->degree -= ogn.degree;
    this->refresh_expression();
    return *this;
}

//Attributes getters (degree, coeff, expression)
int Monomial::get_degree() const noexcept {return this->degree;}
double Monomial::get_coeff() const noexcept {return this->coeff;}
std::string Monomial::get_expression() const noexcept {return this->expression;}

//Swap function for swapping data between two monomial objects
void Monomial::swap(Monomial& ogn) noexcept {
    if (this != &ogn) {
        std::swap(this->degree, ogn.degree);
        std::swap(this->coeff, ogn.coeff);
        std::swap(this->expression, ogn.expression);
    }
}

//Updates the expression to match the degree and coefficient attributes
inline void Monomial::refresh_expression() noexcept {
    this->expression = std::to_string(this->coeff) + "x^" + std::to_string(this->degree);
}

//--------------------------------------
//           POLYNOMIAL CLASS
//--------------------------------------
//Constructor
Polynomial::Polynomial(const int dgr, const std::vector<Monomial> mns) noexcept : degree(dgr), monomials(mns) {this->refresh_expression();}

//Copy constructor
Polynomial::Polynomial(const Polynomial& ogn) noexcept : degree(ogn.degree), monomials(ogn.monomials), expression(ogn.expression) {} 

//Move constructor
Polynomial::Polynomial(Polynomial&& ogn) noexcept : degree(std::move(ogn.degree)), monomials(std::move(ogn.monomials)), expression(std::move(ogn.expression)) {}

//Assigment operator
Polynomial& Polynomial::operator =(Polynomial ogn) noexcept {
    this->swap(ogn);
    return *this;
}

//Move assigment operator
Polynomial& Polynomial::operator =(Polynomial&& ogn) noexcept {
    this->swap(ogn);
    return *this;
}

//Arithmetic operators
Polynomial Polynomial::operator +(Polynomial ogn) const noexcept {return ogn += *this;}
Polynomial Polynomial::operator -(Polynomial ogn) const noexcept {return ogn -= *this;}
Polynomial Polynomial::operator *(Polynomial ogn) const noexcept {return ogn *= *this;}
Polynomial Polynomial::operator /(Polynomial ogn) const noexcept {return ogn /= *this;}

//Arithmetic assigment operators
Polynomial& Polynomial::operator +=(const Polynomial& ogn) noexcept {
    int k, kk;
    while(k < this->monomials.size()) {
        kk = 0;
        while(kk < ogn.monomials.size()) {
            if (ogn.monomials[kk].get_degree() == this->monomials[k].get_degree()) {break;}
            kk++;
        }
        this->monomials[k] += ogn.monomials[kk];
    }
    this->refresh_expression();
    return *this;
}
Polynomial& Polynomial::operator -=(const Polynomial& ogn) noexcept {
    int k, kk;
    while(k < this->monomials.size()) {
        kk = 0;
        while(kk < ogn.monomials.size()) {
            if (ogn.monomials[kk].get_degree() == this->monomials[k].get_degree()) {break;}
            kk++;
        }
        this->monomials[k] -= ogn.monomials[kk];
    }
    this->refresh_expression();
    return *this;
}
Polynomial& Polynomial::operator *=(const Polynomial& ogn) noexcept {
    for(int k = 0; k < this->monomials.size(); k++) {
        for(int kk = 0; kk < ogn.monomials.size(); kk++) {
            this->monomials[k] *= ogn.monomials[kk];
        }
    }
    this->refresh_expression();
    return *this;
}
Polynomial& Polynomial::operator /=(const Polynomial& ogn) noexcept {
    if (coeff == 0) {
        throw std::invalid_argument("Divide by zero");
    }
    this->coeff /= ogn.coeff;
    this->degree -= ogn.degree;
    this->refresh_expression();
    return *this;
}

//Attributes getters (degree, monomials, expression)
int Polynomial::get_degree() const noexcept {return this->degree;}
std::vector<Monomial> Polynomial::get_monomials() const noexcept {return this->monomials;}
std::string Polynomial::get_expression() const noexcept {return this->expression;}

//Swap function for swapping data between two polynomial objects
void Polynomial::swap(Polynomial& ogn) noexcept {
    if (this != &ogn) {
        std::swap(this->degree, ogn.degree);
        std::swap(this->monomials, ogn.monomials);
        std::swap(this->expression, ogn.expression);
    }
}

//Updates the expression to match the monomials attributes
inline void Polynomial::refresh_expression() noexcept {
    //this->expression = std::to_string(this->coeff) + "x^" + std::to_string(this->degree);
}






























Polynomial operator +(Polynomial ogn) const; //Addition math
Polynomial& operator +=(const Polynomial& ogn); //Addition assigment operator
Polynomial operator -(Polynomial ogn) const; //Substraction operator
Polynomial& operator -=(const Polynomial& ogn); //Substraction assigment operator
Polynomial operator *(Polynomial ogn) const; //Multiplication operator
Polynomial& operator *=(const Polynomial& ogn); //Multiplication assigment operator
Polynomial operator /(Polynomial ogn) const; //Division operator
Polynomial& operator /=(const Polynomial& ogn); //Division assigment operator

int get_degree() const noexcept;
std::vector<Monomial> get_monomials()  const noexcept;


Polynomial(const int dgr, const double cnt, const std::vector<double> cfs): degree(std::move(dgr)), constant(std::move(cnt)), coeffs(std::move(cfs)) {
    //Algebra::serialize_equation(constant, coeffs, univariate);
}

const int Polynomial::get_degree() {};
const double Polynomial::get_constant() {};
const std::vector<double> Polynomial::get_coeffs() {};



int Polynomial::Operations::add_root() {};
int Polynomial::Operations::add_point() {};
const int Polynomial::Operations::get_roots() {};
const double Polynomial::Operations::get_points() {};



/*
Equation::Equation(const int dgr, const double cnt, const std::vector<double> cfs) {
    this->degree(dgr);
    this->constant(cnt);
    this->coeffs(cfs);
}

/*
Equation::Equation (int deg, double co) : degree(deg), coefficients(co) {
    this->solve_model(this->coefficients, this->model);
    switch(this->degree) {
        case 1:
            this->solve_linear(this->coefficients, this->roots);
            break;
        case 2:
            if (this->solve_quadratic(this->coefficients, this->roots) == -1) {
                //No equation solution
                int xof;
            }
            break;
        default:
            std::cout << "3+ degree equations not supported yet!" << std::endl;
            break;
    }
}

static int Equation::solve_model(const std::vector<double>& co, std::string& res) {
    for (int i = co.size(); i > 0; i--) {
        res += co[i]; res += "x^"; res += i + " ";
    }
    res += co[0];
    return 0;
}

static int Equation::solve_linear(const std::vector<double>& co, double& res) {
    res = {-co[0]/co[1]};
    return 0;
}

//Make so that it appends to the end
static int Equation::solve_quadratic(const std::vector<double>& co, std::vector<double>& res) {
    double d(std::pow(co[1], 2) - 4 * co[2] * co[0]);

    if (d > 0) {
        res = {(-co[1] + std::sqrt(d)) / (2 * co[2]), (-co[1] - std::sqrt(d)) / (2 * co[2])};
        return 0;
    } else if (d == 0) {
        double x((-co[1] + std::sqrt(d)) / (2 * co[2]));
        res = {x, x};
        return 0;
    }
    return -1;
}

static int Equation::solve_equation(std::vector<double> co, std::vector<double>& res) {
    std::vector<double> divs = Equation::get_divisors(co[0]);
    double pnt;
    std::vector<double> co2;
    for(double div : divs) {
        this->evaluate_point(div, co, pnt);
        if (pnt == 0) {
            this->evaluate_ruffini(div, co, co2);
            if (co2.size() <= 2) {
                //this->solve_quadratic(co2,);
            }
        }
    }
}

static int Equation::evaluate_point(const double x, const std::vector<double>& co, double& res) {
    for (int i = 0; i < co.size(); i++) {
        res += std::pow(x, i+1) * co[i];
    }
    return 0;
}

static int Equation::evaluate_ruffini(const double x, const std::vector<double>& co, std::vector<double>& res) {
    res.insert(res.begin(), co[co.size()]);
    for(int i = co.size() - 1; i >= 0; i--) {
        res.insert(res.begin(), res[co.size()-i] + co[i]);
    }
    return 0;
}

static std::vector<double> Equation::get_divisors(double n) {
    
}*/