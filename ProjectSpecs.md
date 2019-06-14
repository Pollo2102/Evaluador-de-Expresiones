*** C++ features to use in project ***

use templates and generic lambda functions
std::unique_ptr

*** C++11 ***
- New string literals
    u8"I'm a UTF-8 string."
    u"This is a UTF-16 string."
    U"This is a UTF-32 string."

    The type of the first string is the usual const char[]. The type of the second string is const char16_t[] (note lower case 'u' prefix). The type of the third string is const char32_t[] (upper case 'U' prefix).

    u8"This is a Unicode Character: \u2018."
    u"This is a bigger Unicode Character: \u2018."
    U"This is a Unicode Character: \U00002018."

- Static assertions

-Threading facilities

- lambda functions

*** C++14 ***
- Binary literals
    The syntax uses the prefixes 0b or 0B

- Digit separators -> auto integer_literal = 1'000'000;

- Generic lambdas
    auto lambda = [](auto x, auto y) {return x + y;};

-Standard user-defined literals
    C++11 defined the syntax for user-defined literal suffixes, but the standard library did not use any of them. C++14 adds the following standard literals:[16]

    "s", for creating the various std::basic_string types.
    "h", "min", "s", "ms", "us", "ns", for creating the corresponding std::chrono::duration time intervals.
    "if", "i", "il", for creating the corresponding std::complex<float>, std::complex<double> and std::complex<long double> imaginary numbers.
    auto str = "hello world"s; // auto deduces string
    auto dur = 60s;            // auto deduces chrono::seconds
    auto z   = 1i;             // auto deduces complex<double>
    The two "s" literals do not interact, as the string one only operates on string literals, and the one for seconds operates only on numbers.

*** C++17 ***
- keyword register
- std::byte