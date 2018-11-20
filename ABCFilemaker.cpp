//
// Created by Rian on 11/20/2018.
//

#include "ABCFilemaker.hpp"
#include "CustomExceptions.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

const std::vector<std::pair<char, char>> &ABCFilemaker::getNotes() const {
    return notes;
}

void ABCFilemaker::setNotes(const std::vector<std::pair<char, char>> &notes) {
    ABCFilemaker::notes = notes;
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

ABCFilemaker::ABCFilemaker(const std::string &timeInputFilePath, const std::string &toneInputFilePath,
                           const std::string &outputFilePath) : timeInputFilePath(timeInputFilePath),
                                                                toneInputFilePath(toneInputFilePath),
                                                                outputFilePath(outputFilePath) {
    //Load times into char vector
    std::ifstream timeFile(timeInputFilePath, std::ios::binary);
    std::vector<char> timeFileContents((std::istreambuf_iterator<char>(timeFile)),std::istreambuf_iterator<char>());
    //Load tones into char vector
    std::ifstream toneFile(toneInputFilePath, std::ios::binary);
    std::vector<char> toneFileContents((std::istreambuf_iterator<char>(toneFile)),std::istreambuf_iterator<char>());
    //Verify the vectors are the same length
    if (timeFileContents.size() != toneFileContents.size()){
        throw CustomException::TempFileLengthMismatch();
        //throw CustomException::FileLengthMismatch(timeInputFilePath, toneInputFilePath);
    }
    //Merge vectors into notes vector
    std::vector<std::pair<char, char>> merge;
    merge.reserve(timeFileContents.size());
    std::transform(timeFileContents.begin(), timeFileContents.end(), toneFileContents.begin(), std::back_inserter(merge),
                   [](char a, char b) { return std::make_pair(a, b); });
    ABCFilemaker::setNotes(merge);
}

ABCFilemaker::~ABCFilemaker() = default;


