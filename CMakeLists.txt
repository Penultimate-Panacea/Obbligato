cmake_minimum_required(VERSION 3.9)
project(Obbligato)

set(CMAKE_CXX_STANDARD 11)

add_executable(Obbligato main.cpp Mode.cpp Mode.h ObbligatoExeceptions.h Note.cpp Note.h Chord.cpp Chord.h Pitch.cpp Pitch.h Tone.cpp Tone.h Encoder.cpp Encoder.h BaseEightyEight.cpp BaseEightyEight.h)