//
// Created by username on 8/8/2018.
//
#include <string>
#include <deque>
#include <ostream>

#ifndef OBBLIGATO_BASEEIGHTYEIGHT_H
#define OBBLIGATO_BASEEIGHTYEIGHT_H


class BaseEightyEight {
public:
    explicit BaseEightyEight(unsigned int base10input = 0);

    virtual ~BaseEightyEight();

    unsigned int getBase10input() const;

    void setBase10input(unsigned int base10input);

    void setOutput();

    void printEightyEight();

    const std::deque<char> &getOutput() const;

    bool operator==(const BaseEightyEight &rhs) const;

    bool operator!=(const BaseEightyEight &rhs) const;

    unsigned int reduce(unsigned int inputInt);

    friend std::ostream &operator<<(std::ostream &os, const BaseEightyEight &eight);

private:
    unsigned int base10input;
    std::deque<char> output;
    const char equivalence[88] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                  'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '\"', '#', '$', '%', '&',
                                  '\'', '(', ')', '*', '+', ',', '-', '.', '/', '[', '\\', ']', '^', '_', '`', '{',
                                  '|', '}', '~', '@'}; // Provides the symbol set for the numbers in base 88
};




#endif //OBBLIGATO_BASEEIGHTYEIGHT_H
