//
// Created by Rian on 11/20/2018.
//

#include "ABCFilemaker.hpp"
#include "CustomExceptions.hpp"
#include <cmath>
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

ABCFilemaker::ABCFilemaker(const std::string &timeInputFilePath, const std::string &toneInputFilePath,
                           const std::string &seedLocation) : timeInputFilePath(timeInputFilePath),
                                                              toneInputFilePath(toneInputFilePath),
                                                              seedLocation(seedLocation) {
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
    ABCFilemaker::setNotes(merge);}

ABCFilemaker::~ABCFilemaker() = default;



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
    const std::vector<char> b89CharSetVec {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                           'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                           'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                                           'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '<',
                                           '#', '$', '%', '&', '>', '(', ')', '*', '+', ',', '-', '.', '/', '[', '?', ']',
                                           '^', '_', '`', '{', '|', '}', '~', '@', '\\'};
    const std::vector<std::string> abcTimeStringSetVec =  {"/64", "/32", "/16", "/8", "/4", "/3", "2", "", "2", "3"};
    const std::vector<std::string> abcToneStringSetVec = {"A,,,,", "^A,,,,","B,,,,", "C,,,,","^C,,,,","D,,,","^D,,,","E,,,",
                                                          "F,,,", "^F,,,", "G,,,", "^G,,,", "A,,,", "^A,,,", "B,,,", "C,,,",
                                                          "^C,,,", "D,,", "^D,,", "E,,", "F,,", "^F,,", "G,,", "^G,,", "A,,",
                                                          "^A,,", "B,,", "C,,", "^C,,", "D,", "^D,", "E,", "F,", "^F,", "G",
                                                          "^G", "A", "^A", "B", "C", "^C", "D", "^D", "E", "F", "^F", "G",
                                                          "^G", "A", "^A", "B", "c", "^c", "d", "^d", "e", "f", "^f", "g",
                                                          "^g", "a", "^a", "b", "c'", "^c'", "d'", "^d'", "e'", "f'", "^f'",
                                                          "g'", "^g'","a'", "^a'", "b'", "c''", "^c''", "d''", "^d''", "e''",
                                                          "f''", "^f''", "g''", "^g''", "a''", "^a''", "b''", "c'''", "z"};
    auto it = std::find(b89CharSetVec.begin(), b89CharSetVec.end(), tone);
    long index = (std::distance(b89CharSetVec.begin(), it));
    abcNote = abcToneStringSetVec.at(static_cast<unsigned long>(index));
    abcNote + abcTimeStringSetVec.at(static_cast<unsigned long>(time));
    return abcNote;
};

void ABCFilemaker::makeABCfile() {
    std::cout << noteTranslate(notes[2]);
    std::string header = abcFileHeader();
    std::string music = abcMusic();
    std::string closer = abcCloser();
    std::ofstream file("output2.abc");
    file << header;
    file << music;
    file << closer;


};

std::string ABCFilemaker::abcFileHeader() {
    std::string header;
    header.append("X: 1 \n");
    header.append("T: ");
    header.append(seedLocation + "\n");
    header.append("C: " + composer  + "\n");
    header.append("L: " + defaultNoteLength  + "\n");
    header.append("M: " + timeSig + "\n");
    header.append("R: " + tuneType  + "\n");
    header.append("K: " + key  + "\n");
    return header;
}

std::string ABCFilemaker::abcMusic(){
    std::string music;
    unsigned long numberOfABCChars = notes.size() + static_cast<unsigned long>(std::ceil(notes.size()/measureLength));
    for (unsigned long i = 0; i < numberOfABCChars-1; i++) {
        std::string note = noteTranslate(notes[i]);
        music.append(note);
        if(i % measureLength == measureLength-1){music.append("|");}
    }
    return music;
};

std::string ABCFilemaker::abcCloser(){
    std::string closer;
    closer.append("]");
    return closer;
}