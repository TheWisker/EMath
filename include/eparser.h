/**
* @file eparser.h
* @brief This is the main header file for the equation parser.
* @details This file contains the classes and functions for parsing polynomials and monomials.\n
* It consists of two classes, the Parser class and the Lexer class.\n
* The Parser class consists of two functions, one for parsing the entire input as a Polynomial and another for parsing a Monomial at a time.\n
* The Lexer class just provides a token supplier for the Parser class.\n
**/
#ifndef EPARSER_H
#define EPARSER_H
#include <string>
#include "emath.h"
#pragma once
/**
 * @namespace emthp
 * @brief Englobes all the classes and functions of the parser
 * @details The emthp namespace contains two classes: Parser and Lexer. It also contains the TokenType enum and a Token struct.
**/
namespace emthp {
    /**
     * @enum TokenType
     * @brief Enum with all the possible Token types
    **/
    enum TokenType {
        /**
         * @brief Plus sign type
        **/
        T_PLUS,
        /**
         * @brief Minus sign type
        **/
        T_MINUS,
        /**
         * @brief Number type
        **/
        T_NUMBER,
        /**
         * @brief X type
        **/
        T_VARIABLE,
        /**
         * @brief Exponent sign type
        **/
        T_EXPONENT,
        /**
         * @brief EOF type
        **/
        T_EOF
    };
    /**
     * @struct Token
     * @brief Struct for representing a token as a type and a value
    **/
    struct Token {
        public:
            /**
             * @brief The token's type as a TokenType
            **/
            TokenType type;
            /**
             * @brief The token's numerical value as a double
            **/
            double value;
    };
    /**
     * @class Lexer
     * @brief Class that works as a token supplier for the Parser class
     * @details The class consists of two public functions, one for getting the next Token and the other for going back one position.
    **/ 
    class Lexer {
        public:
            /**
            * @brief Standalone constructor for the Lexer class
            * @param input A const reference to the std::string to tokenize.
            **/
            Lexer(const std::string& input) noexcept;
            /**
            * @brief Assigment operator for when called with an lvalue
            * @param ogn The lvalue Lexer object.
            * @return (Lexer&) A reference to the lvalue of the operation
            **/
            Lexer& operator =(const Lexer& ogn) noexcept;
            /**
            * @brief Function that returns the next Token in the input provided in the constructor
            * @return (Token) The next Token in the input
            **/
            Token next() noexcept;
            /**
            * @brief Backtrack function that moves the cursor's position one position backwards
            **/
            void back() noexcept;
        private:
            /**
            * @brief The provided input as a private std::string
            **/
            std::string _input;
            /**
            * @brief Private long unsigned int that represents the cursor's position
            **/
            long unsigned int _pos;
            /**
            * @brief Private function that reads the next Token as a number consisting of various characters
            * @return (double) The number that was read
            **/
            double read_number() noexcept;
            /**
            * @brief Private static function that cleans the input string of the unexpected characters
            * @param input The string to clean.
            * @return (std::string) The clean output
            **/
            static std::string clean(const std::string& input) noexcept;
            /**
            * @brief Miscellaneous private function that checks if a char is a digit
            * @param c The char to check if it is a digit.
            * @return (true) If the char is a digit
            * @return (false) If the char is not a digit
            **/
            static constexpr inline bool is_digit(const char& c) noexcept {return ((c >= '0' && c <= '9') || c == '.');}
    };
    /**
     * @class Parser
     * @brief Class that wraps a std::string and parses it as a Monomial or as a Polynomial
     * @details The class consists of two public functions, one for parsing the entire input as a Polynomial and the other for parsing only the next Monomial.
    **/
    class Parser {
        public:
            /**
            * @brief Standalone constructor for the Parser class
            * @param input A const reference to the std::string to parse when needed.
            **/
            Parser(const std::string& input) noexcept;
            /**
            * @brief Assigment operator for when called with an lvalue
            * @param ogn The lvalue Parser object.
            * @return (Parser&) A reference to the lvalue of the operation
            **/
            Parser& operator =(const Parser& ogn) noexcept;
            /**
            * @brief Function that parses the input as a Polynomial
            * @return (emth::Polynomial) The input as a Polynomial
            **/
            emth::Polynomial parse_polynomial() noexcept;
            /**
            * @brief Function that parses the next Monomial in the input
            * @return (emth::Monomial) The next Monomial in the input
            **/
            emth::Monomial parse_monomial() noexcept;
        private:
            /**
            * @brief Private Lexer instance for supplying tokens
            **/
            Lexer _lexer;
            /**
            * @brief Private function for parsing a plus, minus and number Tokens as a positive or negative double
            * @return (double) The parsed number
            **/
            double parse_number() noexcept;
    };
}
#endif