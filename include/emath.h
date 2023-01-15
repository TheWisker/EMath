#include <complex>
#include <cmath>
#include <vector>
#include <string>

class Arithmetic {
    public:
        static void get_divisors(double n, std::vector<double>& v) noexcept;
};

class Monomial {
    public:
        Monomial(const int dgr, const double cf) noexcept; //Constructor
        Monomial(const Monomial& ogn) noexcept; //Copy constructor
        Monomial(Monomial&& ogn) noexcept; //Move constructor

        Monomial& operator =(Monomial ogn) noexcept; //Assigment operator
        Monomial& operator =(Monomial&& ogn) noexcept; //Move assigment operator

        Monomial operator +(Monomial ogn) const noexcept; //Addition operator
        Monomial operator -(Monomial ogn) const noexcept; //Substraction operator
        Monomial operator *(Monomial ogn) const noexcept; //Multiplication operator
        Monomial operator /(Monomial ogn) const noexcept; //Division operator

        Monomial& operator +=(const Monomial& ogn) noexcept; //Addition assigment operator
        Monomial& operator -=(const Monomial& ogn) noexcept; //Substraction assigment operator
        Monomial& operator *=(const Monomial& ogn) noexcept; //Multiplication assigment operator
        Monomial& operator /=(const Monomial& ogn) noexcept; //Division assigment operator
 
        int get_degree() const noexcept; //Degree getter
        double get_coeff() const noexcept; //Coefficient getter
        std::string get_expression() const noexcept; //String expression getter

    private:
        int degree;
        double coeff;
        std::string expression;

        void swap(Monomial& other) noexcept; //Swap function
        inline void refresh_expression() noexcept; //Update expression function
};

class Polynomial {
    public:
        Polynomial(const int dgr, const std::vector<Monomial> mns) noexcept; //Constructor
        Polynomial(const Polynomial& ogn) noexcept; //Copy constructor
        Polynomial(Polynomial&& ogn) noexcept; //Move constructor

        Polynomial& operator =(Polynomial ogn) noexcept; //Assigment operator
        Polynomial& operator =(Polynomial&& ogn) noexcept; //Move assigment operator

        Polynomial operator +(Polynomial ogn) const noexcept; //Addition operator
        Polynomial operator -(Polynomial ogn) const noexcept; //Substraction operator
        Polynomial operator *(Polynomial ogn) const noexcept; //Multiplication operator
        Polynomial operator /(Polynomial ogn) const noexcept; //Division operator

        Polynomial& operator +=(const Polynomial& ogn) noexcept; //Addition assigment operator
        Polynomial& operator -=(const Polynomial& ogn) noexcept; //Substraction assigment operator
        Polynomial& operator *=(const Polynomial& ogn) noexcept; //Multiplication assigment operator
        Polynomial& operator /=(const Polynomial& ogn) noexcept; //Division assigment operator

        int get_degree() const noexcept; //Degree getter
        std::vector<Monomial> get_monomials()  const noexcept; //Monomials getter
        std::string get_expression() const noexcept; //String expression getter

    private:
        int degree;
        std::vector<Monomial> monomials;
        std::string expression;

        void swap(Polynomial& ogn) noexcept; //Swap function
        inline void refresh_expression() noexcept; //Update expression function

        struct Values {
            public:
                int add_root();
                int add_point();
                const int get_roots();
                const double get_points();

            private:
                std::vector<double> roots;
                std::vector<double, double> points;

        };
};

class Algebra {
    public:
        //Data transformation
        static int parse_equation();
        static int serialize_equation(const double& ct, const std::vector<double>& co, std::string& v);

        //Equation solving
        static int solve_linear(const std::vector<double>& co, double& res);
        static int solve_quadratic(const std::vector<double>& co, std::vector<double>& res);
        static int solve_equation(const std::vector<double>& co, std::vector<double>& res); //Aberth method

        //Equation arithmetic
        static int add_equation();
        static int substract_equation();
        static int multiply_equation();
        static int divide_equation();

        //Equation evaluation
        static int evaluate_equation();

};