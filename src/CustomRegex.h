#ifndef CUSTOMREGEX_H
#define CUSTOMREGEX_H

#include <string>
#include <regex>

class CustomRegex {
public:
    CustomRegex();
    ~CustomRegex();

    bool checkExpression(std::string input); // regex_match
    std::string getPostFixExpression(std::string input); // regex_search
};

#endif // !CUSTOMREGEX_H