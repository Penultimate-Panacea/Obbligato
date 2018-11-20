//
// Created by Rian on 11/20/2018.
//

#ifndef OBBLIGATO_CUSTOMEXCEPTIONS_HPP
#define OBBLIGATO_CUSTOMEXCEPTIONS_HPP

#include <iostream>
#include <exception>

namespace CustomException {

    struct TempFileLengthMismatch: public std::exception
    {
        const char * what () const throw ()
        {
            return "Input files are not of the same size";
        }
    };
    /*TODO
    class FileLengthMismatch: public std::exception {
        const char* file1;
        const char* file2;
        int line;
        const char* func;
        const char* info;

    public:
        FileLengthMismatch(const char* msg, const char* file_, int line_, const char* func_, const char* info_ = "") : std::exception(msg),
                                                                                                                file1 (file_),
                                                                                                                                                                                                                              line (line_),
                                                                                                                func (func_),
                                                                                                                info (info_)
        {
        }

        const char* get_file() const { return file; }
        int get_line() const { return line; }
        const char* get_func() const { return func; }
        const char* get_info() const { return info; }

    };*/
}

#endif //OBBLIGATO_CUSTOMEXCEPTIONS_HPP
