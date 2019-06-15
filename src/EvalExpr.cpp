#include <iostream>
#include "functions.h"
#include "CustomRegex.h"

using namespace std;

int main(void)
{
    CustomRegex CS;

    if (CS.checkExpression("(3-4)+5+7*8"))
        cout << "Expresion correcta.";
    else
        cout << "Expresion incorrecta.";

    return 0;
}