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
private:
    unsigned int base10input; //
    std::deque<char> b89; //Raw form of the b89
public:
    explicit BaseEightyNine(unsigned int base10input = 0);

    virtual ~BaseEightyNine();

    void setBase10input(unsigned int base10input);

    void setB89();

    char firstChar();

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
