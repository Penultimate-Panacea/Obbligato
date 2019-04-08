//
// Created by Penultimate-Panacea on 8/8/2018.
//

#include "BaseEightyNine.h"
#include "ETable.hpp"
#include <cmath>
#include <iostream>
#include <deque>


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
	const char b89CharSet[89] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
						   'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
						   'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
						   'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '<',
						   '#', '$', '%', '&', '>', '(', ')', '*', '+', ',', '-', '.', '/', '[', '?', ']',
						   '^', '_', '`', '{', '|', '}', '~', '@', '\\'};
	std::cerr << "Reduce called with " << inputInt << " as argument." << std::endl;
	auto digits = static_cast<char>(inputInt % 89);
	std::cerr << "Modulo of argument is: " << static_cast<int>(digits) << std::endl;
	char equivalent = b89CharSet[digits]; //identifies the appropriate digit from the const array
	std::cerr << "The Equivalent base89 digit is: " << equivalent << " " << std::endl;
	this->b89.insert(this->b89.begin(),equivalent); //adds the digit to the front of the b89 vector
	return (unsigned int)floor(inputInt/89);
}
/*
void BaseEightyNine::printEightyEight(){
	char out[]={' '};
	for(int i=0; i<this->b89.size();i++ ){
		out[i] = this->b89.at(static_cast<unsigned long>(i));
	}
	cout << out;
}
*/
const std::deque<char> &BaseEightyNine::getB89() const {
	return b89;
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

char BaseEightyNine::firstChar() {
	return b89[0];
}