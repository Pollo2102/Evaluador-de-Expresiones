#include "CustomRegex.h"

#define ARITHMETIC_EXPRESSION "[\\(|\\[]?([\\)[:digit:]]+[\\+|\\-|\\*|\\/]?)+[\\)|\\]]?"
#define ARITHMETIC_EX "([[:digit:]]+[\\+|\\-|\\*|\\/]?)+"

using namespace std;

const regex R(ARITHMETIC_EXPRESSION);

CustomRegex::CustomRegex(){}
CustomRegex::~CustomRegex(){}



bool CustomRegex::checkExpression(string input)
{
    return regex_match(input, R);
}

string CustomRegex::getPostFixExpression(string input) 
{
    
}

// Verificar si (num() == (num))
// Verificar si hay un operador al final