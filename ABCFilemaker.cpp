//
// Created by Rian on 11/20/2018.
//

#include "ABCFilemaker.hpp"

const std::vector<char> &ABCFilemaker::getTimes() const {
    return times;
}

void ABCFilemaker::setTimes(const std::vector<char> &times) {
    ABCFilemaker::times = times;
}

const std::vector<char> &ABCFilemaker::getTones() const {
    return tones;
}

void ABCFilemaker::setTones(const std::vector<char> &tones) {
    ABCFilemaker::tones = tones;
}

const std::string &ABCFilemaker::getTimeInputFilePath() const {
    return timeInputFilePath;
}

void ABCFilemaker::setTimeInputFilePath(const std::string &timeInputFilePath) {
    ABCFilemaker::timeInputFilePath = timeInputFilePath;
}

const std::string &ABCFilemaker::getToneInputFilePath() const {
    return toneInputFilePath;
}

void ABCFilemaker::setToneInputFilePath(const std::string &toneInputFilePath) {
    ABCFilemaker::toneInputFilePath = toneInputFilePath;
}

const std::string &ABCFilemaker::getOutputFilePath() const {
    return outputFilePath;
}

void ABCFilemaker::setOutputFilePath(const std::string &outputFilePath) {
    ABCFilemaker::outputFilePath = outputFilePath;
}

const std::string &ABCFilemaker::getSeedLocation() const {
    return seedLocation;
}

void ABCFilemaker::setSeedLocation(const std::string &seedLocation) {
    ABCFilemaker::seedLocation = seedLocation;
}

const char ABCFilemaker::getKey() const {
    return key;
}

const char ABCFilemaker::getTimeSig() const {
    return timeSig;
}

const std::string &ABCFilemaker::getDefaultNoteLength() const {
    return defaultNoteLength;
}

const std::string &ABCFilemaker::getTuneType() const {
    return tuneType;
}

const char ABCFilemaker::getMeasureLength() const {
    return measureLength;
}
