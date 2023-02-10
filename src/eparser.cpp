/**
* @file eparser.cpp
* @brief This is the main implementation file for the equation parser.
* @details This file contains the implementation of the classes and functions for parsing polynomials and monomials.\n
* It consists of two classes, the Parser class and the Lexer class.\n
* The Parser class consists of two functions, one for parsing the entire input as a Polynomial and another for parsing a Monomial at a time.\n
* The Lexer class just provides a token supplier for the Parser class.\n
**/
#include "eparser.h"
/**
* @brief Standalone constructor for the Lexer class
* @param input A const reference to the std::string to tokenize.
**/
emthp::Lexer::Lexer(const std::string& input) noexcept : _input(this->clean(input)), _pos(0) {}
/**
* @brief Assigment operator for when called with an lvalue
* @param ogn The lvalue Lexer object.
* @return (Lexer&) A reference to the lvalue of the operation
**/
emthp::Lexer& emthp::Lexer::operator =(const emthp::Lexer& ogn) noexcept {
    this->_input = ogn._input;
    this->_pos = ogn._pos;
    return *this;
};
/**
* @brief Function that returns the next Token in the input provided in the constructor
* @return (Token) The next Token in the input
**/
emthp::Token emthp::Lexer::next() noexcept {
    if (this->_pos >= this->_input.size()) {return {emthp::TokenType::T_EOF, {0}};} //Returs EOL on end of _input
    switch (this->_input[this->_pos]) {
        case '+': this->_pos++; return {emthp::TokenType::T_PLUS, {0}};
        case '-': this->_pos++; return {emthp::TokenType::T_MINUS, {0}};
        case '^': this->_pos++; return {emthp::TokenType::T_EXPONENT, {0}};
        case 'x': this->_pos++; return {emthp::TokenType::T_VARIABLE, {0}};
        case '*': case '/': this->_pos++; return next();
        default:
            double number = this->read_number();
            while(true) {
                switch (this->_input[this->_pos]) {
                    case '*': this->_pos++; number *= this->read_number(); break;
                    case '/': this->_pos++; number /= this->read_number(); break;
                    case '^': this->_pos++; number = std::pow(number, this->read_number()); break;
                    default: return {emthp::TokenType::T_NUMBER, {number}};
                }
            }
    }
}
/**
* @brief Backtrack function that moves the cursor's position one position backwards
**/
void emthp::Lexer::back() noexcept {
    if (this->_pos <= 0) {return;} 
    if (emthp::Lexer::is_digit(this->_input[this->_pos-1])) {while (emthp::Lexer::is_digit(this->_input[this->_pos-1])) {this->_pos--;} return;}
    this->_pos--;return;
}
/**
* @brief Private static function that cleans the input string of the unexpected characters
* @param input The string to clean.
* @return (std::string) The clean output
**/
std::string emthp::Lexer::clean(const std::string& input) noexcept {
    long unsigned int pos = 0; std::string string;
    while (pos < input.size()) {
        switch (input[pos]) {
            case '+': string += '+'; break;
            case '-': string += '-'; break;
            case '*': string += '*'; break;
            case '/': string += '/'; break;
            case '^': string += '^'; break;
            case 'x': string += 'x'; break;
            default: if (emthp::Lexer::is_digit(input[pos])) {string += input[pos];} break;
        }
        pos++;
    }
    return string;
}
/**
* @brief Private function that reads the next Token as a number consisting of various characters
* @return (double) The number that was read
**/
double emthp::Lexer::read_number() noexcept {
    std::string snum;
    while (this->_pos < this->_input.size() && emthp::Lexer::is_digit(this->_input[this->_pos])) {
        snum += this->_input[this->_pos];
        this->_pos++;
    }
    if (snum.empty()) {return 1;}
    return std::stod(snum); // CHECK : 2x^2 -- 8x^3/3 ;;;.......................4x^1 + 2x⁶
}
/**
* @brief Standalone constructor for the Parser class
* @param input A const reference to the std::string to parse when needed.
**/
emthp::Parser::Parser(const std::string& input) noexcept : _lexer(input) {};
/**
* @brief Assigment operator for when called with an lvalue
* @param ogn The lvalue Parser object.
* @return (Parser&) A reference to the lvalue of the operation
**/
emthp::Parser& emthp::Parser::operator =(const emthp::Parser& ogn) noexcept {this->_lexer = ogn._lexer; return *this;};
/**
* @brief Function that parses the input as a Polynomial
* @return (emth::Polynomial) The input as a Polynomial
**/
emth::Polynomial emthp::Parser::parse_polynomial() noexcept {
    emth::Polynomial polynomial;
    while (true) {if(!polynomial.push_monomial(std::move(this->parse_monomial()))) {return polynomial;}}
}
/**
* @brief Function that parses the next Monomial in the input
* @return (emth::Monomial) The next Monomial in the input
**/
emth::Monomial emthp::Parser::parse_monomial() noexcept {
    emth::Monomial monomial(0, 0);
    monomial.set_coeff(this->parse_number());
    bool v = false; bool e = false;
    while (!v || !e) {
        emthp::Token token = this->_lexer.next();
        switch (token.type) {
            case emthp::TokenType::T_VARIABLE: v = true; break;
            case emthp::TokenType::T_EXPONENT: if (v) {e = true;} break;
            case emthp::TokenType::T_PLUS: case emthp::TokenType::T_MINUS: case emthp::TokenType::T_NUMBER: if (v) {monomial.set_degree(1); this->_lexer.back();} return monomial;
            case emthp::TokenType::T_EOF: if (v) {monomial.set_degree(1);} return monomial;
        }
    }
    monomial.set_degree((int) this->parse_number());
    return monomial;
}
/**
* @brief Private function for parsing a plus, minus and number Tokens as a positive or negative double
* @return (double) The parsed number
**/
double emthp::Parser::parse_number() noexcept {
    bool positive = true;
    while(true) {
        emthp::Token token = this->_lexer.next();
        switch(token.type) {
            case emthp::TokenType::T_MINUS: positive = !positive; break;
            case emthp::TokenType::T_NUMBER: return positive ? token.value : -token.value;
            case emthp::TokenType::T_VARIABLE: this->_lexer.back(); return positive ? 1 : -1;
            case emthp::TokenType::T_EOF: return 0;
        }
    }
}