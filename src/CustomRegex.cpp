#include "CustomRegex.h"

#define ARITHMETIC_EXPRESSION "(\\(|\\[)?([[:digit:]]+(\\.\\d+)?(\\)|\\])?[\\+|\\-|\\*|\\/|\\%|\\^]?(\\(|\\[)?)+[\\)|\\]]?"

// (2-1)*(3^5)+(4%2)

#define ARITHMETIC_EXPRE "(\\(|\\[)?([[:digit:]]+\\)?[\\+|\\-|\\*|\\/]?)+[\\)|\\]]?"

using namespace std;

const regex R(ARITHMETIC_EXPRESSION);

CustomRegex::CustomRegex(){}
CustomRegex::~CustomRegex(){}



bool CustomRegex::checkExpression(string input)
{
    return regex_match(input, R);
}


// Verificar si (num() == (num))
// Verificar si hay un operador al final