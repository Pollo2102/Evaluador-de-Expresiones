#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>
#include <string>
#include <vector>

class Functions
{
public:
    Functions();
    ~Functions();

    float evaluateExpression(std::vector<std::string> resultStack);
    float toPostFix(std::string expression);
    bool isOperator(char a);
    bool isDigit(char a);
};

#endif // !FUNCTIONS_H