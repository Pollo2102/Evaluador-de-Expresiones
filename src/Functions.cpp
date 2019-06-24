#include "Functions.h"
#include "CustomRegex.h"
#include <iostream>
#include <cmath>

using namespace std;

Functions::Functions() {}
Functions::~Functions() {}

void Functions::mainMenu()
{
    string expression;
    uint16_t opcion = 0;
    while (opcion != 2)
    {
    cout << "Evaluador de Expresiones\n";
    cout << "1. Evaluar Expresión.\n";
    cout << "2. Salir.\n";
    cin >> opcion;
    cout << opcion;

    if (int result; /* c++17 */ opcion == 1)
    {
        cout << "Type the expression: " << endl;
        cin >> expression;
        result = toPostFix(expression);
        cout << endl << "Result: " << result << endl;
    }
    else
    {
        opcion = 2;
    }

    }
}

float Functions::toPostFix(string expression)
{
    cout << "EXPRESSION: " << expression << endl;

    expression.push_back(')');

    float result;
    CustomRegex RX;

    if (!RX.checkExpression(expression))
    {
        cout << "Invalid expression. \n";
        return 0;
    }

    vector<char> operatorStack;
    vector<string> resultS;

    operatorStack.push_back('(');

    string number;
    string operators;

    for (size_t i = 0; i < expression.length(); i++)
    {
        if (isDigit(expression.at(i))) // If operand, add to RESULT**
        {
            number += expression.at(i);
            if ((i < expression.length()-1) && (!isDigit(expression.at(i + 1))))
            {
                resultS.push_back(number);
                number.clear();
            }
        }
        else if (expression.at(i) == '(') // If '(', add to Stack**
        {
            operatorStack.push_back(expression.at(i));
        }
        else if (isOperator(expression.at(i)))
        {
            for (int j = operatorStack.size() - 1; j >= 0; j--)
            {
                if (expression.at(i) == '+' || expression.at(i) == '-')
                {
                    if (operatorStack.at(j) == '(')
                    {
                        break;
                    }
                    else
                    {
                        operators += operatorStack.at(j);
                        resultS.push_back(operators);
                        operators.clear();
                        operatorStack.pop_back();
                    }
                }
                else if (expression.at(i) == '*' || expression.at(i) == '/' || expression.at(i) == '%')
                {
                    if (operatorStack.at(j) == '-' || operatorStack.at(j) == '+' || operatorStack.at(j) == '(')
                    {
                        break;
                    }
                    else
                    {
                        operators += operatorStack.at(j);
                        resultS.push_back(operators);
                        operators.clear();
                        operatorStack.pop_back();
                    }
                }
                else 
                {
                    if (operatorStack.at(j) != '^' || operatorStack.at(j) == '(')
                    {
                        break;
                    }
                    else
                    {
                        operators += operatorStack.at(j);
                        resultS.push_back(operators);
                        operators.clear();
                        operatorStack.pop_back();
                    }
                }
            }
            operatorStack.push_back(expression.at(i));
            // Pop_back from stack and into RESULT operators with greater than or equal precedence. At the end, add operator to stack
        }
        else if (expression.at(i) == ')')
        {
            for (int j = operatorStack.size() - 1; j >= 0; j--)
            {
                if (operatorStack.at(j) == '(')
                {
                    break;
                }
                else
                {
                    operators.clear();
                    operators += operatorStack.at(j);
                    resultS.push_back(operators);
                    operators.clear();
                    operatorStack.pop_back();
                }
            }
            
            operatorStack.pop_back();
            // Pop from stack and into RESULT until '(' and remove '('
        }
        else
        {
            cout << "Invalid expression.\n";
            return 0;
        }
    }

    for (size_t i = 0; i < resultS.size(); i++)
    {
        if (resultS.at(i) == "(")
        {
            resultS.erase(resultS.begin() + i);
            i--;
        }
    }
    

    cout << endl <<"Postfix Expression:";
    for (size_t i = 0; i < resultS.size(); i++)
    {
        cout << resultS.at(i) << " ";
    }
    

    result = evaluateExpression(resultS);
    //Evaluar expresión

    return result;
}

float Functions::evaluateExpression(vector<string> resultStack)
{
    vector<string> stack;
    char operators;

    if (resultStack.empty())
    {
        cout << "Stack is empty.\n";
        return 0;
    }
    for (size_t i = 0; i < resultStack.size(); i++)
    {
        operators = resultStack.at(i).at(0);
        if (isOperator(operators))
        {
            if (operators == '+')
                stack.at(stack.size() - 2) = to_string(stof(stack.at(stack.size() - 2)) + stof(stack.at(stack.size() - 1)));
            else if (operators == '-')
                stack.at(stack.size() - 2) = to_string(stof(stack.at(stack.size() - 2)) - stof(stack.at(stack.size() - 1)));
            else if (operators == '*')
                stack.at(stack.size() - 2) = to_string(stof(stack.at(stack.size() - 2)) * stof(stack.at(stack.size() - 1)));
            else if (operators == '/')
                stack.at(stack.size() - 2) = to_string(stof(stack.at(stack.size() - 2)) / stof(stack.at(stack.size() - 1)));
            else if (operators == '%')
                stack.at(stack.size() - 2) = to_string(stoi(stack.at(stack.size() - 2)) % stoi(stack.at(stack.size() - 1)));
            else if (operators == '^')
                stack.at(stack.size() - 2) = to_string(pow(stof(stack.at(stack.size() - 2)), stof(stack.at(stack.size() - 1))));

            stack.pop_back();
        }
        else
            stack.push_back(resultStack.at(i));
    }
    return stof(stack.front());
}

bool Functions::isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^')
        return true;
    else
        return false;
}

bool Functions::isDigit(char a)
{
    return ((a > 47 && a < 58) || a == '.');
}