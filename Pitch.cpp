//
// Created by username on 8/8/2018.
/*/

#include "Pitch.h"

double Pitch::getFrequency() const {
    return frequency;
}

Pitch::Pitch(double frequency) : frequency(frequency) {}

Pitch::~Pitch() {

}

bool Pitch::operator<(const Pitch &rhs) const {
    return frequency < rhs.frequency;
}

bool Pitch::operator>(const Pitch &rhs) const {
    return rhs < *this;
}

bool Pitch::operator<=(const Pitch &rhs) const {
    return !(rhs < *this);
}

bool Pitch::operator>=(const Pitch &rhs) const {
    return !(*this < rhs);
}

void Pitch::setFrequency(double frequency) {
    Pitch::frequency = frequency;
}
*/
