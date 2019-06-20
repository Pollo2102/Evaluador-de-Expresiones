#include "CustomRegex.h"

#define ARITHM "\\A(?=.*(\\)|\\d)\\z)[\\(|\\[]?([[:digit:]]+\\)?[\\+|\\-|\\*|\\/]?)+[\\)|\\]]?"

#define ARITHMETIC_EXPRESSION "(\\(|\\[)?([[:digit:]]+(\\.\\d+)?\\)?[\\+|\\-|\\*|\\/]?)+[\\)|\\]]?"

#define ARITHMETIC_EXPRE "(\\(|\\[)?([[:digit:]]+\\)?[\\+|\\-|\\*|\\/]?)+[\\)|\\]]?"

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