//
// Created by Rian on 11/20/2018.
//

#ifndef OBBLIGATO_ABCFILEMAKER_HPP
#define OBBLIGATO_ABCFILEMAKER_HPP

#include <vector>
#include <string>
class ABCFilemaker {
private:
    std::vector<char>times;
    std::vector<char>tones;
    std::string timeInputFilePath;
    std::string toneInputFilePath;
    std::string outputFilePath;
    std::string seedLocation; //T:
    const char key = 'C'; //K:
    const char timeSig = 'C'; //M:
    const std::string defaultNoteLength = "1/4"; //L:
    const std::string tuneType = "Obbligato"; //R:
    const char measureLength = 4;
public:
    const char getKey() const;

    const char getTimeSig() const;

    const std::string &getDefaultNoteLength() const;

    const std::string &getTuneType() const;

    const char getMeasureLength() const;

public:
    const std::vector<char> &getTimes() const;

    void setTimes(const std::vector<char> &times);

    const std::vector<char> &getTones() const;

    void setTones(const std::vector<char> &tones);

    const std::string &getTimeInputFilePath() const;

    void setTimeInputFilePath(const std::string &timeInputFilePath);

    const std::string &getToneInputFilePath() const;

    void setToneInputFilePath(const std::string &toneInputFilePath);

    const std::string &getOutputFilePath() const;

    void setOutputFilePath(const std::string &outputFilePath);

    const std::string &getSeedLocation() const;

    void setSeedLocation(const std::string &seedLocation);
};


#endif //OBBLIGATO_ABCFILEMAKER_HPP
