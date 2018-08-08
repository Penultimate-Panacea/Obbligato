//
// Created by username on 8/8/2018.
//

#ifndef OBBLIGATO_MODE_H
#define OBBLIGATO_MODE_H


#include <ostream>

class Mode {
private:

    unsigned char mode_id;
public:

    bool operator==(const Mode &rhs) const;

    bool operator!=(const Mode &rhs) const;

    unsigned char getMode_id() const;

    void setMode_id(unsigned char mode_id);

    Mode(unsigned char mode_id);

    virtual ~Mode();

    friend std::ostream &operator<<(std::ostream &os, const Mode &mode);

};


#endif //OBBLIGATO_MODE_H
