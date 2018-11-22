//
// Created by Rian on 11/22/2018.
//
/*
#ifndef OBBLIGATO_ETABLE_HPP
#define OBBLIGATO_ETABLE_HPP


#include <string>
#include <vector>

class ETable {
public:
    ETable();

private:
    static constexpr char b89CharSet[89] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                                 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '<',
                                 '#', '$', '%', '&', '>', '(', ')', '*', '+', ',', '-', '.', '/', '[', '?', ']',
                                 '^', '_', '`', '{', '|', '}', '~', '@', '\\'};

    static constexpr std::string abcTimeStringSet[10] = {"/64", "/32", "/16", "/8", "/4", "/3", "2", "", "2", "3"};
    const std::vector<char> b89CharSetVec {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                     'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                     'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '<',
                                     '#', '$', '%', '&', '>', '(', ')', '*', '+', ',', '-', '.', '/', '[', '?', ']',
                                     '^', '_', '`', '{', '|', '}', '~', '@', '\\'};
    const std::vector<std::string> abcToneStringSetVec = {"A,,,,", "^A,,,,","B,,,,", "C,,,,","^C,,,,","D,,,","^D,,,","E,,,",
                                                          "F,,,", "^F,,,", "G,,,", "^G,,,", "A,,,", "^A,,,", "B,,,", "C,,,",
                                                          "^C,,,", "D,,", "^D,,", "E,,", "F,,", "^F,,", "G,,", "^G,,", "A,,",
                                                          "^A,,", "B,,", "C,,", "^C,,", "D,", "^D,", "E,", "F,", "^F,", "G",
                                                          "^G", "A", "^A", "B", "C", "^C", "D", "^D", "E", "F", "^F", "G",
                                                          "^G", "A", "^A", "B", "c", "^c", "d", "^d", "e", "f", "^f", "g",
                                                          "^g", "a", "^a", "b", "c'", "^c'", "d'", "^d'", "e'", "f'", "^f'",
                                                          "g'", "^g'","a'", "^a'", "b'", "c''", "^c''", "d''", "^d''", "e''",
                                                          "f''", "^f''", "g''", "^g''", "a''", "^a''", "b''", "c'''", "z"};
    const std::vector<std::string> abcTimeStringSetVec =  {"/64", "/32", "/16", "/8", "/4", "/3", "2", "", "2", "3"};
public:
    static const char *getB89CharSet();

    const std::string *getAbcToneStringSet() const;

    const std::string *getAbcTimeStringSet() const;

    const std::vector<char> &getB89CharSetVec() const;

    const std::vector<std::string> &getAbcToneStringSetVec() const;

    const std::vector<std::string> &getAbcTimeStringSetVec() const;

    virtual ~ETable();

};


#endif //OBBLIGATO_ETABLE_HPP

*/