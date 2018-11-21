//
// Created by Rian on 11/20/2018.
//


#ifndef OBBLIGATO_EQUIVALENCETABLES_HPP
#define OBBLIGATO_EQUIVALENCETABLES_HPP

#include <vector>
#include <string>

namespace Equivalence{
    static const char b89CharSet[89] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                                        'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                        'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                                        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '<',
                                        '#', '$', '%', '&', '>', '(', ')', '*', '+', ',', '-', '.', '/', '[', '?', ']',
                                        '^', '_', '`', '{', '|', '}', '~', '@', '\\'};
    static const std::vector<char> b89CharSetVec (b89CharSet, b89CharSet+ sizeof(b89CharSet) / sizeof(b89CharSet[0]) );
    static const std::string abcToneStringSet[89] = {"A,,,,", "^A,,,,","B,,,,", "C,,,,","^C,,,,","D,,,","^D,,,","E,,,",
                                                   "F,,,", "^F,,,", "G,,,", "^G,,,", "A,,,", "^A,,,", "B,,,", "C,,,",
                                                   "^C,,,", "D,,", "^D,,", "E,,", "F,,", "^F,,", "G,,", "^G,,", "A,,",
                                                   "^A,,", "B,,", "C,,", "^C,,", "D,", "^D,", "E,", "F,", "^F,", "G",
                                                   "^G", "A", "^A", "B", "C", "^C", "D", "^D", "E", "F", "^F", "G",
                                                   "^G", "A", "^A", "B", "c", "^c", "d", "^d", "e", "f", "^f", "g",
                                                   "^g", "a", "^a", "b", "c'", "^c'", "d'", "^d'", "e'", "f'", "^f'",
                                                   "g'", "^g'","a'", "^a'", "b'", "c''", "^c''", "d''", "^d''", "e''",
                                                   "f''", "^f''", "g''", "^g''", "a''", "^a''", "b''", "c'''", "z"};
    static const std::vector<char> abcToneStringSetVec (abcToneStringSet, abcToneStringSet+ sizeof(abcToneStringSet)/
                                                                                      sizeof(abcToneStringSet[0]) );
    static const std::string abcTimeStringSet[10] = {"/64", "/32", "/16", "/8", "/4", "/3", "2", "", "2", "3"};
    static const std::vector<char> abcTimeStringSetVec (abcTimeStringSet, abcTimeStringSet+ sizeof(abcTimeStringSet)/
                                                                                      sizeof(abcTimeStringSet[0]));

}
#endif //OBBLIGATO_EQUIVALENCETABLES_HPP
