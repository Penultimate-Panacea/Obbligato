//
// Created by Penultimate-Panacea on 8/8/2018.
//

#include "BaseEightyNine.h"
#include <cmath>
#include <iostream>

using namespace std;


BaseEightyNine::BaseEightyNine(unsigned int base10input) : base10input(base10input) {
    setBase10input(base10input);
    setB89();
}

BaseEightyNine::~BaseEightyNine() = default;

void BaseEightyNine::setBase10input(unsigned int base10input) {
    BaseEightyNine::base10input = base10input;
}


bool BaseEightyNine::operator==(const BaseEightyNine &rhs) const {
    return b89 == rhs.b89;
}

bool BaseEightyNine::operator!=(const BaseEightyNine &rhs) const {
    return !(rhs == *this);
}

BaseEightyNine BaseEightyNine::operator+(const BaseEightyNine &rhs) const{
    return BaseEightyNine(base10input + rhs.base10input);
}

BaseEightyNine BaseEightyNine::operator-(const BaseEightyNine &rhs) const{
    return BaseEightyNine(base10input - rhs.base10input);
}

BaseEightyNine BaseEightyNine::operator*(const BaseEightyNine &rhs) const{
    return BaseEightyNine(base10input * rhs.base10input);
}

BaseEightyNine BaseEightyNine::operator/(const BaseEightyNine &rhs) const{
    return BaseEightyNine(base10input / rhs.base10input);
}

void BaseEightyNine::setB89(){
    unsigned int reduction = this->base10input;
    do{
    reduction = reduce(reduction);
    } while (reduction != 0);
}

unsigned int BaseEightyNine::reduce(unsigned int inputInt){
    cerr << "Reduce called with " << inputInt << " as argument." << endl;
    char digits = (inputInt % 89);
    cerr << "Modulo of argument is " << digits << endl;
    //char equivalent;
    char equivalent = BaseEightyNine::equivalenceTable[digits]; //identifies the appropriate digit from the const array
    cerr << "The Equivalent base89 digit is" << equivalent << " " << endl;
    this->b89.insert(this->b89.begin(),equivalent); //adds the digit to the front of the b89 vector
    return (unsigned int)floor(inputInt/89);
}

void BaseEightyNine::printEightyEight(){
    char out[]={' '};
    for(int i=0; i<this->b89.size();i++ ){
        out[i] = this->b89.at(static_cast<unsigned long>(i));
    }
    cout << out;
}

const deque<char> &BaseEightyNine::getB89() const {
    return b89;
}

ostream &operator<<(ostream &os, const BaseEightyNine &eight) {

}

bool BaseEightyNine::operator<(const BaseEightyNine &rhs) const {
    return base10input < rhs.base10input;
}

bool BaseEightyNine::operator>(const BaseEightyNine &rhs) const {
    return rhs < *this;
}

bool BaseEightyNine::operator<=(const BaseEightyNine &rhs) const {
    return !(rhs < *this);
}

bool BaseEightyNine::operator>=(const BaseEightyNine &rhs) const {
    return !(*this < rhs);
}
