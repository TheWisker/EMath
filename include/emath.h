/**
* @mainpage EMath++ Project
* 
* @section intro Introduction
* 
* This is a project that aims to provide some wrapper classes for algebraic mathematical concepts.\n
* It includes the Monomial and Polynomial classes for general calculus, plus a Parser for transforming std::string to Polynomial objects.\n
* It also comes with a Termial interface for doing multiple operatios with polynomials: arithemtic, root finding, graphical representation.\n 
* The library is currently in expansion. It will include in the future support for Exponential, Trigonometric and Radical functions.\n
* Any feedback is much appreciated!
*
* @section libinstall Library Installation
* 
* The project comes with a folder with some bash files that complete some Meson related tasks.\n
* All bash files must be executed from the project's root directory to work properly.\n
* To install the project, it is only necessary to execute two files.\n
* Once installed, just include the emath.h or eparser.h header files in your code as needed, and link them with their implementation.
* 
* @subsection step1 Step one: Setup the Project
* 
* To setup the Meson project run the setup.sh bash file:
* @code
* bash ./scripts/setup.sh
* @endcode
* 
* @subsection step2 Step two: Install the Library
* 
* To install the emath library run the install.sh bash file:
* 
* @code
* bash ./scripts/install.sh
* @endcode
* 
* @note You will need a privileged user's credentials
* 
* @section test Testing
* 
* The project comes with some test files located in the test folder.\n
* To test that the library code works properly run the following bash file:
* @code
* bash ./scripts/test.sh
* @endcode
*
* @section terinstall Interface Installation
*
* The project comes with a folder with some bash files that complete some Meson related tasks.\n
* All bash files must be executed from the project's root directory to work properly.\n
* There are two ways to install the Interface, when following the Library Installation instructions or manually as explained here:
*
* @subsection istep1 Step one: Setup the Project
*
* To setup the Meson project run the setup.sh bash file:
* @code
* bash ./scripts/setup.sh
* @endcode
* 
* @subsection istep2 Step two: Compile the Interface
* 
* To compile the Interface run the compile.sh bash file:
* @code
* bash ./scripts/compile.sh
* @endcode
*
* @subsection istep3 Step three: Move to final directory
*
* To finish installing the Interface choose one of the two executable files: emath_cli_d or emath_cli_s.
* The executable ending in _d is the dynamic version and the one ending in _s is the static version.
*
* @note When installing to a Windows machine the executable files will have prefixed '.exe'
* @note If the dynamic version does not work try the static version: This could resolve missing dependencies
*
* @section terusage Interface Usage
*
* @subsection launching Launching the Interface
* 
* To launch the Interface just open a console and cd to the directory with the binaries:
* @code
* cd /path/to/emath_cli_dir
* ./emath_cli_d
* @endcode
*
* Or if they are in the PATH environment variable call them normally:
* @code
* emath_cli_d
* @endcode
*
* @note We will use emath_cli_d as the binary executable, but if you installed the static version you should call emath_cli_s instead
*
* @subsection adding Adding polynomials
*
* To add polynomials to the cache and consecuently be able to operate with them you should press 'e' on the main menu.
* Then you should write the polynomial in the following markup [ 3/2x^2 + 2*2.2x - 5 ] and press enter.
*
* @note If you have added toomany polynomials to the cache a scroll function will be enabled, cycle pressing tab on the main or operation menus until the polynomials window is focused and the press the arrow functions to scroll.
*
* @image html screenshot_one.png
*
* @subsection removing Removing polynomials
*
* To remove polynomials from the cache and consecuently delete them you should press 'q' on the main menu.
* Then you should write the number corresponding to the polynomial's index.
*
* @subsection operation New operation
*
* Once at least one polynomial has been added you can press space on the main menu to enter to the operation menu:
*
* @image html screenshot_three.png
* 
* Now you have a variety of choices: numbered different operations and arithmetic operations.
*
* @subsection arithmetic Arithmetic operation
*
* Once in the operation menu, you can press space again to input a arithmetic operation.
* Arithmetic operations consist of +, -, *, / operations beetwen the polynomial indexes.
* Here is an example of what you would input to multiply the polynomial with index 0 to the one with index 1
* and add to that what results the polynomial with index 2: [ 0 * 1 + 2 ]. Then the results will be printed, and you will ahve to press any key to continue.
*
* @note Higher grade operations like multiplication and division are computer before their lower grade counter parts addition and substraction
* @note If you want to save the resulting polynomial to cache write the '_' character as the first character and then write the rest of the operation normally
*
* @subsection evaluate Evaluate operation
*
* To get the value of y for some x, you make a evaluate operation. Press 1 on the operation menu, input the polynomial's index and then input the x's value.
*
* @subsection derint Derivative and Integral operation
*
* Both these operations are done in an indentical way: Press 2 or 3 respectively on the operation menu and then input the polynomial's index.
*
* @subsection root Root finding operation
*
* To find the real and complex roots of a polynomial when on the operation menu: Press 4 and then input the polynomial's index. The roots will be printed inside parenthesis.
*
* @image html screenshot_four.png
*
* @subsection draw Drawing operation
*
* To draw a polynomial in the Cartesian plane: Press 5 on the operation menu and then input the polynomial's index. A new window will open showing the polynomail on the Cartesian plane.
* You then can move with the arrow keys around the Cartesian plane and resize the window to expand the Cartesian plane.
*
* @image html screenshot_two.png
**/
/**
* @file emath.h
* @brief This is the main header file for the emath library
* @details This file declares the functions of the emath library.\n
* It consists of two classes, the Monomial class and the Polynomial class.\n
* The Monomial class declares all the functions, operators, and properties for representing and operating monomials.\n
* The Polynomial class declares all the functions, operators, and properties for representing and operating polynomials.\n
**/
#ifndef EMATH_H
#define EMATH_H
#include <map>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <unsupported/Eigen/Polynomials>
#include "set.h"
#pragma once
/**
 * @namespace emth
 * @brief Englobes all the classes and functions of the emath library
 * @details The emth namespace contains three classes: Arithmetic, Monomial and Polynomial. The first contains functions for arithmetic operations. The last two are wrappers on abstract algebraic concepts.
**/
namespace emth {
    #define R_TOL std::numeric_limits<double>::epsilon()
    #define R_ITR 1000
    /**
     * @class Arithmetic
     * @brief Class with some functions for arithmetic math
     * @details The class consists of the functions that operate with real numbers.
    **/
    class Arithmetic {
        public:
            /**
            * @brief Gets the all the positive divisors for an integer.
            * @param n The integer to get the divisors for.
            * @param v The vector reference where to store the divisors.
            **/
            static void get_divisors(int n, std::vector<int>& v) noexcept;
    };
    /**
     * @class Monomial
     * @brief Class for representing and operating monomials
     * @details The class consists of the constructors, the operators, the getters, the properties and some private functions.
    **/
    class Monomial {
        public:
            /**
            * @brief Default constructor for when initialized with no arguments
            **/
            Monomial() noexcept; //Default constructor
            /**
            * @brief Normal constructor for initialization with coeff and degree
            * @param cf The coefficient as a double.
            * @param dgr The degree as a integer.
            **/
            Monomial(const double cf, const int dgr) noexcept; //Constructor
            /**
            * @brief Copy constructor for when initialized with an lvalue Monomial object
            * @param ogn The lvalue Monomial object.
            **/
            Monomial(const Monomial& ogn) noexcept; //Copy constructor
            /**
            * @brief Move constructor for when initialized with an rvalue Monomial object
            * @param ogn The rvalue Monomial object.
            **/
            Monomial(Monomial&& ogn) noexcept; //Move constructor
            /**
            * @brief Assigment operator overload for when called with an lvalue
            * @param ogn The lvalue Monomial object.
            * @return (Monomial&) A reference to the lvalue of the operation
            **/
            Monomial& operator =(const Monomial& ogn) noexcept; //Assigment operator
            /**
            * @brief Move assigment operator overload for when called with an rvalue
            * @param ogn The rvalue Monomial object.
            * @return (Monomial&) A reference to the lvalue of the operation
            **/
            Monomial& operator =(Monomial&& ogn) noexcept; //Move assigment operator
            /**
            * @brief Equal logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If Monomial objects coefficients and degrees match.
            * @return (false) If Monomial objects coefficients and degrees dont match. 
            **/
            bool operator ==(const Monomial& ogn) const noexcept; //Equal logic operator
            /**
            * @brief Not equal logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If Monomial objects coefficients and degrees dont match.
            * @return (false) If Monomial objects coefficients and degrees match. 
            **/
            bool operator !=(const Monomial& ogn) const noexcept; //Not Equal logic operator
            /**
            * @brief Greater than logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If the Monomial object degree is greater than the degree of the passed Monomial.
            * @return (false) If the Monomial object degree is equal or less than the degree of the passed Monomial.
            **/
            bool operator >(const Monomial& ogn) const noexcept; //Greater than logic operator
            /**
            * @brief Less than logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If the Monomial object degree is less than the degree of the passed Monomial.
            * @return (false) If the Monomial object degree is equal or greater than the degree of the passed Monomial.
            **/
            bool operator <(const Monomial& ogn) const noexcept; //Less than logic operator
            /**
            * @brief Greater or equal than logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If the Monomial object degree is greater or equal than the degree of the passed Monomial.
            * @return (false) If the Monomial object degree is less than the degree of the passed Monomial.
            **/
            bool operator >=(const Monomial& ogn) const noexcept; //Greater or Equal than logic operator
            /**
            * @brief Less or equal than logic operator overload
            * @param ogn The Monomial object to compare to.
            * @return (true) If the Monomial object degree is less or equal than the degree of the passed Monomial.
            * @return (false) If the Monomial object degree is greater than the degree of the passed Monomial.
            **/
            bool operator <=(const Monomial& ogn) const noexcept; //Less or Equal than logic operator
            /**
            * @brief Addition operator overload
            * @param ogn The Monomial object to add.
            * @return (Monomial) A brand new Monomial that represents the result.
            **/
            Monomial operator +(const Monomial& ogn) const noexcept; //Addition operator
            /**
            * @brief Substraction operator overload
            * @param ogn The Monomial object to substract by.
            * @return (Monomial) A brand new Monomial that represents the result.
            **/
            Monomial operator -(const Monomial& ogn) const noexcept; //Substraction operator
            /**
            * @brief Multiplication operator overload
            * @param ogn The Monomial object to multiply by.
            * @return (Monomial) A brand new Monomial that represents the result.
            **/
            Monomial operator *(const Monomial& ogn) const noexcept; //Multiplication operator
            /**
            * @brief Division operator overload
            * @param ogn The Monomial object to divide by.
            * @return (Monomial) A brand new Monomial that represents the result.
            **/
            Monomial operator /(const Monomial& ogn) const noexcept; //Division operator
            /**
            * @brief Modulus operator overload
            * @param ogn The Monomial object to divide by.
            * @return (Monomial) A brand new Monomial that represents the result.
            **/
            Monomial operator %(const Monomial& ogn) const noexcept; //Modulus operator
            /**
            * @brief Addition assigment operator overload
            * @param ogn The Monomial object to add.
            * @return (Monomial&) A reference to the lvalue of the operation.
            **/
            Monomial& operator +=(const Monomial& ogn) noexcept; //Addition assigment operator
            /**
            * @brief Substraction assigment operator overload
            * @param ogn The Monomial object to substract by.
            * @return (Monomial&) A reference to the lvalue of the operation.
            **/
            Monomial& operator -=(const Monomial& ogn) noexcept; //Substraction assigment operator
            /**
            * @brief Multiplication assigment operator overload
            * @param ogn The Monomial object to multiply by.
            * @return (Monomial&) A reference to the lvalue of the operation.
            **/
            Monomial& operator *=(const Monomial& ogn) noexcept; //Multiplication assigment operator
            /**
            * @brief Division assigment operator overload
            * @param ogn The Monomial object to divide by.
            * @return (Monomial&) A reference to the lvalue of the operation.
            **/
            Monomial& operator /=(const Monomial& ogn) noexcept; //Division assigment operator
            /**
            * @brief Modulus assigment operator overload
            * @param ogn The Monomial object to divide by.
            * @return (Monomial&) A reference to the lvalue of the operation.
            **/
            Monomial& operator %=(const Monomial& ogn) noexcept; //Modulus assigment operator
            /**
            * @brief A friend operator to insert the Monomial into a std::stringstream
            * @param ss The std::stringstream.
            * @param m The Monomial object to insert.
            * @return (std::stringstream&) A reference to the std::stringstream.
            **/
            friend std::stringstream& operator<<(std::stringstream& ss, const Monomial& m); //Stream operator
            /**
            * @brief A friend operator to insert the Monomial into a std::ostream
            * @param out The std::ostream.
            * @param m The Monomial object to insert.
            * @return (std::ostream&) A reference to the std::ostream.
            **/
            friend std::ostream& operator<<(std::ostream& out, const Monomial& m); //Stream operator
            /**
            * @brief Getter function for getting the coefficient of the Monomial
            * @return (double) The coefficient of the Monomial.
            **/
            double get_coeff() const noexcept; //Coefficient getter
            /**
            * @brief Getter function for getting the degree of the Monomial
            * @return (int) The degree of the Monomial.
            **/
            int get_degree() const noexcept; //Degree getter
            /**
            * @brief Setter function for setting the coefficient of the Monomial
            * @param cf The coefficient to set to.
            **/
            void set_coeff(double cf) noexcept; //Coefficient setter
            /**
            * @brief Setter function for setting the degree of the Monomial
            * @param dgr The degree to set to.
            **/
            void set_degree(int dgr) noexcept; //Degree setter
            /**
            * @brief Getter function for getting the expression of the Monomial
            * @return (std::string) The expression of the Monomial.
            **/
            std::string get_expression() const noexcept; //String expression getter
            /**
            * @brief Calculus function for getting the value of the Monomial at a point
            * @param x The point to evaluate.
            * @return (double) The result of the evaluation of the Monomial.
            **/
            double get_value(const double& x) const noexcept; //Value for x getter
            /**
            * @brief The class destructor
            **/
            ~Monomial(); //Destructor
        private:
            /**
            * @brief The coefficient of the Monomial
            **/
            double coeff;
            /**
            * @brief The degree of the Monomial
            **/
            int degree;
            /**
            * @brief The swap function for the copy-and-swap idiom implemented by the assigment operators
            * @param ogn The other Monomial to swap the data with.
            **/
            void swap(Monomial& ogn) noexcept; //Swap function
    };
    /**
     * @class Polynomial
     * @brief Class for representing and operating polynomials
     * @details The class consists of the constructors, the operators, the getters, the properties and some private functions.
    */
    class Polynomial {
        public:
            /**
            * @brief Default constructor for when initialized with no arguments
            **/
            Polynomial() noexcept; //Default constructor
            /**
            * @brief Normal constructor for initialization with a std::map<int, Monomial>
            * @param mns The std::map<int, Monomial>.
            **/
            Polynomial(const std::map<int, Monomial> mns) noexcept; //Constructor
            /**
            * @brief List constructor for initialization with a std::initializer_list<Monomial>
            * @param mns The std::initializer_list<Monomial>.
            **/
            Polynomial(const std::initializer_list<Monomial> mns) noexcept; //List Constructor
            /**
            * @brief Vector constructor for initialization with a std::vector<Monomial>
            * @param mns The std::vector<Monomial>.
            **/
            Polynomial(const std::vector<Monomial> mns) noexcept; //Vector Constructor
            /**
            * @brief Copy constructor for when initialized with an lvalue Polynomial object
            * @param ogn The lvalue Polynomial object.
            **/
            Polynomial(const Polynomial& ogn) noexcept; //Copy constructor
            /**
            * @brief Move constructor for when initialized with an rvalue Polynomial object
            * @param ogn The rvalue Polynomial object.
            **/
            Polynomial(Polynomial&& ogn) noexcept; //Move constructor
            /**
            * @brief Assigment operator overload for when called with an lvalue
            * @param ogn The lvalue Polynomial object.
            * @return (Polynomial&) A reference to the lvalue of the operation
            **/
            Polynomial& operator =(const Polynomial& ogn) noexcept; //Assigment operator
            /**
            * @brief Move assigment operator overload for when called with an rvalue
            * @param ogn The rvalue Polynomial object.
            * @return (Polynomial&) A reference to the lvalue of the operation
            **/
            Polynomial& operator =(Polynomial&& ogn) noexcept; //Move assigment operator
            /**
            * @brief Equal logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If Polynomial objects degrees and monomials match.
            * @return (false) If Polynomial objects degrees and monomials dont match. 
            **/
            bool operator ==(const Polynomial& ogn) const noexcept; //Equal logic operator
            /**
            * @brief Not equal logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If Polynomial objects degrees and monomials dont match.
            * @return (false) If Polynomial objects degrees and monomials match. 
            **/
            bool operator !=(const Polynomial& ogn) const noexcept; //Not equal logic operator
            /**
            * @brief Greater than logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If the Polynomial object degree is greater than the degree of the passed Polynomial.
            * @return (false) If the Polynomial object degree is equal or less than the degree of the passed Polynomial.
            **/
            bool operator >(const Polynomial& ogn) const noexcept; //Greater than logic operator
            /**
            * @brief Less than logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If the Polynomial object degree is less than the degree of the passed Polynomial.
            * @return (false) If the Polynomial object degree is equal or greater than the degree of the passed Polynomial.
            **/
            bool operator <(const Polynomial& ogn) const noexcept; //Lesser than logic operator
            /**
            * @brief Greater or equal than logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If the Polynomial object degree is greater or equal than the degree of the passed Polynomial.
            * @return (false) If the Polynomial object degree is less than the degree of the passed Polynomial.
            **/
            bool operator >=(const Polynomial& ogn) const noexcept; //Greater or Equal than logic operator
            /**
            * @brief Less or equal than logic operator overload
            * @param ogn The Polynomial object to compare to.
            * @return (true) If the Polynomial object degree is less or equal than the degree of the passed Polynomial.
            * @return (false) If the Polynomial object degree is greater than the degree of the passed Polynomial.
            **/
            bool operator <=(const Polynomial& ogn) const noexcept; //Lesser or Equal than logic operator
            /**
            * @brief Addition operator overload
            * @param ogn The Polynomial object to add.
            * @return (Polynomial) A brand new Polynomial that represents the result.
            **/
            Polynomial operator +(const Polynomial& ogn) const noexcept; //Addition operator
            /**
            * @brief Substraction operator overload
            * @param ogn The Polynomial object to substract by.
            * @return (Polynomial) A brand new Polynomial that represents the result.
            **/
            Polynomial operator -(const Polynomial& ogn) const noexcept; //Substraction operator
            /**
            * @brief Multiplication operator overload
            * @param ogn The Polynomial object to multiply by.
            * @return (Polynomial) A brand new Polynomial that represents the result.
            **/
            Polynomial operator *(const Polynomial& ogn) const noexcept; //Multiplication operator
            /**
            * @brief Division operator overload
            * @param ogn The Polynomial object to divide by.
            * @return (Polynomial) A brand new Polynomial that represents the result.
            **/
            Polynomial operator /(const Polynomial& ogn) const noexcept; //Division operator
            /**
            * @brief Modulus operator overload
            * @param ogn The Polynomial object to divide by.
            * @return (Polynomial) A brand new Polynomial that represents the result.
            **/
            Polynomial operator %(const Polynomial& ogn) const noexcept; //Modulus operator
            /**
            * @brief Addition assigment operator overload
            * @param ogn The Polynomial object to add.
            * @return (Polynomial&) A reference to the lvalue of the operation.
            **/
            Polynomial& operator +=(const Polynomial& ogn) noexcept; //Addition assigment operator
            /**
            * @brief Substraction assigment operator overload
            * @param ogn The Polynomial object to substract by.
            * @return (Polynomial&) A reference to the lvalue of the operation.
            **/
            Polynomial& operator -=(const Polynomial& ogn) noexcept; //Substraction assigment operator
            /**
            * @brief Multiplication assigment operator overload
            * @param ogn The Polynomial object to multiply by.
            * @return (Polynomial&) A reference to the lvalue of the operation.
            **/
            Polynomial& operator *=(const Polynomial& ogn) noexcept; //Multiplication assigment operator
            /**
            * @brief Division assigment operator overload
            * @param ogn The Polynomial object to divide by.
            * @return (Polynomial&) A reference to the lvalue of the operation.
            **/
            Polynomial& operator /=(const Polynomial& ogn) noexcept; //Division assigment operator
            /**
            * @brief Modulus assigment operator overload
            * @param ogn The Polynomial object to divide by.
            * @return (Polynomial&) A reference to the lvalue of the operation.
            **/
            Polynomial& operator %=(const Polynomial& ogn) noexcept; //Modulus assigment operator
            /**
            * @brief A friend operator to insert the Polynomial into a std::stringstream
            * @param ss The std::stringstream.
            * @param m The Polynomial object to insert.
            * @return (std::stringstream&) A reference to the std::stringstream.
            **/
            friend std::stringstream& operator<<(std::stringstream& ss, const Polynomial& p) noexcept; //Stream operator
            /**
            * @brief A friend operator to insert the Polynomial into a std::ostream
            * @param out The std::ostream.
            * @param m The Polynomial object to insert.
            * @return (std::ostream&) A reference to the std::ostream.
            **/
            friend std::ostream& operator<<(std::ostream& out, const Polynomial& p) noexcept; //Stream operator
            /**
            * @brief Getter function for getting the degree of the Polynomial
            * @return (int) The degree of the Polynomial.
            **/
            int get_degree() const noexcept; //Degree getter
            /**
            * @brief Getter function for getting the monomials of the Polynomial
            * @return (std::map<int, Monomial>) The monomials of the Polynomial.
            **/
            std::map<int, Monomial> get_monomials() const noexcept; //Monomials getter
            /**
            * @brief Function for knowing if the polynomial has or not any monomials
            * @return (bool) If the polynomial is empty.
            **/
            bool is_empty() const noexcept;
            /**
            * @brief Function for appending a lvalue monomial to the Polynomial
            * @param m The Monomial object to append.
            * @return (bool) If the operation was successful.
            **/
            bool push_monomial(const Monomial& m) noexcept; //Monomials appender
            /**
            * @brief Function for appending a rvalue monomial to the Polynomial
            * @param m The Monomial object to append.
            * @return (bool) If the operation was successful.
            **/
            bool push_monomial(Monomial&& m) noexcept; //Monomials appender
            /**
            * @brief Getter function for getting the expression of the Polynomial
            * @return (std::string) The expression of the Polynomial.
            **/
            std::string get_expression() const noexcept; //String expression getter
            /**
            * @brief Calculus function for getting the value of the Polynomial at a point
            * @param x The point to evaluate.
            * @return (double) The result of the evaluation of the Polynomial.
            **/
            double get_value(const double& x) const noexcept; //Value for x getter
            /**
            * @brief Calculus function for getting the derivative of the Polynomial
            * @return (Polynomial) The result of the derivative of the Polynomial.
            **/
            Polynomial get_derivative() const noexcept; //Gets the derivative
            /**
            * @brief Calculus function for getting the integral of the Polynomial
            * @return (Polynomial) The result of the integral of the Polynomial.
            **/
            Polynomial get_integral() const noexcept; //Gets the integral
            /**
            * @brief Calculus function for getting all the real and complex roots of the Polynomial using the Eigen library
            * @return (std::vector<double>) All the roots as doubles in a std::vector
            **/
            std::vector<std::complex<double>> get_roots() const noexcept;
            /**
            * @brief The class destructor
            **/
            ~Polynomial(); //Destructor
        private:
            /**
            * @brief The monomials of the Polynomial as a std::map<int, Monomial> where the key is the degree of the Monomial
            **/
            std::map<int, Monomial> monomials;
            /**
            * @brief The swap function for the copy-and-swap idiom implemented by the assigment operators
            * @param ogn The other Polynomial to swap the data with.
            **/
            void swap(Polynomial& ogn) noexcept; //Swap function
            /**
            * @brief The redux function for removing the Monomials of zero coefficient
            **/
            Polynomial& redux() noexcept; //Reduces the polynomial
    };
};
#endif