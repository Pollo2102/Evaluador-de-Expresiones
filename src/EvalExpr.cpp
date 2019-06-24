#include <iostream>
#include "Functions.h"
#include "CustomRegex.h"

using namespace std;

int main(void)
{
    auto lambda = [](auto x, auto y) { return x + y; };

    Functions F;
    
    F.mainMenu();

    return 0;
}