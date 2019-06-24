#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CustomRegex.h"
#include "Functions.h"
#include <string>
#include <vector>
#include <cmath>


const std::string EXAMPLE_EXPRESSION_1 = "(3-4)+5+7*8";
const std::string EXAMPLE_EXPRESSION_2 = "(3-4)+[5+7]]*8j";//Prueba
const std::string EXAMPLE_EXPRESSION_3 = "(3-4)+[5+7]]*8+"; //Prueba
const std::string EXAMPLE_EXPRESSION_4 = "(3.4-4)+[5.5+7]]*8+";//Prueba
const std::string EXAMPLE_EXPRESSION_5 = "(3.4-4)+[5.5+7]*8";
const std::string EXAMPLE_EXPRESSION_6 = "(3.5-4))+5.4+7*8"; //Prueba
const std::string EXAMPLE_EXPRESSION_7 = "(2-1)*(3^5)+(4%2)";

TEST_CASE("Regular Expression Test Case") 
{
    CustomRegex CS;

    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_1) == true); //Numeros enteros
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_2) == false); // Paréntesis incompletos
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_3) == false); // Expresión inválida
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_4) == false); // Paréntesis y Expresión Inválida
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_5) == true); // Flotantes. Paréntesis Correctos.
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_6) == false); // Expresión correcta
    CHECK(CS.checkExpression(EXAMPLE_EXPRESSION_7) == true); // Expresión correcta
}

TEST_CASE("Expression Evaluation Test Case") //Only arithmetic operators
{
    Functions F;

    std::vector<std::string> stack;
    stack.push_back("10");
    stack.push_back("8");
    stack.push_back("-");
    stack.push_back("125");
    stack.push_back("987");
    stack.push_back("*");
    stack.push_back("563");
    stack.push_back("/");
    stack.push_back("+");

    F.evaluateExpression(stack);
}

TEST_CASE("Infix to Postfix Test Case") 
{
    Functions F;

    std::string str1 = "10+5-5*9/3";
    std::string str2 = "10+10-5*9/3";
    std::string str3 = "10.5+10-5*9/3";
    std::string str4 = "100+5";
    std::string str5 = "10/8*9-8+4";
    std::string str6 = "10+10-5/5*3";
    std::string str7 = "(2-1)*(3^5)+(4%2)";
    auto number = [](){return (2-1)*(pow(3, 5))+4%2;}; //C++11

    CHECK(F.toPostFix(str1) == 0.0f);
    CHECK(F.toPostFix(str2) == 5.0f);
    CHECK(F.toPostFix(str3) == 5.5f);
    CHECK(F.toPostFix(str4) == 105.0f);
    CHECK(F.toPostFix(str5) == 7.25f);
    CHECK(F.toPostFix(str6) == 17.0f);
    CHECK(F.toPostFix(str7) == 243.0f);
    CHECK(F.toPostFix(str7) == number());

}

TEST_CASE("Floating Point Evaluation Test Case") //Only arithmetic operators
{
    using namespace std::string_literals;
    Functions F;
    std::string num = std::to_string(1'987); //C++14
    std::string num2 = "10"s; //C++14

    std::vector<std::string> stack;
    stack.push_back("10");
    stack.push_back("8.8");
    stack.push_back("-");
    stack.push_back("125.5");
    stack.push_back(num);
    stack.push_back("*");
    stack.push_back("563");
    stack.push_back("/");
    stack.push_back("+");

    F.evaluateExpression(stack);
}

TEST_CASE("isDigit Test Case")
{
    Functions Func;

    int number1 = 0b110101; //C++14
    char n1 = static_cast<char>(number1); //C++14

    CHECK(Func.isDigit(n1) == true);
    CHECK(Func.isDigit('5') == true);
    CHECK(Func.isDigit('.') == true);
    CHECK(Func.isDigit('0') == true);
    CHECK(Func.isDigit('+') == false);
    CHECK(Func.isDigit('*') == false);
}

TEST_CASE("isOperator Test Case")
{
    Functions Func;

    CHECK(Func.isOperator('+') == true);
    CHECK(Func.isOperator('-') == true);
    CHECK(Func.isOperator('*') == true);
    CHECK(Func.isOperator('/') == true);
    CHECK(Func.isOperator('%') == true);
    CHECK(Func.isOperator('^') == true);
    CHECK(Func.isOperator('(') == false);
    CHECK(Func.isOperator('#') == false);
}