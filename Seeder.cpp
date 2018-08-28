//
// Created by Penultimate-Panacea on 8/27/2018.
//

#include "Seeder.h"
#include <string>
unsigned long concatenate(unsigned long i, unsigned long j) { //SOURCE : https://stackoverflow.com/a/37536245
    std::string result = "";
    for (; i <= j; ++i)
        result += std::to_string(i);
    return std::stoi(result);
}
unsigned short Seeder::getHall() const {
    return hall;
}

void Seeder::setHall(unsigned short hall) {
    Seeder::hall = hall;
}

unsigned short Seeder::getFloor() const {
    return floor;
}

void Seeder::setFloor(unsigned short floor) {
    Seeder::floor = floor;
}

unsigned short Seeder::getRoom() const {
    return room;
}

void Seeder::setRoom(unsigned short room) {
    Seeder::room = room;
}

unsigned char Seeder::getWall() const {
    return wall;
}

void Seeder::setWall(unsigned char wall) {
    Seeder::wall = wall;
}

unsigned char Seeder::getShelf() const {
    return shelf;
}

void Seeder::setShelf(unsigned char shelf) {
    Seeder::shelf = shelf;
}

unsigned char Seeder::getBook() const {
    return book;
}

void Seeder::setBook(unsigned char book) {
    Seeder::book = book;
}

Seeder::Seeder(unsigned short hall, unsigned short floor, unsigned short room, unsigned char wall, unsigned char shelf,
           unsigned char book) : hall(hall), floor(floor), room(room), wall(wall), shelf(shelf), book(book) {}

Seeder::~Seeder() = default;

std::ostream &operator<<(std::ostream &os, const Seeder &Seeder) {
    os << "h-" << Seeder.hall << "-f-" << Seeder.floor << "-r-" << Seeder.room << "-w-" << Seeder.wall << "-s-" << Seeder.shelf <<
    "-b-" << Seeder.book;
    return os;
}

unsigned int Seeder::getSeed() const {
    return seed;
}

void Seeder::setSeed() {
    unsigned long tempSeed;
    unsigned long finalSeed;
    tempSeed = concatenate(this->hall, this->floor);
    tempSeed = concatenate(tempSeed, this->room);
    tempSeed = concatenate(tempSeed, this->wall);
    tempSeed = concatenate(tempSeed, this->shelf);
    tempSeed = concatenate(tempSeed,this->book);
    finalSeed = tempSeed;
    Seeder::seed = finalSeed;
}



