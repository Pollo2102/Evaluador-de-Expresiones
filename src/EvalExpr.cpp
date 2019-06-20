#include <iostream>
#include "Functions.h"
#include "CustomRegex.h"

using namespace std;

int main(void)
{
    auto lambda = [](auto x, auto y) { return x + y; };

    Functions F;

    std::string str1 = "10+5-5*9/3";

    F.toPostFix(str1);
    // stof to convert to float

    /* if (CS.checkExpression("(3-4)+5+7*8"))
        cout << "Expresion correcta.";
    else
        cout << "Expresion incorrecta."; */

    return 0;
}