/**
* @file eparser.cpp
* @brief This is the main test file for the equation parser.
* @details This file contains a text fixture class and all the test cases.\n
* It consists of the EParserTest classe that provides the test fixture for all the tests.\n
* Then it contains all the test cases, for testing correct execution.
**/
#include <gtest/gtest.h>
#include "eparser.h"
/**
 * @class EParserTest
 * @brief Class that provides a test fixture for the test cases
**/
class EParserTest : public ::testing::Test {
    public:
        /**
        * @brief Standalone constructor for the EParserTest class
        * @details Initializes the lexer and parser object with empty inputs.
        **/
        EParserTest() : lexer(""), parser("") {};
        /**
        * @brief Function for setting the input to the lexer and parser objects
        * @param input The std::string to set as input
        **/
        void set_input(const std::string &input) {
            this->lexer = emthp::Lexer(input);
            this->parser = emthp::Parser(input);
        }
    protected:
        /**
        * @brief The lexer object on which to perform the tests on
        **/
        emthp::Lexer lexer;
        /**
        * @brief The parser object on which to perform the tests on
        **/
        emthp::Parser parser;
};
/**
* @test Test lexer functionality with simple expressions
**/
TEST_F(EParserTest, Lexer) {
    emthp::Token token;
    this->set_input("2x^2 - 8");

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 2.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_VARIABLE);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EXPONENT);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 2.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_MINUS);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 8.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EOF);
    ASSERT_EQ(token.value, 0.0);
}
/**
* @test Test lexer functionality with compund expressions
**/
TEST_F(EParserTest, CompoundLexer) {
    emthp::Token token;
    this->set_input("1.11x^2.22");
    
    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 1.11);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_VARIABLE);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EXPONENT);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 2.22);
    
    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EOF);
    ASSERT_EQ(token.value, 0.0);
}
/**
* @test Test lexer functionality with arithmetic expressions
**/
TEST_F(EParserTest, ArithmeticLexer) {
    emthp::Token token;
    this->set_input("2*8/4^3 x^ 2^2");
    
    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 64.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_VARIABLE);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EXPONENT);
    ASSERT_EQ(token.value, 0.0);

    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_NUMBER);
    ASSERT_EQ(token.value, 4.0);
    
    token = this->lexer.next();
    ASSERT_EQ(token.type, emthp::TokenType::T_EOF);
    ASSERT_EQ(token.value, 0.0);
}
/**
* @test Test parser functionality with monomial expressions
**/
TEST_F(EParserTest, Variables) {
    this->set_input("x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(1, 1));
    this->set_input("2x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(2, 1));
    this->set_input("x^2"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(1, 2));
    this->set_input("2x^2"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(2, 2));
}
/**
* @test Test parser functionality with polynomial expressions
**/
TEST_F(EParserTest, Compound) {this->set_input("2x^2 - 2x + 2"); ASSERT_EQ(this->parser.parse_polynomial(), emth::Polynomial({emth::Monomial(2, 2), emth::Monomial(-2, 1), emth::Monomial(2, 0)}));}
/**
* @test Test parser functionality with sign expressions
**/
TEST_F(EParserTest, Signs) {
    this->set_input("-x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(-1, 1));
    this->set_input("--x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(1, 1));
    this->set_input("---x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(-1, 1));
    this->set_input("-+x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(-1, 1));
    this->set_input("+-+x"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(-1, 1));
}
/**
* @test Test parser functionality with noise in the expressions
**/
TEST_F(EParserTest, Noise) {
    this->set_input("(1)<···(0)<···_x_···>^{2}"); ASSERT_EQ(this->parser.parse_monomial(), emth::Monomial(10, 2));
    this->set_input("(1)<···(0)<···_x_···>^{2} - (0)<···(5)<···_x_···>^{2}"); ASSERT_EQ(this->parser.parse_polynomial(), emth::Polynomial({emth::Monomial(5, 2)}));
}
/**
* @test Test parser edge cases
**/
TEST_F(EParserTest, Edge) {this->set_input(""); ASSERT_EQ(this->parser.parse_polynomial(), emth::Polynomial());}
/**
* @brief Function that runs all the declared tests
* @param argc The console arguments count
* @param argv The console arguments as a array of char arrays
* @return (0) If all tests passed
* @return (1) If one or more tests failed
**/
int main(int argc, char** argv) {testing::InitGoogleTest(&argc, argv); return RUN_ALL_TESTS();}