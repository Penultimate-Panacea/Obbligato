//
// Created by Rian on 11/20/2018.
//

#ifndef OBBLIGATO_ABCFILEMAKER_HPP
#define OBBLIGATO_ABCFILEMAKER_HPP

#include <vector>
#include <string>

class ABCFilemaker {
    /** \class ABCFilemaker
     * Creates a .abc file from the output files from main.
     */

private:
    std::vector<std::pair<char, char>> notes; //Joined vector of tones and times as <tone, time>
    std::string timeInputFilePath;
    std::string toneInputFilePath;
    std::string seedLocation; //T:
    char buffer;
    const char key = 'C'; //K:
    const char timeSig = 'C'; //
    const std::string defaultNoteLength = "1"; //L:
    const std::string tuneType = "Obbligato"; //R:
    const char measureLength = 4;

public:
    //Setters & Getters
    const std::vector<std::pair<char, char>> &getNotes() const;

    void setNotes(const std::vector<std::pair<char, char>> &notes);

    const std::string &getTimeInputFilePath() const;

    void setTimeInputFilePath(const std::string &timeInputFilePath);

    void setToneInputFilePath(const std::string &toneInputFilePath);

    void setOutputFilePath(const std::string &outputFilePath);

    const std::string &getSeedLocation() const;

    void setSeedLocation(const std::string &seedLocation);

    //Constructors & Destructors
    ABCFilemaker(const std::string &timeInputFilePath, const std::string &toneInputFilePath);

    virtual ~ABCFilemaker();

    //Core Methods
    void makeABCfile();
    std::string noteTranslate(std::pair<char, char>);

};


#endif //OBBLIGATO_ABCFILEMAKER_HPP
