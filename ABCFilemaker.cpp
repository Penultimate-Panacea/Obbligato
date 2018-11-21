//
// Created by Rian on 11/20/2018.
//

#include "ABCFilemaker.hpp"
#include "EquivalenceTables.hpp"
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

void ABCFilemaker::setToneInputFilePath(const std::string &toneInputFilePath) {
    ABCFilemaker::toneInputFilePath = toneInputFilePath;
}

const std::string &ABCFilemaker::getSeedLocation() const {
    return seedLocation;
}

void ABCFilemaker::setSeedLocation(const std::string &seedLocation) {
    ABCFilemaker::seedLocation = seedLocation;
}


ABCFilemaker::ABCFilemaker(const std::string &timeInputFilePath, const std::string &toneInputFilePath)
                                                                : timeInputFilePath(timeInputFilePath),
                                                                toneInputFilePath(toneInputFilePath){
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
    merge.reserve(toneFileContents.size());
    std::transform(toneFileContents.begin(), toneFileContents.end(), timeFileContents.begin(), std::back_inserter(merge),
                   [](char a, char b) { return std::make_pair(a, b); });
    ABCFilemaker::setNotes(merge);
}

ABCFilemaker::~ABCFilemaker() = default;

void ABCFilemaker::makeABCfile() {};

std::string ABCFilemaker::noteTranslate(std::pair<char, char> note) {
    ////////////////////////////////////////////////////////////////////////////////
    /// Translates the raw output of the RCLG to an ABC Note
    ///
    /// \param[in] a pair of chars representing the codes for a tone and a time. Tone should be first.
    /// \param[out] String in the format of a ABC note
    ///

    std::string abcNote;
    char tone = note.first;
    char time = note.second;
    auto it = std::find(Equivalence::b89CharSetVec.begin(), Equivalence::b89CharSetVec.end(), tone);
    char index = static_cast<char> (std::distance(Equivalence::b89CharSetVec.begin(), it));
    abcNote = Equivalence::abcToneStringSetVec.at(index);
    abcNote + Equivalence::abcTimeStringSetVec.at(time);
    return abcNote;
};


