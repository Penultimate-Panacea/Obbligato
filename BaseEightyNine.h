//
// Created by Penultimate-Panacea on 8/8/2018.
//
#include <string>
#include <deque>
#include <ostream>

#ifndef OBBLIGATO_BASEEIGHTYNINE_H
#define OBBLIGATO_BASEEIGHTYNINE_H


class BaseEightyNine {
public:
//private:
    unsigned int base10input; //
    std::deque<char> b89; //Raw form of the b89
    // Removing static constexpr  from declaration fixed bug
    char equivalenceTable[89] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
                                                  'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                                                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                                  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                                  'u', 'v', 'w', 'x', 'y', 'z', '!', '<', '#', '$', '%', '&', '>', '(',
                                                  ')', '*', '+', ',', '-', '.', '/', '[', '?', ']', '^', '_', '`', '{',
                                                  '|', '}', '~', '@', '\\'};
    // Provides the symbol set for the numbers in base 89
//public:
    explicit BaseEightyNine(unsigned int base10input = 0);

    virtual ~BaseEightyNine();

    void setBase10input(unsigned int base10input);

    void setB89();

    void printEightyEight();

    const std::deque<char> &getB89() const;

    bool operator==(const BaseEightyNine &rhs) const;

    bool operator!=(const BaseEightyNine &rhs) const;

    BaseEightyNine operator+(const BaseEightyNine &rhs) const ;

    bool operator<(const BaseEightyNine &rhs) const;

    bool operator>(const BaseEightyNine &rhs) const;

    bool operator<=(const BaseEightyNine &rhs) const;

    bool operator>=(const BaseEightyNine &rhs) const;

    BaseEightyNine operator-(const BaseEightyNine &rhs) const ;

    BaseEightyNine operator*(const BaseEightyNine &rhs) const ;

    BaseEightyNine operator/(const BaseEightyNine &rhs) const ;

    unsigned int reduce(unsigned int inputInt);

};

#endif //OBBLIGATO_BASEEIGHTYNINE_H
