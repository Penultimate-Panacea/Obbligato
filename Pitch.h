//
// Created by username on 8/8/2018.
/*/

#ifndef OBBLIGATO_TONE_H
#define OBBLIGATO_TONE_H


class Pitch {
private:
    unsigned double frequency; //The Frequency Aprroximated in HZ
public:
    Pitch(double frequency);

    double getFrequency() const;

    void setFrequency(double frequency);

    virtual ~Pitch();

    bool operator<(const Pitch &rhs) const;

    bool operator>(const Pitch &rhs) const;

    bool operator<=(const Pitch &rhs) const;

    bool operator>=(const Pitch &rhs) const;
};


#endif //OBBLIGATO_TONE_H
*/