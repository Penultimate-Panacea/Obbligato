//
// Created by Penultimate-Panacea on 8/27/2018.
//

#ifndef OBBLIGATO_Seeder_H
#define OBBLIGATO_Seeder_H


#include <ostream>

class Seeder {
public:
    Seeder(unsigned short hall, unsigned short floor, unsigned short room, unsigned short wall, unsigned short shelf,
         unsigned short book);

    virtual ~Seeder();

    friend std::ostream &operator<<(std::ostream &os, const Seeder &Seeder);

    unsigned short getHall() const;

    void setHall(unsigned short hall);

    unsigned short getFloor() const;

    void setFloor(unsigned short floor);

    unsigned short getRoom() const;

    void setRoom(unsigned short room);

    unsigned short getWall() const;

    void setWall(unsigned short wall);

    unsigned short getShelf() const;

    void setShelf(unsigned short shelf);

    unsigned short getBook() const;

    void setBook(unsigned short book);

    unsigned long getSeed() const;

    void setSeed();

private:
    unsigned short hall;
    unsigned short floor;
    unsigned short room;
    unsigned short wall; //1-6 TODO add bounds
    unsigned short shelf; //1-7 TODO add bounds
    unsigned short book; //1-25 TODO add bounds
    unsigned long seed;
};


#endif //OBBLIGATO_Seeder_H
