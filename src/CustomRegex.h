#ifndef CUSTOMREGEX_H
#define CUSTOMREGEX_H

#include <string>
#include <regex>

class CustomRegex {
public:
    CustomRegex();
    ~CustomRegex();

    bool checkExpression(std::string input); // regex_match
};

#endif // !CUSTOMREGEX_H