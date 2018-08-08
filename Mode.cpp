//
// Created by username on 8/8/2018.
//

#include <tgmath.h>
#include <iostream>
#include "Mode.h"
#include "ObbligatoExeceptions.h"

Mode::Mode(unsigned char mode_id) : mode_id(mode_id) {}

Mode::~Mode() {}

unsigned char Mode::getMode_id() const {
    return mode_id;
}

void Mode::setMode_id(unsigned char mode_id) {
    if (mode_id > 168) {throw InvalidModeError();};
    Mode::mode_id = mode_id;
}

bool Mode::operator==(const Mode &rhs) const {
    return mode_id == rhs.mode_id;
}

bool Mode::operator!=(const Mode &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Mode &mode) {
    os << "mode_id: " << mode.mode_id;
    return os;
}
