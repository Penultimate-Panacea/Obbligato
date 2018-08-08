//
// Created by username on 8/8/2018.
//

#include "BaseEightyEight.h"
#include <cmath>
#include <iostream>

using namespace std;


BaseEightyEight::BaseEightyEight(unsigned int base10input) : base10input(base10input) {
    setBase10input(base10input);
    setOutput();
}

BaseEightyEight::~BaseEightyEight() = default;

unsigned int BaseEightyEight::getBase10input() const {
    return base10input;
}

void BaseEightyEight::setBase10input(unsigned int base10input) {
    BaseEightyEight::base10input = base10input;
}


bool BaseEightyEight::operator==(const BaseEightyEight &rhs) const {
    return output == rhs.output;
}

bool BaseEightyEight::operator!=(const BaseEightyEight &rhs) const {
    return !(rhs == *this);
}

void BaseEightyEight::setOutput(){
    unsigned int reduction = this->base10input;
    do{
    reduction = reduce(reduction);
    } while (reduction !=0);
}

unsigned int BaseEightyEight::reduce(unsigned int inputInt){
    cerr << "Reduce called with " << inputInt << " as argument." << endl;
    auto digits = static_cast<char>(inputInt % 88);
    cerr << "Modulo of argument is " << digits << endl;
    char equivalent = this->equivalence[digits]; //identifies the appropriate digit from the const array
    std::cerr << "The Equivalent base88 digit is" << equivalent << " " << std::endl;
    this->output.insert(this->output.begin(),equivalent); //adds the digit to the front of the output vector
    return (unsigned int)floor(inputInt/88);

}

void BaseEightyEight::printEightyEight(){
    char out[]={' '};
    for(int i=0; i<this->output.size();i++ ){
        out[i] = this->output.at(static_cast<unsigned long>(i));
    }
    cout << out;
}

const deque<char> &BaseEightyEight::getOutput() const {
    return output;
}

ostream &operator<<(ostream &os, const BaseEightyEight &eight) {

}
