//
// Created by username on 8/8/2018.
//

#ifndef OBBLIGATO_INVALIDMODE_H
#define OBBLIGATO_INVALIDMODE_H

#include <stdexcept>


class InvalidModeError : public std::runtime_error{
public:
    InvalidModeError() : std::runtime_error("Not a invalid Mode "){}
};

#endif //OBBLIGATO_INVALIDMODE_H
